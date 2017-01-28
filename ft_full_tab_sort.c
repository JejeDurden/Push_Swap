/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_full_tab_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <jdesmare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 18:32:48 by jdesmare          #+#    #+#             */
/*   Updated: 2017/01/28 18:56:00 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

static int		ft_find_max_pos(int *tab, int max)
{
	int		i;

	i = 0;
	while (tab[i] != max)
		i++;
	return (i);
}

void	ft_full_tab_sort(t_struct *piles)
{
	int		max;
	int		flag;

	flag = 1;
	while (ft_is_finished(piles) == 0)
	{
		while (piles->size_a > 0 && flag == 1)
			ft_pb(piles);
		flag = 0;
		max = ft_ismax(piles->b, piles->size_b);
		if (piles->b[0] == max)
			ft_pa(piles);
		else if (piles->b[piles->size_b] == max)
			ft_rrb(piles);
		else if (ft_find_max_pos(piles->b, max) > piles->size_b / 2)
			ft_rrb(piles);
		else
			ft_rb(piles);
	}
}
