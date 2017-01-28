/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_merge_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <jdesmare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 15:26:32 by jdesmare          #+#    #+#             */
/*   Updated: 2017/01/28 20:02:14 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"
/*
static void			ft_fusion(t_struct *piles, int start, int middle, int end)
{
	int		i;
	int		j;
	int		k;
	int		range;

	i = start;
	j = 0;
	range = middle - start;
	while (i < middle)
	{
		ft_pb(piles);
		i++;
	}
	i = end;
	k = start;
		i = 0;
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
		printf("\n");
}*/

static void		ft_simultaneous_sort(t_struct *piles)
{
	int		max_a;
	int		max_b;
	int		first_bug_a;
	int		first_bug_b;
	int		i;

	max_a = ft_ismax(piles->a, piles->size_a);
	max_b = ft_ismax(piles->b, piles->size_b);
	while (ft_is_sorted(piles->b, piles->size_b) == 0 || ft_is_sorted(piles->b, piles->size_b) == 0)
	{
		first_bug_a = ft_get_first_bug(piles->a, piles->size_a);
		first_bug_b = ft_get_first_bug(piles->b, piles->size_b);
		if (piles->a[0] > piles->a[1] && piles->b[0] > piles->b[1])
			ft_ss(piles);
		else if (first_bug_b > piles->size_b / 2 && first_bug_a > piles->size_a / 2)
			ft_rrr(piles);
		else if (first_bug_b > piles->size_b / 2)
			ft_rrb(piles);
		else if (first_bug_a > piles->size_a / 2)
			ft_rra(piles);
		else if (piles->a[0] > piles->a[1])
			ft_sa(piles);
		else if (piles->b[0] > piles->b[1])
			ft_sb(piles);
		else if (ft_is_sorted(piles->b, piles->size_b) == 1)
			ft_insertion(piles);
		else
			ft_rr(piles);
		i = 0;
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
		printf("\n");
	}
}

void			ft_merge_sort(t_struct *piles)
{
	int		min_a;

	while (piles->size_a > piles->sizemax / 2)
		ft_pb(piles);
	ft_simultaneous_sort(piles);
	while (piles->size_b > 0)
	{
		min_a = ft_ismin(piles->a, piles->size_a);
		if (piles->a[0] < piles->b[0])
			ft_ra(piles);
		else if (piles->b[0] < min_a)
			ft_pa(piles);
		else
			ft_pa(piles);
	}
	while (ft_is_finished(piles) == 0)
		ft_ra(piles);
}
