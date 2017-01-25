/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <jdesmare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 14:16:54 by jdesmare          #+#    #+#             */
/*   Updated: 2017/01/25 18:11:53 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	ft_rra(t_struct *piles)
{
	int		temp;
	int		i;

	temp = piles->a[piles->size_a - 1];
	i = piles->size_a - 1;
	while (i > 0)
	{
		piles->a[i] = piles->a[i - 1];
		i--;
	}
	piles->a[0] = temp;
	if (piles->push_swap == 1)
		ft_putstr("rra\n");
}

void	ft_rrb(t_struct *piles)
{
	int		temp;
	int		i;

	temp = piles->b[piles->size_b - 1];
	i = piles->size_b - 1;
	while (i > 0)
	{
		piles->b[i] = piles->b[i - 1];
		i--;
	}
	piles->b[0] = temp;
	if (piles->push_swap == 1)
		ft_putstr("rrb\n");
}

void	ft_rrr(t_struct *piles)
{
	int		temp;
	int		i;

	temp = piles->a[piles->size_a - 1];
	i = piles->size_a - 1;
	while (i > 0)
	{
		piles->a[i] = piles->a[i - 1];
		i--;
	}
	piles->a[0] = temp;
	temp = piles->b[piles->size_b - 1];
	i = piles->size_b - 1;
	while (i > 0)
	{
		piles->b[i] = piles->b[i - 1];
		i--;
	}
	piles->b[0] = temp;
	if (piles->push_swap == 1)
		ft_putstr("rrr\n");
}
