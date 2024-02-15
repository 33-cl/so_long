/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeferre <maeferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 19:57:18 by maeferre          #+#    #+#             */
/*   Updated: 2024/02/15 18:25:38 by maeferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include "get_next_line.h"

// Minilibx related libraries
# include <X11/X.h>
# include <X11/keysym.h>
# include "../minilibx-linux/mlx.h"

# define COLLECTIBLE "assets/sprites/collectible50.xpm"
# define BACKGROUND "assets/map/background50.xpm"
# define PLAYER "assets/sprites/player50.xpm"
# define WALL "assets/map/wall50.xpm"
# define EXIT "assets/sprites/exit50.xpm"

# define N "so_long"
# define TILE_SIZE 50

# define KEY_UP 65362
# define KEY_LEFT 65361
# define KEY_DOWN 65364
# define KEY_RIGHT 65363

typedef struct s_game
{
	char	**map;
	void	*window;
	void	*mlx;
	int		map_height;
	int		map_width;
	int		img_heigth;
	int		img_width;
	int		player_x;
	int		player_y;
	int		exit_x;
	int		exit_y;
	int		items_collected;
	int		nb_items;
	size_t	nb_steps;
	void	*image;
}	t_game;

// Libft functions
int		ft_putstr(char *s);
bool	ft_putnbr(int n);
size_t	ft_strlen2d(char **tab);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);

// Free functions
int		free_game(t_game *game);
void	free_map(char **map);
char	**free_and_null(char *map1, char *line);

// Map related functions
bool	parsing(char **map);
bool	check_invalid_extension(char *file);
bool	check_empty_map(char **map);
bool	multiple_new_lines(char *map);
char	**extract_map(char *argv);
char	**extract_n_parse(char **argv);
int		draw_map(t_game *game, int i, int j);

// User related functions
bool	go_up(t_game *game, char player);
bool	go_down(t_game *game, char player);
bool	go_left(t_game *game, char player);
bool	go_right(t_game *game, char player);
int		key_pressed(int keycode, t_game *game);
int		key_pressed(int keycode, t_game *game);

#endif
