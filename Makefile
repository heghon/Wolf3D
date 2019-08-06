# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmenant <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/13 13:10:40 by bmenant           #+#    #+#              #
#    Updated: 2019/08/04 13:24:59 by sseneca          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN = \033[0;32m
BLUE = \033[1;34m
YELLOW = \033[1;33m
WHITE = \033[1;37m
OK = $(GREEN)-OK-$(WHITE)

NAME = wolf3d

SRC_FILE = ./src/
OBJ_FILE = ./obj/

SRCS =	main.c \
		init.c \
		map_handler.c \
		drawing_handler.c \
		launch_rays.c \
		movements.c \
		special_movements.c


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
	@ $(CC) $(LFLAGS) $(OBJ) -o $@ $(FLAGS) -fsanitize=address
	@echo "$(BLUE)-$(NAME)		$(OK)"

$(OBJ_FILE)%.o : $(SRC_FILE)%.c
	@ mkdir $(OBJ_FILE) 2> /dev/null || true
	@ $(CC) $(IFLAGS) -o $@ -c $<

clean :
	@ make clean -C ./libft/
	@ rm -rf $(OBJ)
	@ rmdir $(OBJ_FILE) 2> /dev/null || true
	@echo "$(BLUE)-CLEAN		$(OK)"

fclean : clean
	@ make fclean -C ./libft/
	@ rm -f $(NAME)
	@echo "$(BLUE)-FCLEAN		$(OK)"

re	: fclean all

push:
	@git add -A
	@git commit -m "make push"
	@echo "\n$(BLUE)-COMMIT	$(OK)"
	@git push origin sseneca
	@echo "\n$(BLUE)-PUSH	$(OK)"

test : re
	@ ./$(NAME) test_map
