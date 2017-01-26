/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insertion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <jdesmare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 15:36:46 by jdesmare          #+#    #+#             */
/*   Updated: 2017/01/26 19:58:46 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

static int	ft_get_last_bug(t_struct *piles)
{
	int		i;

	i = piles->sizemax;
	while (piles->a[i] > piles->a[i - 1])
		i--;
	return (i - 1);
}

static int	ft_get_first_bug(t_struct *piles)
{
	int		i;

	i = 1;
	while (piles->a[i] > piles->a[i - 1])
		i++;
	return (i);
}

void	ft_insertion(t_struct *piles)
{
	int		i;
	int		min;
	int		first_bug;
	int		last_bug;

	min = ft_ismin(piles->a, piles->size_a);
	while (ft_is_sorted(piles) == 0)
	{
		first_bug = ft_get_first_bug(piles);
		last_bug = ft_get_last_bug(piles);
		if (first_bug > piles->size_a / 2)
		{
			i = piles->size_a - last_bug;
			while (i-- >= 0)
				ft_rra(piles);
		}
		else
		{
			if (piles->a[0] == min)
				ft_ra(piles);
			else if (piles->a[1] < piles->a[0])
				ft_sa(piles);
			else
				ft_ra(piles);
		}
	/*	i = 0;
		while (i < piles->size_a)
		{
			ft_putnbr(piles->a[i]);
			ft_putchar(' ');
			i++;
		}
		ft_putstr("\n\n");*/
	}
}
