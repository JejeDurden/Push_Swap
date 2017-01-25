/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <jdesmare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 13:44:06 by jdesmare          #+#    #+#             */
/*   Updated: 2017/01/25 16:50:27 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

int		ft_is_sorted(t_struct *piles)
{
	int		i;

	i = 0;
	if (piles->b[0] == 0 && piles->size_b == 0)
	{
		while (i + 1 < piles->sizemax)
		{
			if (piles->a[i] >= piles->a[i + 1])
				return (0);
			i++;
		}
		return (1);
	}
	else
		return (0);
}
