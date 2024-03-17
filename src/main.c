/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeferre <maeferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 19:12:18 by maeferre          #+#    #+#             */
/*   Updated: 2024/03/17 21:03:36 by maeferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	ft_bzero(&game, sizeof(t_game));
	if (argc != 2)
		return (write(2, "Error\n", 6));
	game.map = extract_n_parse(argv);
	if (!game.map)
		return (0);
	game.mlx = mlx_init();
	if (!game.mlx)
		return (free_game(&game), 0);
	game.map_height = ft_strlen2d(game.map) * TILE_SIZE;
	game.map_width = ft_strlen(game.map[0]) * TILE_SIZE;
	game.win = mlx_new_window(game.mlx, game.map_width, game.map_height, N);
	if (!game.win)
		return (free_game(&game), 0);
	game.nb_items = draw_map(&game, -1, -1);
	if (game.nb_items == -1)
		return (free_game(&game), 0);
	mlx_hook(game.win, 2, 1L << 0, &key_pressed, &game);
	mlx_hook(game.win, 17, 0L, &close_window, &game);
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

int	close_window(t_game *game)
{
	mlx_loop_end(game->mlx);
	write(1, "STOP\n", 5);
	return (0);
}
