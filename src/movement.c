/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeferre <maeferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 19:11:44 by maeferre          #+#    #+#             */
/*   Updated: 2024/02/14 22:44:33 by maeferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../minilibx-linux/mlx.h"

static bool	write_infos(t_game *game)
{
	if (!ft_putstr("Steps : "))
		return (false);
	if (!ft_putnbr(game->nb_steps))
		return (false);
	if (!ft_putstr(" || "))
		return (false);
	if (!ft_putnbr(game->items_collected))
		return (false);
	if (!ft_putstr("/"))
		return (false);
	if (!ft_putnbr(game->nb_items))
		return (false);
	if (!ft_putstr("\n"))
		return (false);
	return (true);
}

bool	go_up(t_game *game, char player)
{
	char	*up_tile;

	up_tile = &game->map[game->player_y - 1][game->player_x];
	if (*up_tile == 'E' && game->nb_items == game->items_collected
		&& player == 'P')
		mlx_loop_end(game->mlx);
	else if (*up_tile == 'C')
		game->items_collected++;
	if (player == 'P' && (*up_tile == '0' || *up_tile == 'C'))
	{
		game->nb_steps++;
		if (!write_infos(game))
			return (false);
		game->map[game->player_y][game->player_x] = '0';
		*up_tile = 'P';
	}
	else if (player == 'E' && game->map[game->exit_y - 1][game->exit_x] == '0')
	{
		game->map[game->exit_y][game->exit_x] = '0';
		game->map[game->exit_y - 1][game->exit_x] = 'E';
	}
	if (!draw_map(game, -1, -1))
		return (false);
	return (true);
}

bool	go_down(t_game *game, char player)
{
	char	*down_tile;

	down_tile = &game->map[game->player_y + 1][game->player_x];
	if (*down_tile == 'E' && game->nb_items == game->items_collected
		&& player == 'P')
		mlx_loop_end(game->mlx);
	if (*down_tile == 'C')
		game->items_collected++;
	if (player == 'P' && (*down_tile == '0' || *down_tile == 'C'))
	{
		game->nb_steps++;
		if (!write_infos(game))
			return (false);
		game->map[game->player_y][game->player_x] = '0';
		*down_tile = 'P';
	}
	else if (player == 'E' && game->map[game->exit_y + 1][game->exit_x] == '0')
	{
		game->map[game->exit_y][game->exit_x] = '0';
		game->map[game->exit_y + 1][game->exit_x] = 'E';
	}
	if (!draw_map(game, -1, -1))
		return (false);
	return (true);
}

bool	go_left(t_game *game, char player)
{
	char	*left_tile;

	left_tile = &game->map[game->player_y][game->player_x - 1];
	if (*left_tile == 'E' && game->nb_items == game->items_collected
		&& player == 'P')
		mlx_loop_end(game->mlx);
	if (*left_tile == 'C')
		game->items_collected++;
	if (player == 'P' && (*left_tile == 'C' || *left_tile == '0'))
	{
		game->nb_steps++;
		if (!write_infos(game))
			return (false);
		game->map[game->player_y][game->player_x] = '0';
		*left_tile = 'P';
	}
	else if (player == 'E' && game->map[game->exit_y][game->exit_x - 1] == '0')
	{
		game->map[game->exit_y][game->exit_x] = '0';
		game->map[game->exit_y][game->exit_x - 1] = 'E';
	}
	if (!draw_map(game, -1, -1))
		return (false);
	return (true);
}

bool	go_right(t_game *game, char player)
{
	char	*right_tile;

	right_tile = &game->map[game->player_y][game->player_x + 1];
	if (*right_tile == 'E' && game->nb_items == game->items_collected
		&& player == 'P')
		mlx_loop_end(game->mlx);
	if (*right_tile == 'C')
		game->items_collected++;
	if (player == 'P' && (*right_tile == '0' || *right_tile == 'C'))
	{
		game->nb_steps++;
		if (!write_infos(game))
			return (false);
		game->map[game->player_y][game->player_x] = '0';
		*right_tile = 'P';
	}
	else if (player == 'E' && game->map[game->exit_y][game->exit_x + 1] == '0')
	{
		game->map[game->exit_y][game->exit_x] = '0';
		game->map[game->exit_y][game->exit_x + 1] = 'E';
	}
	if (!draw_map(game, -1, -1))
		return (false);
	return (true);
}
