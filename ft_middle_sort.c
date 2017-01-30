/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_middle_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <jdesmare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 20:25:27 by jdesmare          #+#    #+#             */
/*   Updated: 2017/01/30 16:05:54 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

static void		ft_push_nb(t_struct *piles, int nb, int nb_pos)
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

static int		ft_closest(int *tab, int size, int n1, int n2)
{
	int		moves;
	int		i;
	int		closest;
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
	closest = tab[i];
	val1 = moves;
	moves = 0;
	i = size;
	while (tab[i] != n1 && tab[i] != n2)
	{
		i--;
		moves++;
	}
	if (val1 >= moves + 1)
		return (tab[i]);
	else
		return (closest);
}

static void		ft_find_and_push(t_struct *piles, t_struct *temp)
{
	int			first_down;
	int			first_up;
	int			first_down_pos;
	int			first_up_pos;

	first_down_pos = 2;
	first_up_pos = 3;
	while (piles->size_b > 0)
	{
		first_down = temp->a[(temp->size_a - 1) / 2 - first_down_pos];
		first_up = temp->a[(temp->size_a - 1) / 2 + first_up_pos];
		if (ft_closest(piles->b, piles->size_b, first_down, first_up) == first_down && first_down_pos <= temp->size_a - 1)
		{
			if (ft_find_num_pos(piles->b, first_down, piles->size_b) != -1)
				ft_push_nb(piles, first_down, ft_find_num_pos(piles->b, first_down, piles->size_b));
			first_down_pos++;
		}
		else
		{
			if (ft_find_num_pos(piles->b, first_up, piles->size_b) != -1)
			{
				ft_push_nb(piles, first_up, ft_find_num_pos(piles->b, first_up, piles->size_b));
				ft_ra(piles);
			}
			first_up_pos++;
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

	temp = ft_init_struct(piles->sizemax + 1);
	ft_copy_pile_a(temp, piles);
	ft_sort_temp(temp->a, temp->size_a);
	med = temp->a[(temp->size_a - 1) / 2];
	up = temp->a[(temp->size_a - 1) / 2 + 1];
	down = temp->a[(temp->size_a - 1) / 2 - 1];
	up2 = temp->a[(temp->size_a - 1) / 2 + 2];
	while (piles->size_a > 4)
	{
		if (piles->a[0] != med && piles->a[0] != down && piles->a[0] != up && piles->a[0] != up2)
			ft_pb(piles);
		else
			ft_ra(piles);
	}
	ft_insertion(piles);
	ft_find_and_push(piles, temp);
}
