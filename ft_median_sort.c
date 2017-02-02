/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_median_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <jdesmare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 20:25:27 by jdesmare          #+#    #+#             */
/*   Updated: 2017/02/02 16:19:57 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

static void		ft_push_nb(t_struct *piles, int nb, int nb_pos)
{
	if (nb_pos != -1)
	{
		if (nb_pos > (piles->size_b - 1) / 2)
		{
			while (piles->b[0] != nb)
				ft_rrb(piles);
			ft_pa(piles);
		}
		else
		{
			while (piles->b[0] != nb)
				ft_rb(piles);
			ft_pa(piles);
		}
	}
}

static int		ft_closest(int *tab, int size, int n1, int n2)
{
	int		moves;
	int		i;
	int		val1;

	if (n1 == 0)
		return (n2);
	if (n2 == 0)
		return (n1);
	moves = 0;
	i = 0;
	while (tab[i] != n1 && tab[i] != n2)
	{
		i++;
		moves++;
	}
	i = tab[i];
	val1 = moves;
	moves = 1;
	while (tab[size] != n1 && tab[size] != n2)
	{
		size--;
		moves++;
	}
	return ((val1 >= moves) ? tab[size] : i);
}

static void		ft_find_push(t_struct *piles, t_struct *temp, int up_pos)
{
	int		down;
	int		up;
	int		down_pos;

	down_pos = 2;
	while (piles->size_b > 0)
	{
		down = temp->a[(temp->size_a - 1) / 2 - down_pos];
		up = temp->a[(temp->size_a - 1) / 2 + up_pos];
		if (ft_closest(piles->b, piles->size_b - 1, down, up)
				== down && down_pos <= temp->size_a)
		{
			ft_push_nb(piles, down, ft_find_num_pos(piles->b,
						down, piles->size_b));
			down_pos++;
		}
		else
		{
			ft_push_nb(piles, up, ft_find_num_pos(piles->b, up, piles->size_b));
			ft_ra(piles);
			up_pos++;
		}
	}
}

static void		ft_sort_temp(int *tab, int size)
{
	int		i;

	i = 0;
	while (ft_is_sorted(tab, size) == 0)
	{
		if (tab[i] > tab[i + 1])
		{
			ft_swap(&tab[i], &tab[i + 1]);
			i = -1;
		}
		i++;
	}
}

void			ft_median_sort(t_struct *piles)
{
	t_struct	*temp;
	t_num		*nums;

	if (piles->size_a > 3 && piles->size_a < 120 && piles->size_a != 7)
	{
		nums = ft_memalloc(sizeof(t_num));
		temp = ft_init_struct(piles->sizemax + 1);
		ft_copy_pile_a(temp, piles);
		ft_sort_temp(temp->a, temp->size_a);
		nums->med = temp->a[(temp->size_a - 1) / 2];
		nums->up = temp->a[(temp->size_a - 1) / 2 + 1];
		nums->down = temp->a[(temp->size_a - 1) / 2 - 1];
		ft_split_piles(piles, temp, nums);
		ft_insertion(piles);
		ft_find_push(piles, temp, 2);
		free(nums);
		ft_free_piles(&temp);
		free(temp);
	}
	else
		piles->moves = 70000;
}
