# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdesmare <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/11 10:38:56 by jdesmare          #+#    #+#              #
#*   Updated: 2017/01/24 19:44:46 by jdesmare         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME2 = checker

CC = gcc $(FLAGS)

FLAGS = -Wall -Werror -Wextra

INCLUDES = ./includes/

SRC =	ft_push_swap.c						\
		ft_parser.c							\


SRC2 =	ft_checker.c						\
		ft_parser.c							\

OBJ = $(SRC:.c=.o)
OBJ2 = $(SRC:.c=.o)

all: $(NAME) $(NAME2)

$(NAME): $(OBJ)
	@make -C ./libft/
	@$(CC) -I$(INCLUDES) -c $(SRC)
	@$(CC) $^ -L./libft/ -lft -o $@
	@echo "$(NAME) created successfully"

$(NAME2): $(OBJ2)
	@make -C ./libft/
	@$(CC) -I$(INCLUDES) -c $(SRC2)
	@$(CC) $^ -L./libft/ -lft -o $@
	@echo "$(NAME2) created successfully"

%.o: %.c
	@$(CC) -o $@ -c $<

clean:
	@make clean -C ./libft/
	@echo "Erasing .o files in Filler..."
	@rm -f $(OBJ)
	@echo "Done."

fclean: clean
	@make fclean -C ./libft/
	@echo "Erasing $(NAME)..."
	@rm -f $(NAME)
	@echo "Done."

re: fclean all clean

.PHONY: all, clean, fclean, re
