/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_middle_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <jdesmare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 20:25:27 by jdesmare          #+#    #+#             */
/*   Updated: 2017/01/28 20:36:41 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

static int		ft_get_med_pos(int *tab, int size)
{
	int		i;

	i = 0;
	while (i < size / 2)
	{
		
		i++;
	}
	return (i);
}

void	ft_half_sort(t_struct *piles)
{
	int		min;

	while (ft_is_finished(piles) == 0)
	{
		while (ft_is_sorted(piles->a, piles->size_a) == 0)
		{
			min = ft_ismin(piles->a, piles->size_a);
			if (piles->a[0] == min)
				ft_pb(piles);
			else if (piles->a[piles->size_a] == min)
				ft_rra(piles);
			else if (ft_find_min_pos(piles->a, min) > piles->size_a / 2)
				ft_rra(piles);
			else if (piles->a[0] - 1 == piles->a[0])
				ft_sa(piles);
			else
				ft_ra(piles);
			if (piles->size_a < 15)
				ft_insertion(piles);
		}
		while (piles->size_b > 0)
			ft_pa(piles);
	}
}
