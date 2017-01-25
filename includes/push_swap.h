/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <jdesmare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 10:54:00 by jdesmare          #+#    #+#             */
/*   Updated: 2017/01/25 18:19:07 by jdesmare         ###   ########.fr       */
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
}					t_struct;

int					ft_valid_num(char *argv, char **tabstr, int n);
int					ft_valid_int(char *argv);
void				ft_checker(t_struct *piles);
void				ft_push_swap(t_struct *piles);
void				ft_exec_command(char *line, t_struct *piles);
int					ft_is_sorted(t_struct *piles);
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

#endif
