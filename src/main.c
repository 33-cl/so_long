/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeferre <maeferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:10:03 by maeferre          #+#    #+#             */
/*   Updated: 2024/01/17 22:31:49 by maeferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static char		**free_and_null(char *map1, char *line);
static bool		check_invalid_extension(char *file);
static bool		multiple_new_lines(char *map);
static char		**extract_map(char *argv);


#include <stdio.h>
int	main(int argc, char **argv)
{
	char 	**map;
	ssize_t	i;

	// Creates map
	map = extract_map(argv[1]);
	if (!map)
	{
		printf("Error");
		return 0;
	}
	if (!parsing(map) || !check_invalid_extension(argv[1]))
		printf("Error");
	else
	{
		// Displays map
		i = 0;
		while (map[i])
		{
			printf("line = %s\n", map[i]);
			i++;
		}
	}
	
	// Frees map
	i = -1;
	while (i++, map[i])
		free(map[i]);
	
	free(map);

	return (0);
}

/*
	Extracts the map
																			"1111"
	open("../map.ber", O_RDONLY)	=>		"1111\n1001\n1111"		=> 		"1001"
																			"1111"
*/																

static char	**extract_map(char *argv)
{
	int		ber_file;	// STEP 1
	char	*map1;		// STEP 2
	char	**map2;		// STEP 3
	char	*line;

	ber_file = open(argv, O_RDONLY);
	if (!ber_file)
		return (NULL);
	map1 = ft_strdup("");
	line = get_next_line(ber_file);
	if (!map1 || !line)
		return (free_and_null(map1, line));
	while (line)
	{
		map1 = ft_strjoin(map1, line);
		free(line);
		line = get_next_line(ber_file);
		if (!map1 || !multiple_new_lines(map1))
			return (free_and_null(map1, line));
	}
	map2 = ft_split(map1, '\n');
	free(map1);
	free(line);
	return (map2);
}

static char	**free_and_null(char *map1, char *line)
{
	free(map1);
	free(line);
	return (NULL);
}

static bool	multiple_new_lines(char *map)
{
	ssize_t	i;

	i = -1;
	while (i++, map[i])
		if (map[i] == '\n' && map[i + 1] && map[i + 1] == '\n')
			return (false);
	return (true);
}

static bool	check_invalid_extension(char *file)
{
	size_t	i;

	i = ft_strlen(file);
	return (i >= 5 && file[i - 3] == '.' && file[i - 2] == 'b' && file[i - 1] == 'e' && file[i - 0] == 'r');
}
