/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insertion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <jdesmare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 15:36:46 by jdesmare          #+#    #+#             */
/*   Updated: 2017/01/28 20:06:17 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

int		ft_get_first_bug(int *tab, int size)
{
	int		i;
	int		bug;

	i = 1;
	bug = 0;
	while (i < size)
	{
		if (tab[i] < tab[i - 1])
		{
			bug = i;
			break ;
		}
		i++;
	}
	return (bug);
}

void	ft_insertion(t_struct *piles)
{
	int		i;
	int		max;
	int		first_bug;

	max = ft_ismax(piles->a, piles->size_a);
	while (ft_is_sorted(piles->a, piles->size_a) == 0)
	{
		first_bug = ft_get_first_bug(piles->a, piles->size_a);
		if (first_bug > piles->size_a / 2)
		{
			i = piles->size_a - first_bug;
			while (i-- >= 0)
				ft_rra(piles);
		}
		else
		{
			if (piles->a[0] == max)
				ft_ra(piles);
			else if (piles->a[1] < piles->a[0])
				ft_sa(piles);
			else
				ft_ra(piles);
		}
	}
}
