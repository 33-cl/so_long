# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maeferre <maeferre@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/11 11:08:39 by maeferre          #+#    #+#              #
#    Updated: 2024/02/07 17:46:45 by maeferre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
STANDARD_FLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -Iminilibx-linux -Lminilibx-linux -lmlx -lX11 -lXext -lm -fsanitize=address -g3
SRC_DIR = ./src/
SRCS_FILES 		= $(addprefix ${SRC_DIR},\
				main.c				\
				movement.c			\
				parsing.c			\
				parsing_utils.c		\
				ft_split.c			\
				ft_strdup.c			\
				ft_strjoin.c		\
				ft_substr.c			\
				ft_strlen2d.c		\
				get_next_line.c		\
				get_next_line_utils.c)
OBJ_FILES = $(SRCS_FILES:%.c=%.o)


all: ${NAME}

clean:
	rm -f src/*.o

fclean:
	rm -f src/*.o ${NAME} 

$(NAME) : $(OBJ_FILES)
	$(CC) $(STANDARD_FLAGS) -o $(NAME) $(OBJ_FILES) $(MLX_FLAGS)

%.o : %.c
	$(CC) -o $@ -c $<

.PHONY: all clean
