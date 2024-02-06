# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maeferre <maeferre@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/11 11:08:39 by maeferre          #+#    #+#              #
#    Updated: 2024/02/06 16:09:56 by maeferre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = cc
CFLAGS = -Iminilibx-linux -Lminilibx-linux -lX11 -lXext
SRC_DIR = src
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(SRC_FILES:%.c=%.o)
EXEC = my_program

all: $(EXEC)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(EXEC): $(OBJ_FILES)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f $(SRC_DIR)/*.o $(EXEC)

.PHONY: all clean

