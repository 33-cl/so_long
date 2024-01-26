/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeferre <maeferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 11:47:10 by maeferre          #+#    #+#             */
/*   Updated: 2024/01/23 18:53:33 by maeferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"
#include <stdbool.h>

static void	get_player_position(char **map, int *player_X, int *player_Y);

static bool	check_close_rectangle(char **map);
static bool	check_map_content(char **map);
static void	map_fill(char **map, int x, int y);
static bool	check_empty_map(char **map);


#include <stdio.h>
bool	parsing(char **map)
{
	char	**filled_map;
	int		player_X;
	int		player_Y;
	size_t	i;

	if (!check_close_rectangle(map))
		return (false);
	if (!check_map_content(map))
		return (false);
	get_player_position(map, &player_X, &player_Y);
	map_fill(map, player_X, player_Y);
	if (!check_empty_map(map))
		return (false);
	return (true);
}

/*
	Verify the map is a rectangle and the border is made of '1' chars
	
			11111		11111		11111
	ex :	10001 = 1   10000 = 0   100011 = 0
			11111		11111		11111
*/

static bool	check_close_rectangle(char **map)
{
	ssize_t		i;
	ssize_t		j;
	
	i = -1;
	j = -1;
	while (j++, map[0][j])
		if (map[0][j] != '1')
			return (false);
	while (i++, map[i + 1] != NULL)
		if (j != ft_strlen(map[i]) || map[i][0] != '1' || map[i][j - 1] != '1')
			return (false);
	j = -1;
	while (j++, map[i][j])
		if (map[i][j] != '1')
			return (false);
	return (true);
}

/*	
	Verifies the map contains :
		~ 1 entrance
		~ 1 exit
		~ 1 or more collectible item
*/

static bool	check_map_content(char **map)
{
	ssize_t		i;
	size_t		j;
	size_t		entrance;
	size_t		exit;
	size_t		item;

	i = -1;
	entrance = 0;
	exit = 0;
	item = 0;
	while (i++, map[i])
	{
		j = -1;
		while (j++, map[i][j])
		{
			if (map[i][j] == 'P')
				entrance++;
			else if (map[i][j] == 'E')
				exit++;
			else if (map[i][j] == 'C')
				item++;
		}
	}
	return (entrance == 1 && exit == 1 && item >= 1);
}


/*
	Assigns to player_X and player_Y the value of the player's position
*/

static void	get_player_position(char **map, int *player_X, int *player_Y)
{
	ssize_t	i;
	ssize_t	j;
	
	i = -1;
	while (i++, map[i])
	{
		j = -1;
		while (j++, map[i][j])
			if (map[i][j] == 'P')
			{
				*player_X = j;
				*player_Y = i;
				return ;
			}	
	}
}

/*
	Recursive function that travels every elements of the map (excepts walls)
	and replaces these elements by 'X' characters
	Starts at 'P'

			111111111				111111111
			1 P   111				1XXXXX111
	ex :	1111    1		==>		1111XXXX1
			1  1    1				1  1XXXX1
			111111111				111111111
*/

static void	map_fill(char **map, int x, int y)
{
	map[y][x] = 'X';
	if (map[y][x + 1] == '0' || map[y][x + 1] == 'E' || map[y][x + 1] == 'C')
		map_fill(map, x + 1, y);
	if (map[y][x - 1] == '0' || map[y][x - 1] == 'E' || map[y][x - 1] == 'C')
		map_fill(map, x - 1, y);
	if (map[y - 1][x] == '0' || map[y - 1][x] == 'E' || map[y - 1][x] == 'C')
		map_fill(map, x, y - 1);
	if (map[y + 1][x] == '0' || map[y + 1][x] == 'E' || map[y + 1][x] == 'C')
		map_fill(map, x, y + 1);	
}

/*	
	Verifies the map is empty
*/

static bool	check_empty_map(char **map)
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
