/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_middle_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <jdesmare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 20:25:27 by jdesmare          #+#    #+#             */
/*   Updated: 2017/02/01 15:24:39 by jdesmare         ###   ########.fr       */
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
	moves = 0;
	while (tab[size] != n1 && tab[size] != n2)
	{
		size--;
		moves++;
	}
	return ((val1 >= moves + 1) ? tab[size] : i);
}

static void		ft_find_push(t_struct *piles, t_struct *temp, int up_pos)
{
	int			down;
	int			up;
	int			down_pos;

	down_pos = 2;
	while (piles->size_b > 0)
	{
		down = temp->a[(temp->size_a - 1) / 2 - down_pos];
		up = temp->a[(temp->size_a - 1) / 2 + up_pos];
		if (ft_closest(piles->b, piles->size_b, down, up)
				== down && down_pos <= temp->size_a - 1)
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

void	ft_middle_sort(t_struct *piles)
{
	int			med;
	int			up;
	int			up2;
	int			down;
	t_struct	*temp;

	if (piles->size_a > 3)
	{
		temp = ft_init_struct(piles->sizemax + 1);
		ft_copy_pile_a(temp, piles);
		ft_sort_temp(temp->a, temp->size_a);
		med = temp->a[(temp->size_a - 1) / 2];
		up = temp->a[(temp->size_a - 1) / 2 + 1];
		down = temp->a[(temp->size_a - 1) / 2 - 1];
		up2 = temp->a[(temp->size_a - 1) / 2 + 2];
		while (piles->size_a > 4)
		{
			if (piles->a[0] != med && piles->a[0] != down
					&& piles->a[0] != up && piles->a[0] != up2)
				ft_pb(piles);
			else
				ft_ra(piles);
		}
		ft_insertion(piles);
		ft_find_push(piles, temp, 3);
	}
	else
		piles->moves = 70;
}
