/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_merge_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <jdesmare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 15:26:32 by jdesmare          #+#    #+#             */
/*   Updated: 2017/02/01 15:58:43 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void		ft_sort_by_two(t_struct *piles)
{
	int		last;

	last = piles->b[piles->size_b - 1];
	while (piles->b[0] != last && piles->b[1] != last)
	{
		if (piles->a[0] > piles->a[1] && piles->b[0] > piles->b[1])
			ft_ss(piles);
		else if (piles->a[0] > piles->a[1])
			ft_sa(piles);
		else if (piles->b[0] > piles->b[1])
			ft_sb(piles);
		if (piles->b[0] != last && piles->b[1] != last)
		{
			ft_rr(piles);
			ft_rr(piles);
		}
	}
	if (piles->size_b % 2 != 0 && piles->size_a % 2 != 0)
		ft_both_odd(piles);
	else if (piles->size_a % 2 != 0)
		ft_odd_a(piles);
	else if (piles->size_b % 2 != 0)
		ft_odd_b(piles);
	else
		ft_both_even(piles);
}

static void		ft_push_to_a(t_struct *piles, int n)
{
	int		temp;
	int		temp2;

	temp = 0;
	temp2 = 0;
	while (temp < n)
	{
		if (piles->a[0] < piles->b[0] && temp2++ < n)
			ft_ra(piles);
		else
		{
			ft_pa(piles);
			ft_ra(piles);
			temp++;
		}
	}
	n = n * 2 - temp2 - temp;
	while (n-- > 0)
		ft_ra(piles);
}
static void		ft_push_to_b(t_struct *piles, int n)
{
	int		temp;
	int		temp2;

	temp = 0;
	temp2 = 0;
	while (temp < n)
	{
		if (piles->b[0] < piles->a[0] && temp2++ < n)
			ft_rb(piles);
		else
		{
			ft_pb(piles);
			ft_rb(piles);
			temp++;
		}
	}
	n = n * 2 - temp2 - temp;
	while (n-- > 0)
		ft_rb(piles);
}



static void		ft_mergeation(t_struct *piles, int n)
{
	int		last;
	int		flag;
	int		turn;
//	int		i;

	flag = (piles->size_a >= piles->size_b) ? 2 : 3;
	turn = (piles->size_a <= piles->size_b) ? piles->size_b / n :
		piles->size_a / n;
	while (turn > 0 && (ft_is_sorted(piles->a, piles->size_a) == 0 ||
				ft_is_sorted(piles->b, piles->size_b) == 0))
	{
		last = piles->b[n];
/*			i = 0;
			while (i < piles->size_a)
			{
				printf("%d ", piles->a[i]);
				i++;
			}
			printf("\n");
			i = 0;
			sleep(1);
			while (i < piles->size_b)
			{
				printf("%d ", piles->b[i]);
				i++;
			}
			printf("\n");
			printf("n =  %d", n);
			printf("\n");
			printf("last %d", last);
			printf("\n");*/
		if (flag % 2 == 1)
			ft_push_to_a(piles, n);
		else
			ft_push_to_b(piles, n);
		flag++;
		turn--;
	}
}

void			ft_merge_sort(t_struct *piles)
{
	int		n;
	int		i;

	if (piles->size_a > 4)
	{
		while (piles->size_a > piles->sizemax / 2)
			ft_pb(piles);
		ft_sort_by_two(piles);
/*			i = 0;
			while (i < piles->size_a)
			{
				printf("%d ", piles->a[i]);
				i++;
			}
			printf("\n");
			sleep(1);
			i = 0;
			while (i < piles->size_b)
			{
				printf("%d ", piles->b[i]);
				i++;
			}
			printf("\n");
			printf("oui oui\n");*/
		n = 2;
		while (n <= piles->sizemax / 2
				&& (ft_is_sorted(piles->a, piles->size_a) == 0 ||
					ft_is_sorted(piles->b, piles->size_b) == 0))
		{
			i = 0;
			while (i < piles->size_b % n && n != 2)
			{
				ft_rb(piles);
				i++;
			}
			i = 0;
			while (i < piles->size_a % n && n != 2)
			{
				ft_ra(piles);
				i++;
			}
			ft_mergeation(piles, n);
			n *= 2;
		}
		ft_card_sort(piles);
	}
	else
		piles->moves = 70;
}
