/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeferre <maeferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:10:03 by maeferre          #+#    #+#             */
/*   Updated: 2024/01/26 19:42:07 by maeferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"
#include "../minilibx-linux/mlx.h"
#include <stdio.h>
#include <X11/X.h>
#include <X11/keysym.h>

// cc mlx.c -Iminilibx-linux -Lminilibx-linux -lmlx -lX11 -lXext -lm

//int		fill_background(t_game game);
int	key_pressed(int keycode, t_game *game);



int main(int argc, char **argv)
{
    t_game	game;
    size_t	i;

	game.map = extract_n_parse(argv);
	if (!game.map)
		return (0);

    // Initialisation de la structure game
    game.mlx = mlx_init();
	game.map_height = ft_strlen2d(game.map) * TILE_SIZE;
	game.map_width = ft_strlen(game.map[0]) * TILE_SIZE;
	printf("width  = %d\nheigth = %d\n", game.map_width, game.map_height);
    game.window = mlx_new_window(game.mlx, game.map_width, game.map_height, "so_long");
    	game.items_collected = 0;

	//fill_background(game) and initialises nb_items at the same time;
	game.nb_items = draw_map(&game, -1, -1);

	mlx_hook(game.window, KeyRelease, KeyReleaseMask, &key_pressed, &game);

    // Boucler jusqu'à ce que la fenêtre soit fermée
    mlx_loop(game.mlx);

    // Liberation de la memoire
    mlx_destroy_window(game.mlx, game.window);
    i = -1;
    while (i++, game.map[i])
	free(game.map[i]);
    free(game.map);
    free(game.mlx);

    return 0;
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
		printf("STOP\n");
		mlx_loop_end(game->mlx);
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

int		draw_map(t_game *game, int i, int j)
{
	void	*image;
	int		x;
	int		y;
	int		nb_items;

	nb_items = 0;
	i = -1;
	y = TILE_SIZE * (-1);
	while (y += TILE_SIZE, i++, game->map[i])
	{
		j = -1;
		x = TILE_SIZE * (-1);
		while (x += TILE_SIZE, j++, game->map[i][j])
		{
			if (game->map[i][j] == '0')
				image = mlx_xpm_file_to_image(game->mlx, "assets/map/background50.xpm", &game->img_width, &game->img_heigth);
			else if (game->map[i][j] == '1')
				image = mlx_xpm_file_to_image(game->mlx, "assets/map/wall50.xpm", &game->img_width, &game->img_heigth);
			else if (game->map[i][j] == 'E')
			{
				game->exit_y = i;
				game->exit_x = j;
				image = mlx_xpm_file_to_image(game->mlx, "assets/sprites/exit50.xpm", &game->img_width, &game->img_heigth);
			}
			else if (game->map[i][j] == 'C')
			{	
				image = mlx_xpm_file_to_image(game->mlx, "assets/sprites/collectible50.xpm", &game->img_width, &game->img_heigth);
				nb_items++;
			}
			else if (game->map[i][j] == 'P')
			{
				game->player_y = i;
				game->player_x = j;
				image = mlx_xpm_file_to_image(game->mlx, "assets/sprites/player50.xpm", &game->img_width, &game->img_heigth);
			}
			if (!image)
					return (printf("fail\n"), -1);
			mlx_put_image_to_window(game->mlx, game->window, image, x, y);
			// Liberation de la memoire de l'image affichee
			mlx_destroy_image(game->mlx, image);
		}
	}

	return (nb_items);
}
/*
int	fill_background(t_game game)
{
	int		i;
	int		j;
	int		width;
	int		height;
	void	*image;
	
	i = 0;
	while (i < game.map_width)
	{
		j = TILE_SIZE * (-1);
		while(j+= TILE_SIZE, j < game.map_height)
		{
			image = mlx_xpm_file_to_image(game.mlx, "assets/map/background50.xpm", &width, &height);
			if (!image)
				return (printf("fail\n"), -1);
			mlx_put_image_to_window(game.mlx, game.window, image, i, j);
			free(image);
		}
		i += TILE_SIZE;
	}
	return (0);
}*/
