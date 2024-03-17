/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeferre <maeferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:33:58 by maeferre          #+#    #+#             */
/*   Updated: 2024/03/13 04:14:03 by maeferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	draw_tile(t_game *game, int nb_items, int i, int j)
{
	if (game->map[i][j] == '0')
		game->image = mlx_xpm_file_to_image(game->mlx, BACKGROUND,
				&game->img_width, &game->img_height);
	else if (game->map[i][j] == '1')
		game->image = mlx_xpm_file_to_image(game->mlx, WALL,
				&game->img_width, &game->img_height);
	else if (game->map[i][j] == 'E')
	{
		game->exit_y = i;
		game->exit_x = j;
		game->image = mlx_xpm_file_to_image(game->mlx, EXIT,
				&game->img_width, &game->img_height);
	}
	else if (nb_items++, game->map[i][j] == 'C')
		game->image = mlx_xpm_file_to_image(game->mlx, COLLECTIBLE,
				&game->img_width, &game->img_height);
	else if (game->map[i][j] == 'P')
	{
		game->player_y = i;
		game->player_x = j;
		game->image = mlx_xpm_file_to_image(game->mlx, PLAYER,
				&game->img_width, &game->img_height);
	}
	return (nb_items);
}

int	draw_move_exit(t_game *game, char movement)
{
	int	x;
	int	y;

	get_players_position(game);
	x = game->exit_x * TILE_SIZE;
	y = game->exit_y * TILE_SIZE;
	game->image = mlx_xpm_file_to_image(game->mlx, EXIT,
			&game->img_width, &game->img_height);
	mlx_put_image_to_window(game->mlx, game->win, game->image, x, y);
	if (!game->image)
		return (0);
	mlx_destroy_image(game->mlx, game->image);
	game->image = mlx_xpm_file_to_image(game->mlx, BACKGROUND,
			&game->img_width, &game->img_height);
	if (movement == 'W' && game->map[game->exit_y + 1][game->exit_x] == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->image, x, y + 50);
	if (movement == 'S' && game->map[game->exit_y - 1][game->exit_x] == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->image, x, y - 50);
	if (movement == 'A' && game->map[game->exit_y][game->exit_x + 1] == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->image, x + 50, y);
	if (movement == 'D' && game->map[game->exit_y][game->exit_x - 1] == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->image, x - 50, y);
	if (!game->image)
		return (0);
	return (mlx_destroy_image(game->mlx, game->image), 1);
}

int	draw_move_player(t_game *game, char movement)
{
	int	x;
	int	y;

	get_players_position(game);
	x = game->player_x * TILE_SIZE;
	y = game->player_y * TILE_SIZE;
	game->image = mlx_xpm_file_to_image(game->mlx, PLAYER,
			&game->img_width, &game->img_height);
	mlx_put_image_to_window(game->mlx, game->win, game->image, x, y);
	if (!game->image)
		return (0);
	mlx_destroy_image(game->mlx, game->image);
	game->image = mlx_xpm_file_to_image(game->mlx, BACKGROUND,
			&game->img_width, &game->img_height);
	if (movement == 'W' && game->map[game->player_y + 1][game->player_x] == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->image, x, y + 50);
	if (movement == 'S' && game->map[game->player_y - 1][game->player_x] == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->image, x, y - 50);
	if (movement == 'A' && game->map[game->player_y][game->player_x + 1] == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->image, x + 50, y);
	if (movement == 'D' && game->map[game->player_y][game->player_x - 1] == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->image, x - 50, y);
	if (!game->image)
		return (0);
	return (mlx_destroy_image(game->mlx, game->image), 1);
}

int	draw_map(t_game *game, int i, int j)
{
	int		x;
	int		y;
	int		nb_items;

	nb_items = -1;
	i = -1;
	y = 0;
	while (i++, game->map[i])
	{
		j = -1;
		x = 0;
		while (j++, game->map[i][j])
		{
			nb_items = draw_tile(game, nb_items, i, j);
			if (!game->image)
				return (write(2, "fail\n", 5), -1);
			mlx_put_image_to_window(game->mlx, game->win, game->image, x, y);
			mlx_destroy_image(game->mlx, game->image);
			x += TILE_SIZE;
		}
		y += TILE_SIZE;
	}
	return (nb_items);
}
