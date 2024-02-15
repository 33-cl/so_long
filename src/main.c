/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeferre <maeferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:10:03 by maeferre          #+#    #+#             */
/*   Updated: 2024/02/15 18:24:41 by maeferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../minilibx-linux/mlx.h"
#include <X11/X.h>
#include <X11/keysym.h>

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (write(STDERR_FILENO, "Error\n", 6));
	game.map = extract_n_parse(argv);
	if (!game.map)
		return (0);
	game.mlx = mlx_init();
	if (!game.mlx)
		return (free_game(&game), 0);
	game.map_height = ft_strlen2d(game.map) * TILE_SIZE;
	game.map_width = ft_strlen(game.map[0]) * TILE_SIZE;
	game.window = mlx_new_window(game.mlx, game.map_width, game.map_height, N);
	if (!game.window)
		return (free_game(&game), 0);
	game.items_collected = 0;
	game.nb_items = draw_map(&game, -1, -1);
	if (game.nb_items == -1)
		return (free_game(&game), 0);
	game.nb_steps = 0;
	mlx_hook(game.window, 2, 1L << 0, &key_pressed, &game);
	mlx_loop(game.mlx);
	free_game(&game);
	return (0);
}

/*
	----------------------------------
	----------------------------------
*/

int	key_pressed(int keycode, t_game *game)
{
	int	error;

	error = 0;
	if (keycode == XK_Escape)
	{
		mlx_loop_end(game->mlx);
		return (write(1, "STOP\n", 5));
	}
	if (keycode == XK_w)
		error = go_up(game, 'P');
	if (keycode == XK_a)
		error = go_left(game, 'P');
	if (keycode == XK_s)
		error = go_down(game, 'P');
	if (keycode == XK_d)
		error = go_right(game, 'P');
	if (keycode == KEY_UP)
		error = go_up(game, 'E');
	if (keycode == KEY_LEFT)
		error = go_left(game, 'E');
	if (keycode == KEY_DOWN)
		error = go_down(game, 'E');
	if (keycode == KEY_RIGHT)
		error = go_right(game, 'E');
	return (error);
}

int	draw_tile(t_game *game, int nb_items, int i, int j)
{
	if (game->map[i][j] == '0')
		game->image = mlx_xpm_file_to_image(game->mlx, BACKGROUND,
				&game->img_width, &game->img_heigth);
	else if (game->map[i][j] == '1')
		game->image = mlx_xpm_file_to_image(game->mlx, WALL,
				&game->img_width, &game->img_heigth);
	else if (game->map[i][j] == 'E')
	{
		game->exit_y = i;
		game->exit_x = j;
		game->image = mlx_xpm_file_to_image(game->mlx, EXIT,
				&game->img_width, &game->img_heigth);
	}
	else if (nb_items++, game->map[i][j] == 'C')
		game->image = mlx_xpm_file_to_image(game->mlx, COLLECTIBLE,
				&game->img_width, &game->img_heigth);
	else if (game->map[i][j] == 'P')
	{
		game->player_y = i;
		game->player_x = j;
		game->image = mlx_xpm_file_to_image(game->mlx, PLAYER,
				&game->img_width, &game->img_heigth);
	}
	return (nb_items);
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
				return (write(STDERR_FILENO, "fail\n", 5), -1);
			mlx_put_image_to_window(game->mlx, game->window, game->image, x, y);
			mlx_destroy_image(game->mlx, game->image);
			x += TILE_SIZE;
		}
		y += TILE_SIZE;
	}
	return (nb_items);
}

int	free_game(t_game *game)
{
	size_t	i;

	i = 0;
	if (game->window)
		mlx_destroy_window(game->mlx, game->window);
	i = -1;
	while (i++, game->map[i])
		free(game->map[i]);
	free(game->map);
	free(game->mlx);
	return (0);
}
