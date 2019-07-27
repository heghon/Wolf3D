# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmenant <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/09 15:15:33 by bmenant           #+#    #+#              #
#    Updated: 2019/07/02 11:41:04 by bmenant          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -Wall -Wextra -Werror
CC = gcc $(FLAGS)

SRC =	ft_absolute.c \
		ft_arc_to_rad.c \
		ft_atoi.c \
		ft_bzero.c \
		ft_double_tab.c \
		ft_double_tab_int.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_lstadd.c \
		ft_lstdel.c \
		ft_lstdelone.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_lstnew.c \
		ft_memalloc.c \
		ft_memccpy.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memdel.c \
		ft_memmove.c \
		ft_memset.c \
		ft_putchar.c \
		ft_putchar_fd.c \
		ft_putendl.c \
		ft_putendl_fd.c \
		ft_putnbr.c \
		ft_putnbrendl.c \
		ft_putnbr_fd.c \
		ft_putstr.c \
		ft_putstr_fd.c \
		ft_round_down.c \
		ft_strcat.c \
		ft_strchr.c \
		ft_strclr.c \
		ft_strchri.c \
		ft_strcmp.c \
		ft_strcpy.c \
		ft_strdel.c \
		ft_strdup.c \
		ft_strequ.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strjoinfree.c \
		ft_strlcat.c \
		ft_strlen.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strncat.c \
		ft_strncmp.c \
		ft_strncpy.c \
		ft_strnequ.c \
		ft_strnew.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strsplit.c \
		ft_strstr.c \
		ft_strsub.c \
		ft_strsubfree.c \
		ft_strtrim.c \
		ft_tolower.c \
		ft_toupper.c \
		get_next_line.c

SRCO = $(SRC:.c=.o)

SRC_FILE = ./src/
OBJ_FILE = ./obj/

SRCS = $(addprefix $(SRC_FILE),$(SRC))
OBJS = $(addprefix $(OBJ_FILE),$(SRCO))

.PHONY : all $(NAME) clean fclean all

all: $(NAME)

$(NAME): $(OBJS)
		@ ar rc $(NAME) $(OBJS)

$(OBJ_FILE)%.o : $(SRC_FILE)%.c
		@ mkdir $(OBJ_FILE) 2> /dev/null || true
		@ $(CC) -c $< -o $@

clean:
		@ rm -f $(OBJS)
		@ rmdir $(OBJ_FILE) 2> /dev/null || true

fclean: clean
		@ rm -f $(NAME)

re: fclean all
