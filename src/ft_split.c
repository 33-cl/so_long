/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeferre <maeferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 00:18:58 by maeferre          #+#    #+#             */
/*   Updated: 2024/03/17 19:55:50 by maeferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_len_word(char const *s, char c)
{
	size_t		length;

	length = 0;
	while (*s && *s != c)
	{
		length++;
		s++;
	}
	return (length);
}

static void	*ft_free_tab(char **tab)
{
	size_t		i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	return (NULL);
}

static size_t	ft_count_word(char const *s, char c)
{
	size_t	i;
	size_t	nb_strings;

	i = 0;
	nb_strings = 0;
	while (s[i] == c && s[i])
		i++;
	while (s[i])
	{
		nb_strings++;
		while (s[i] != c && s[i])
			i++;
		while (s[i] == c && s[i])
			i++;
	}
	return (nb_strings);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	nb_strings;
	size_t	i;

	if (!s)
		return (NULL);
	nb_strings = ft_count_word(s, c);
	tab = malloc(sizeof(char *) * (nb_strings + 1));
	if (!tab)
		return (NULL);
	tab[nb_strings] = NULL;
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			tab[i] = ft_substr(s, 0, ft_len_word(s, c));
			if (!tab[i++])
				return (ft_free_tab(tab));
			s += ft_len_word(s, c);
		}
		else
			s++;
	}
	return (tab);
}
