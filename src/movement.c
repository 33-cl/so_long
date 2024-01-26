/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeferre <maeferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 19:11:44 by maeferre          #+#    #+#             */
/*   Updated: 2024/01/26 19:30:57 by maeferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"
#include "../minilibx-linux/mlx.h"
#include <stdio.h>


int		go_up(t_game *game, char player)
{
	if (player == 'P' && game->map[game->player_y - 1][game->player_x] == '0')
	{
		printf("Knight : en haut\n");
		game->map[game->player_y][game->player_x] = '0';
		game->map[game->player_y - 1][game->player_x] = 'P';
	}
	else if (player == 'E' && game->map[game->exit_y - 1][game->exit_x] == '0')
	{
		printf("Ghost : en haut\n");
		game->map[game->exit_y][game->exit_x] = '0';
		game->map[game->exit_y - 1][game->exit_x] = 'E';
	}
	if (!draw_map(game, -1, -1))
		return (-1);
	return (0);
}

int		go_down(t_game *game, char player)
{
	if (player == 'P' && game->map[game->player_y + 1][game->player_x] == '0')
	{
		printf("Knight : en bas\n");
		game->map[game->player_y][game->player_x] = '0';
		game->map[game->player_y + 1][game->player_x] = 'P';
	}
	else if (player == 'E' && game->map[game->exit_y + 1][game->exit_x] == '0')
	{
		printf("Ghost : en bas\n");
		game->map[game->exit_y][game->exit_x] = '0';
		game->map[game->exit_y + 1][game->exit_x] = 'E';
	}
	if (!draw_map(game, -1, -1))
		return (-1);
	return (0);
}

int		go_left(t_game *game, char player)
{
	if (player == 'P' && game->map[game->player_y][game->player_x - 1] == '0')
	{
		printf("Knight : a gauche\n");
		game->map[game->player_y][game->player_x] = '0';
		game->map[game->player_y][game->player_x - 1] = 'P';
	}
	else if (player == 'E' && game->map[game->exit_y][game->exit_x - 1] == '0')
	{
		printf("Ghost : a gauche\n");
		game->map[game->exit_y][game->exit_x] = '0';
		game->map[game->exit_y][game->exit_x - 1] = 'E';
	}
	if (!draw_map(game, -1, -1))
		return (-1);
	return (0);
}

int		go_right(t_game *game, char player)
{
	if (player == 'P' && game->map[game->player_y][game->player_x + 1] == '0')
	{
		printf("Knight : droite\n");
		game->map[game->player_y][game->player_x] = '0';
		game->map[game->player_y][game->player_x + 1] = 'P';
	}
	else if (player == 'E' && game->map[game->exit_y][game->exit_x + 1] == '0')
	{
		printf("Ghost : droite\n");
		game->map[game->exit_y][game->exit_x] = '0';
		game->map[game->exit_y][game->exit_x + 1] = 'E';
	}
	if (!draw_map(game, -1, -1))
		return (-1);
	return (0);
}
