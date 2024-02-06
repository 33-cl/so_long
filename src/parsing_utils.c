/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeferre <maeferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:39:04 by maeferre          #+#    #+#             */
/*   Updated: 2024/02/05 23:12:10 by maeferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

/*
	Extracts and parses the map
																			"1111"
	open("../map.ber", O_RDONLY)	=>		"1111\n1001\n1111"		=> 		"1001"
																			"1111"
*/																

char	**extract_n_parse(char **argv)
{
	char 	**map;
	char	**old_map;
	bool	error;
	ssize_t	i;

	error = 0;
	map = extract_map(argv[1]);
	old_map = extract_map(argv[1]);
	if (!map || !old_map)
	{
		printf("Error 1");
		return (NULL);
	}
	if (!parsing(map) || !check_invalid_extension(argv[1]))
	{
		printf("Error");
		error = 1;
	}
	i = -1;
	while (i++, map[i])
		free(map[i]);
	free(map);
	if (error == 1)
		return (NULL);
	return (old_map);
}

char	**extract_map(char *argv)
{
	int		ber_file;
	char	*map1;
	char	**map2;
	char	*line;

	if (!argv)
		return (NULL);
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

char	**free_and_null(char *map1, char *line)
{
	free(map1);
	free(line);
	return (NULL);
}

bool	multiple_new_lines(char *map)
{
	ssize_t	i;

	i = -1;
	while (i++, map[i])
		if (map[i] == '\n' && map[i + 1] && map[i + 1] == '\n')
			return (false);
	return (true);
}

bool	check_invalid_extension(char *file)
{
	size_t	i;

	if (!file)
		return (false);
	i = ft_strlen(file);
	return (i >= 5 && file[i - 4] == '.' && file[i - 3] == 'b' && file[i - 2] == 'e' && file[i - 1] == 'r');
}