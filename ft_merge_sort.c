/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_merge_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <jdesmare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 15:26:32 by jdesmare          #+#    #+#             */
/*   Updated: 2017/01/30 21:08:56 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

static void		ft_odd_b(t_struct *piles)
{
	if (piles->b[0] < piles->a[0])
	{
		ft_rb(piles);
		ft_pb(piles);
		ft_rb(piles);
		ft_pb(piles);
	}
	else if (piles->b[0] < piles->a[1])
	{
		ft_pb(piles);
		ft_rb(piles);
		ft_rb(piles);
		ft_pb(piles);
	}
	else
	{
		ft_pb(piles);
		ft_rb(piles);
		ft_pb(piles);
		ft_rb(piles);
	}
	ft_rb(piles);
}

static void		ft_odd_a(t_struct *piles)
{
	if (piles->a[0] < piles->b[0])
	{
		ft_pb(piles);
		ft_rb(piles);
		ft_rb(piles);
	}
	else if (piles->a[0] < piles->b[1])
	{
		ft_rb(piles);
		ft_pa(piles);
		ft_rb(piles);
	}
	else
	{
		ft_rb(piles);
		ft_rb(piles);
		ft_pa(piles);
	}
	ft_rb(piles);
}

static void		ft_sort_by_two(t_struct *piles)
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
	if (piles->size_a % 2 != 0)
		ft_odd_a(piles);
	else if (piles->size_b % 2 != 0)
		ft_odd_b(piles);
}

static void		ft_push_it_babe(t_struct *piles, int flag, int n)
{
	int		min;
	int		temp;
	int		temp2;

	temp = n;
	temp2 = 0;
	if (flag % 2 == 1)
	{
		while (temp > 0)
		{
			min = ft_ismin(piles->a, piles->size_a);
			if (piles->a[0] < piles->b[0] && temp2 < n)
			{
				ft_ra(piles);
				temp++;
			}
			else if (piles->b[0] < min)
			{
				ft_pa(piles);
				temp--;
			}
			else
			{
				ft_pa(piles);
				temp--;
			}
		}
		n *= 2;
		while (n > 0)
		{
			ft_ra(piles);
			n--;
		}
	}
	else
	{
		while (temp > 0)
		{
			min = ft_ismin(piles->b, piles->size_b);
			if (piles->b[0] < piles->a[0] && temp2 < n)
			{
				ft_rb(piles);
				temp2++;
			}
			else if (piles->a[0] < min)
			{
				ft_pb(piles);
				temp--;
			}
			else
			{
				ft_pb(piles);
				temp--;
			}
		}
		n *= 2;
		while (n > 0)
		{
			ft_rb(piles);
			n--;
		}
	}
}



static void		ft_mergeation(t_struct *piles, int n)
{
	int		last;
	int		flag;
	int		turn;
	int		i;

	flag = (piles->size_a >= piles->size_b) ? 2 : 3;
	turn = (piles->size_a >= piles->size_b) ? piles->size_b / n :
		piles->size_a / n;
	while (turn > 0)
	{
		last = piles->b[n];
			sleep(1);
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
			printf("n =  %d", n);
			printf("\n");
			printf("last %d", last);
			printf("\n");
			ft_push_it_babe(piles, flag, n);
		flag++;
		turn--;
	}
}

void			ft_merge_sort(t_struct *piles)
{
	int		min_a;
	int		n;

	while (piles->size_a > piles->sizemax / 2)
		ft_pb(piles);
	ft_sort_by_two(piles);
	n = 4;
	while (n <= piles->sizemax / 2)
	{
		ft_mergeation(piles, n);
		n *= 2;
	}
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
