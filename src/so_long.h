/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeferre <maeferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 19:57:18 by maeferre          #+#    #+#             */
/*   Updated: 2024/02/05 17:44:57 by maeferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdbool.h>
# include <fcntl.h>
# include "get_next_line.h"

// Minilibx related libraries
# include <X11/X.h>
# include <X11/keysym.h>
# include "../minilibx-linux/mlx.h"

# define TILE_SIZE 50

# define KEY_UP 65362
# define KEY_LEFT 65361
# define KEY_DOWN 65364
# define KEY_RIGHT 65363

typedef struct	s_game{
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
}t_game;

size_t	ft_strlen2d(char **tab);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
bool	parsing(char **map);
char	**free_and_null(char *map1, char *line);
bool	check_invalid_extension(char *file);
bool	multiple_new_lines(char *map);
char	**extract_map(char *argv);
char	**extract_n_parse(char **argv);
int		draw_map(t_game *game, int i, int j);
int		go_up(t_game *game, char player);
int		go_down(t_game *game, char player);
int		go_left(t_game *game, char player);
int		go_right(t_game *game, char player);

#endif
