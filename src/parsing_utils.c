/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeferre <maeferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:39:04 by maeferre          #+#    #+#             */
/*   Updated: 2024/02/14 22:44:00 by maeferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	multiple_new_lines(char *map);
bool	check_invalid_extension(char *file);
void	free_map(char **map);

/*
	Extracts and parses the map
																	"1111"
	open("../map.ber", O_RDONLY)	=>	"1111\n1001\n1111"	=> 		"1001"
																	"1111"
*/																

char	**extract_n_parse(char **argv)
{
	char	**map;
	char	**old_map;
	bool	error;
	ssize_t	i;

	if (!argv)
		return (write(STDERR_FILENO, "Error\n", 6), NULL);
	error = 0;
	map = extract_map(argv[1]);
	old_map = extract_map(argv[1]);
	if (!check_invalid_extension(argv[1]))
		return (write(STDERR_FILENO, "Error\n", 6), NULL);
	if (!map || !old_map)
		return (write(STDERR_FILENO, "Error\n", 6), NULL);
	if (!parsing(map))
	{
		write(STDERR_FILENO, "Error\n", 6);
		error = 1;
	}
	free_map(map);
	if (error == 1)
		return (free_map(old_map), NULL);
	return (old_map);
}

char	**extract_map(char *argv)
{
	int		ber_file;
	char	*map1;
	char	**map2;
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
	return (i >= 5 && file[i - 4] == '.' && file[i - 3] == 'b'
		&& file[i - 2] == 'e' && file[i - 1] == 'r');
}

/*	
	Verifies the map is empty
*/

bool	check_empty_map(char **map)
{
	ssize_t		i;
	size_t		j;

	i = -1;
	while (i++, map[i])
	{
		j = -1;
		while (j++, map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'X')
				return (false);
		}
	}
	return (true);
}
