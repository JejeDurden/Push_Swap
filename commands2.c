/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <jdesmare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 14:16:36 by jdesmare          #+#    #+#             */
/*   Updated: 2017/01/25 18:09:40 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	ft_ra(t_struct *piles)
{
	int		temp;
	int		i;

	temp = piles->a[0];
	i = 0;
	while (i < piles->size_a)
	{
		piles->a[i] = piles->a[i + 1];
		i++;
	}
	piles->a[piles->size_a - 1] = temp;
	if (piles->push_swap == 1)
		ft_putstr("ra\n");
}

void	ft_rb(t_struct *piles)
{
	int		temp;
	int		i;

	temp = piles->b[0];
	i = 0;
	while (i < piles->size_b)
	{
		piles->b[i] = piles->b[i + 1];
		i++;
	}
	piles->b[piles->size_b - 1] = temp;
	if (piles->push_swap == 1)
		ft_putstr("rb\n");
}

void	ft_rr(t_struct *piles)
{
	int		temp;
	int		i;

	temp = piles->a[0];
	i = 0;
	while (i < piles->size_a)
	{
		piles->a[i] = piles->a[i + 1];
		i++;
	}
	piles->a[piles->size_a - 1] = temp;
	temp = piles->b[0];
	i = 0;
	while (i < piles->size_b)
	{
		piles->b[i] = piles->b[i + 1];
		i++;
	}
	piles->b[piles->size_b - 1] = temp;
	if (piles->push_swap == 1)
		ft_putstr("rr\n");
}
