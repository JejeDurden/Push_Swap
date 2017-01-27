/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_merge_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <jdesmare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 15:26:32 by jdesmare          #+#    #+#             */
/*   Updated: 2017/01/27 20:41:43 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

static void		ft_pivotal_sort(t_struct *piles)
{
	int		pivot;
	int		i;

	pivot = piles->b[0];
	i = 0;
	while (i < piles->size_a)
	{
		if (piles->a[i] < pivot)
			ft_pb(piles);
		else
		{
			ft_ra(piles);
			printf("coucou\n");
		}
		i++;
/*		i = 0;
		while (i < piles->size_a)
		{
			printf("%d ", piles->a[i]);
			i++;
		}
		printf("\n");
		i = 0;
		while (i < piles->size_b)
		{
			printf("%d ", piles->b[i]);
			i++;
		}
		printf("\n");
		printf("pile a sorted = %d\n", ft_is_sorted(piles->a, piles->size_a));
		printf("\n");
		printf("pile b sorted = %d\n", ft_is_sorted(piles->b, piles->size_b));
		printf("\n");*/
	}
}

void			ft_merge_sort(t_struct *piles)
{
	int		max_a;
	int		i;

	max_a = ft_ismax(piles->a, piles->size_a);
	i = 0;
	while (piles->a[0] < piles->a[1] && i < piles->size_a)
	{
		ft_ra(piles);
		i++;
	}
	ft_pb(piles);
	ft_pivotal_sort(piles);
	while (piles->size_b > 0)
	{
		if (piles->a[0] < piles->b[0] && max_a > piles->b[0])
			ft_ra(piles);
		else
			ft_pa(piles);
	}
	while (ft_ismin(piles->a, piles->size_a) < piles->a[0])
		ft_ra(piles);
/*	i = 0;
	while (i < piles->size_a)
	{
		printf("%d ", piles->a[i]);
		i++;
	}
	printf("\n");*/
	if (ft_is_finished(piles) == 0)
		ft_merge_sort(piles);
}
