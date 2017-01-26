/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <jdesmare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 14:10:15 by jdesmare          #+#    #+#             */
/*   Updated: 2017/01/26 19:16:26 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	ft_sa(t_struct *piles)
{
	int		temp;

	temp = 0;
	if (piles->size_a > 1)
	{
		temp = piles->a[0];
		piles->a[0] = piles->a[1];
		piles->a[1] = temp;
	}
	if (piles->push_swap == 1 && piles->test == 0)
		ft_putstr("sa\n");
	else if (piles->push_swap == 1 && piles->test == 1)
		piles->moves++;
}

void	ft_sb(t_struct *piles)
{
	int		temp;

	temp = 0;
	if (piles->size_b > 1)
	{
		temp = piles->b[0];
		piles->b[0] = piles->b[1];
		piles->b[1] = temp;
	}
	if (piles->push_swap == 1 && piles->test == 0)
		ft_putstr("sb\n");
	else if (piles->push_swap == 1 && piles->test == 1)
		piles->moves++;
}

void	ft_ss(t_struct *piles)
{
	int		temp;

	temp = 0;
	if (piles->size_a > 1)
	{
		temp = piles->a[0];
		piles->a[0] = piles->a[1];
		piles->a[1] = temp;
	}
	if (piles->size_b > 1)
	{
		temp = piles->b[0];
		piles->b[0] = piles->b[1];
		piles->b[1] = temp;
	}
	if (piles->push_swap == 1 && piles->test == 0)
		ft_putstr("ss\n");
	else if (piles->push_swap == 1 && piles->test == 1)
		piles->moves++;
}

void	ft_pa(t_struct *piles)
{
	if (piles->size_b > 0)
	{
		ft_move_up_a(piles);
		piles->a[0] = piles->b[0];
		ft_move_down_b(piles);
	}
	if (piles->push_swap == 1 && piles->test == 0)
		ft_putstr("pa\n");
	else if (piles->push_swap == 1 && piles->test == 1)
		piles->moves++;
}

void	ft_pb(t_struct *piles)
{
	if (piles->size_a > 0)
	{
		ft_move_up_b(piles);
		piles->b[0] = piles->a[0];
		ft_move_down_a(piles);
	}
	if (piles->push_swap == 1 && piles->test == 0)
		ft_putstr("pa\n");
	else if (piles->push_swap == 1 && piles->test == 1)
		piles->moves++;
}
