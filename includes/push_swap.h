/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <jdesmare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 10:54:00 by jdesmare          #+#    #+#             */
/*   Updated: 2017/02/02 10:30:22 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct		s_struct
{
	int		*a;
	int		*b;
	int		size_a;
	int		size_b;
	int		sizemax;
	int		push_swap;
	int		error;
	int		test;
	int		moves;
}					t_struct;

typedef struct		s_algos
{
	int		insertion;
	int		median_sort;
	int		merge_sort;
}					t_algos;

typedef struct		s_num
{
	int		med;
	int		up;
	int		down;
	int		up2;
}					t_num;

int					ft_valid_num(char *argv, char **tabstr, int n);
int					ft_valid_int(char *argv);
void				ft_checker(t_struct *piles);
void				ft_push_swap(t_struct *piles);
int					ft_exec_command(char *line, t_struct *piles);
int					ft_is_finished(t_struct *piles);
t_struct			*ft_init_struct(int argc);
void				ft_move_up_a(t_struct *piles);
void				ft_move_up_b(t_struct *piles);
void				ft_move_down_a(t_struct *piles);
void				ft_move_down_b(t_struct *piles);
void				ft_sa(t_struct *piles);
void				ft_sb(t_struct *piles);
void				ft_ss(t_struct *piles);
void				ft_pa(t_struct *piles);
void				ft_pb(t_struct *piles);
void				ft_ra(t_struct *piles);
void				ft_rb(t_struct *piles);
void				ft_rr(t_struct *piles);
void				ft_rra(t_struct *piles);
void				ft_rrb(t_struct *piles);
void				ft_rrr(t_struct *piles);
void				ft_insertion(t_struct *piles);
void				ft_merge_sort(t_struct *piles);
void				ft_median_sort(t_struct *piles);
void				ft_card_sort(t_struct *piles);
void				ft_free_piles(t_struct **piles);
int					ft_find_num_pos(int *tab, int num, int size);
void				ft_copy_pile_a(t_struct *temp, t_struct *piles);
void				ft_split_piles(t_struct *piles, t_struct *temp,
						t_num *nums);
int					ft_get_first_bug(int *tab, int size);
void				ft_both_odd(t_struct *piles);
void				ft_both_even(t_struct *piles);
void				ft_odd_b(t_struct *piles);
void				ft_odd_a(t_struct *piles);
void				ft_sort_by_two(t_struct *piles);

#endif
