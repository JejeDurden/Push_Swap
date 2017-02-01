/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_half_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <jdesmare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 10:00:47 by jdesmare          #+#    #+#             */
/*   Updated: 2017/02/01 15:27:02 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

int		ft_find_num_pos(int *tab, int num, int size)
{
	int		i;

	i = 0;
	while (tab[i] != num && i <= size)
		i++;
	if (i < size)
		return (i);
	else
		return (-1);
}

void	ft_half_sort(t_struct *piles)
{
	int		min;

	if (piles->sizemax > 3)
	{
		while (ft_is_finished(piles) == 0)
		{
			while (ft_is_sorted(piles->a, piles->size_a) == 0)
			{
				min = ft_ismin(piles->a, piles->size_a);
				if (piles->a[0] == min)
					ft_pb(piles);
				else if (piles->a[piles->size_a] == min)
					ft_rra(piles);
				else if (ft_find_num_pos(piles->a, min, piles->size_a) > piles->size_a / 2)
					ft_rra(piles);
				else
					ft_ra(piles);
				if (piles->size_a < 15)
					ft_insertion(piles);
			}
		while (piles->size_b > 0)
			ft_pa(piles);
		}
	}
	else
		piles->moves = 70;
}
