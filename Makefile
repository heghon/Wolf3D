# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmenant <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/13 13:10:40 by bmenant           #+#    #+#              #
#    Updated: 2019/07/25 13:54:09 by bmenant          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

SRC_FILE = ./src/
OBJ_FILE = ./obj/

SRCS =	main.c \
		key_handler.c \
		init.c \
		map_handler.c \
		drawing_handler.c \
		launch_rays.c \
		direction_moves.c \
		special_moves.c

OBJS = $(SRCS:.c=.o)

SRC = $(addprefix $(SRC_FILE),$(SRCS))
OBJ = $(addprefix $(OBJ_FILE),$(OBJS))

FLAGS = -lmlx -framework OpenGL -framework AppKit
CFLAGS = -Wall -Wextra -Werror
IFLAGS = -I ./inc/
LFLAGS = ./libft/libft.a

CC = gcc $(CFLAGS)

.PHONY: all, clean, fclean, re

all : $(NAME)

$(NAME) : $(OBJ)
	@ make -C./libft/
	@ $(CC) $(LFLAGS) $(OBJ) -o $@ $(FLAGS)

$(OBJ_FILE)%.o : $(SRC_FILE)%.c
	@ mkdir $(OBJ_FILE) 2> /dev/null || true
	@ $(CC) $(IFLAGS) -o $@ -c $<

clean :
	@ make clean -C ./libft/
	@ rm -rf $(OBJ)
	@ rmdir $(OBJ_FILE) 2> /dev/null || true

fclean : clean
	@ make fclean -C ./libft/
	@ rm -f $(NAME)

re	: fclean all

test : re
	@ ./$(NAME) test_map
