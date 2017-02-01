/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   odd_even.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <jdesmare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 13:16:59 by jdesmare          #+#    #+#             */
/*   Updated: 2017/02/01 13:20:01 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void		ft_both_odd(t_struct *piles)
{
	if (piles->b[0] < piles->a[0])
	{
		ft_rb(piles);
		ft_pb(piles);
		ft_rb(piles);
	}
	else
	{
		ft_pb(piles);
		ft_rb(piles);
		ft_rb(piles);
	}
}

void		ft_both_even(t_struct *piles)
{
	if (piles->a[0] > piles->a[1] && piles->b[0] > piles->b[1])
		ft_ss(piles);
	else if (piles->a[0] > piles->a[1])
		ft_sa(piles);
	else if (piles->b[0] > piles->b[1])
		ft_sb(piles);
}

void		ft_odd_b(t_struct *piles)
{
	if (piles->a[0] > piles->a[1])
		ft_sa(piles);
	if (piles->b[0] < piles->a[0])
	{
		ft_pa(piles);
		ft_ra(piles);
		ft_ra(piles);
	}
	else if (piles->b[0] < piles->a[1])
	{
		ft_ra(piles);
		ft_pa(piles);
		ft_ra(piles);
	}
	else
	{
		ft_ra(piles);
		ft_ra(piles);
		ft_pa(piles);
	}
	ft_ra(piles);
}

void		ft_odd_a(t_struct *piles)
{
	if (piles->b[0] > piles->b[1])
		ft_sb(piles);
	if (piles->a[0] < piles->b[0])
	{
		ft_pb(piles);
		ft_rb(piles);
		ft_rb(piles);
	}
	else if (piles->a[0] < piles->b[1])
	{
		ft_rb(piles);
		ft_pb(piles);
		ft_rb(piles);
	}
	else
	{
		ft_rb(piles);
		ft_rb(piles);
		ft_pb(piles);
	}
	ft_rb(piles);
}
