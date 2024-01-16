/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeferre <maeferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:10:03 by maeferre          #+#    #+#             */
/*   Updated: 2024/01/16 19:43:51 by maeferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static char		**free_and_null(char *map1, char *line);
static char		**extract_map(char *argv);

#include <stdio.h>
int	main(int argc, char **argv)
{
	/*void	*mlx_ptr; // Pointer to mlx structure
	void	*win_ptr; // Pointer to the window

	int		width;
	int		height;
	int		i = 0;

	width = 800;
	height = 600; 

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, width, height, "so_long");

	mlx_hook(win_ptr, 2, 1L<<0, mlx_destroy_window, mlx_ptr); // Closing window management

	mlx_loop(mlx_ptr); // Maintain display

	while (i < 500)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, 100, i, RGB(0, 0, 255));
		i++;
	}*/

	char 	**map;
	ssize_t	i;

	// Creates map
	map = extract_map(argv[1]);
	if (!map)
		return 0;
	
	if (!parsing(map))
		printf("Parsing error");
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
		if (!map1)
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
