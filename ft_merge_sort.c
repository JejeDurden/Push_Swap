/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_merge_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <jdesmare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 15:26:32 by jdesmare          #+#    #+#             */
/*   Updated: 2017/01/27 17:10:53 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

static void		ft_simultaneous_sort(t_struct *piles)
{
	int		max_a;
	int		max_b;
	int		bug_a;
	int		bug_b;
	int		i;

	max_a = ft_ismax(piles->a, piles->size_a);
	max_b = ft_ismax(piles->b, piles->size_b);
	while (ft_is_sorted(piles->a, piles->size_a) == 0 ||
			ft_is_sorted(piles->b, piles->size_b) == 0)
	{
	//	printf("ouiiiiiiiiii \n");
		bug_a = ft_get_first_bug(piles->a);
		bug_b = ft_get_first_bug(piles->b);
		if (bug_a > piles->size_a / 2 && bug_b > piles->size_b / 2)
			ft_rrr(piles);
		else if (bug_a > piles->size_a / 2)
			ft_rra(piles);
		else if (bug_b > piles->size_b / 2)
			ft_rrb(piles);
		else if (piles->a[0] == max_a && piles->b[0] == max_b)
			ft_rr(piles);
		else if (piles->a[0] == max_a)
			ft_ra(piles);
		else if (piles->b[0] == max_b)
			ft_rb(piles);
		else if (piles->a[1] < piles->a[0] && piles->b[1] < piles->b[0])
			ft_ss(piles);
		else if (piles->a[1] < piles->a[0])
			ft_sa(piles);
		else if (piles->b[1] < piles->b[0])
			ft_sb(piles);
		else if (ft_is_sorted(piles->b, piles->size_b) == 1)
			ft_ra(piles);
		else if (ft_is_sorted(piles->a, piles->size_a) == 1)
			ft_rb(piles);
		else
			ft_rr(piles);
		i = 0;
		while (i < piles->size_a)
		{
			printf("%d ", piles->a[i]);
			i++;
		}
		ft_putchar('\n');
	}
}

void			ft_merge_sort(t_struct *piles)
{
	while (piles->size_a > piles->sizemax / 2)
		ft_pb(piles);
	ft_simultaneous_sort(piles);
	printf("lol\n");
	while (piles->size_b != 0)
	{
		if (piles->a[0] > piles->b[0])
			ft_ra(piles);
		else
			ft_pa(piles);
	}
	while (ft_is_finished(piles) == 0)
		ft_ra(piles);
}
