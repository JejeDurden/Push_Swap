/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <jdesmare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 15:36:09 by jdesmare          #+#    #+#             */
/*   Updated: 2017/01/25 17:36:14 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void		ft_move_up_a(t_struct *piles)
{
	int		i;

	piles->size_a++;
	i = piles->size_a - 1;
	while (i > 0)
	{
		piles->a[i] = piles->a[i - 1];
		i--;
	}
}

void		ft_move_up_b(t_struct *piles)
{
	int		i;

	piles->size_b++;
	i = piles->size_b - 1;
	while (i > 0)
	{
		piles->b[i] = piles->b[i - 1];
		i--;
	}
}

void		ft_move_down_a(t_struct *piles)
{
	int		i;

	i = 0;
	while (i < piles->size_a)
	{
		piles->a[i] = piles->a[i + 1];
		i++;
	}
	piles->size_a--;
}

void		ft_move_down_b(t_struct *piles)
{
	int		i;

	i = 0;
	while (i < piles->size_b)
	{
		piles->b[i] = piles->b[i + 1];
		i++;
	}
	piles->size_b--;
}
