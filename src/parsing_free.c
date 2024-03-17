/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeferre <maeferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 21:19:36 by maeferre          #+#    #+#             */
/*   Updated: 2024/03/17 20:09:06 by maeferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_players_position(t_game *game)
{
	int	i;
	int	j;
	int	nb_columns;
	int	nb_lines;

	i = -1;
	nb_lines = ft_strlen2d(game->map);
	nb_columns = ft_strlen(*game->map);
	while (i++, i < nb_lines)
	{
		j = -1;
		while (j++, j < nb_columns)
		{
			if (game->map[i][j] == 'P')
			{
				game->player_x = j;
				game->player_y = i;
			}
			else if (game->map[i][j] == 'E')
			{
				game->exit_x = j;
				game->exit_y = i;
			}
		}
	}
}

void	free_map(char **map)
{
	size_t	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

char	**free_and_null(char *map1, char *line)
{
	free(map1);
	free(line);
	return (NULL);
}

int	free_game(t_game *game)
{
	size_t	i;

	if (game->win && game->mlx)
		mlx_destroy_window(game->mlx, game->win);
	i = -1;
	while (i++, game->map[i])
		free(game->map[i]);
	free(game->map);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	return (0);
}
