/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_card_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <jdesmare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 10:25:16 by jdesmare          #+#    #+#             */
/*   Updated: 2017/01/30 13:16:43 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

static int		ft_find_closest_upper(t_struct *piles, int nb)
{
	int		closest;
	int		current;
	int		i;

	current = ft_ismax(piles->a, piles->size_a);
	closest = (current > nb) ? current : -1;
	i = 0;
	while (i < piles->size_a)
	{
		if (piles->a[i] > nb && piles->a[i] < current)
		{
			current = piles->a[i];
			closest = current;
		}
		i++;
	}
	return (closest);
}
void			ft_card_sort(t_struct *piles)
{
	int		closest;
	int		closest_pos;

	while (piles->size_a > 2)
		ft_pb(piles);
	if (ft_is_sorted(piles->a, piles->size_a) == 0)
		ft_sa(piles);
	while (piles->size_b > 0)
	{
		closest = ft_find_closest_upper(piles, piles->b[0]);
		if (closest == -1)
			closest = ft_ismin(piles->a, piles->size_a);
		closest_pos = ft_find_num_pos(piles->a, closest, piles->size_a);
		if (closest_pos > (piles->size_a - 1) / 2)
			while (piles->a[0] != closest)
				ft_rra(piles);
		else
			while (piles->a[0] != closest)
				ft_ra(piles);
		ft_pa(piles);
	}
	while (ft_is_finished(piles) == 0)
		ft_ra(piles);
}
