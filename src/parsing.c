/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeferre <maeferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 11:47:10 by maeferre          #+#    #+#             */
/*   Updated: 2024/01/16 19:52:01 by maeferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"
#include <stdbool.h>

static bool	check_close_rectangle(char **map);

#include <stdio.h>
bool	parsing(char **map)
{
	// Verif que la carte est un rectangle entoure de murs
	if (!check_close_rectangle(map))
		return (false);

	// Verif que la carte contient 1 entree, 1 sortie et >= 1 item
	
	// Verif que tout les collectibles sont accessibles
	
	// Verif qu'il y a un chemin valide


	// Si la fonction arrive ici cela signifie que ma map est valide
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
		if (map[i][0] != '1' || map[i][j] != '\0' || map[i][j - 1] != '1')
			return (false);
	j = -1;
	while (j++, map[i][j])
		if (map[i][j] != '1')
			return (false);
	return (true);
}
