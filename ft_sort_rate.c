/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_rate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <jdesmare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 13:17:25 by jdesmare          #+#    #+#             */
/*   Updated: 2017/01/26 17:18:02 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

int		ft_sort_rate(t_struct *piles)
{
	float	rate;
	int		i;

	rate = 0.0;
	i = 0;
	while (i <= piles->sizemax)
	{
		if (piles->a[i] < piles->a[i + 1])
			rate += 1.0;
		i++;
	}
	if (piles->sizemax > 2)
		rate += 1.0;
	rate = (rate / (piles->sizemax) * 100);
	return ((int)rate);
}
