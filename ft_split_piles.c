/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_piles.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <jdesmare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 08:57:19 by jdesmare          #+#    #+#             */
/*   Updated: 2017/02/10 20:22:53 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void		ft_split_piles(t_struct *piles, t_struct *temp, t_num *nums)
{
	while (piles->size_a > (piles->sizemax / 2) + 2)
	{
		if ((piles->a[0] < temp->a[(temp->size_a) / 4]
					|| piles->a[0] > temp->a[((temp->size_a) / 4) * 3]))
			ft_pb(piles);
		else
			ft_ra(piles);
	}
	while (piles->size_a > 3)
	{
		if (piles->a[0] < nums->down || piles->a[0] > nums->up)
			ft_pb(piles);
		else
			ft_ra(piles);
	}
}
