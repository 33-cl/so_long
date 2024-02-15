/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeferre <maeferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 13:38:07 by maeferre          #+#    #+#             */
/*   Updated: 2024/02/13 22:19:23 by maeferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 9
# endif

void		shift_buffer(char *buf);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		ft_bzero(void *s, size_t n);
char		*get_next_line(int fd);
char		*fill_temp(char *buf);
char		*temp_to_join(char *s1, char *s2);
size_t		ft_strlen(const char *s);
int			new_line_or_end(char *str);
int			ft_read(int fd, char *buf, char *res);

#endif
