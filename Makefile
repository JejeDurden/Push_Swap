# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdesmare <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/11 10:38:56 by jdesmare          #+#    #+#              #
#*   Updated: 2017/02/01 19:52:29 by jdesmare         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME2 = checker

CC = gcc $(FLAGS)

FLAGS = -Wall -Werror -Wextra

INCLUDES = ./includes/

SRC =	ft_push_swap.c						\
		ft_parser.c							\
		ft_is_finished.c					\
		ft_init_struct.c					\
		commands.c							\
		commands2.c							\
		commands3.c							\
		moves.c								\
		ft_sort_rate.c						\
		ft_insertion.c						\
		ft_free_piles.c						\
		ft_card_sort.c						\
		ft_copy_pile_a.c					\
		ft_find_num_pos.c					\
		ft_full_tab_sort.c					\
		ft_merge_sort.c						\
		ft_middle_sort.c					\
		ft_median_sort.c					\
		odd_even.c							\

SRC2 =	ft_checker.c						\
		ft_parser.c							\
		commands.c							\
		commands2.c							\
		commands3.c							\
		ft_exec_command.c					\
		ft_is_finished.c					\
		ft_init_struct.c					\
		moves.c								\
		ft_free_piles.c						\

OBJ = $(SRC:.c=.o)
OBJ2 = $(SRC2:.c=.o)

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
	@echo "Erasing .o files in Push_Swap..."
	@rm -f $(OBJ) $(OBJ2)
	@echo "Done."

fclean: clean
	@make fclean -C ./libft/
	@echo "Erasing $(NAME)..."
	@rm -f $(NAME) $(NAME2)
	@echo "Done."

re: fclean all clean

.PHONY: all, clean, fclean, re
