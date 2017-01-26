/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <jdesmare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 14:16:54 by jdesmare          #+#    #+#             */
/*   Updated: 2017/01/26 19:18:03 by jdesmare         ###   ########.fr       */
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
	if (piles->push_swap == 1 && piles->test == 0)
		ft_putstr("rra\n");
	else if (piles->push_swap == 1 && piles->test == 1)
		piles->moves++;
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
	if (piles->push_swap == 1 && piles->test == 0)
		ft_putstr("rrb\n");
	else if (piles->push_swap == 1 && piles->test == 1)
		piles->moves++;
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
	if (piles->push_swap == 1 && piles->test == 0)
		ft_putstr("rrr\n");
	else if (piles->push_swap == 1 && piles->test == 1)
		piles->moves++;
}
