/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_piles.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <jdesmare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 19:40:22 by jdesmare          #+#    #+#             */
/*   Updated: 2017/01/26 19:43:33 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	ft_copy_pile_a(t_struct *temp, t_struct *piles)
{
	int		i;

	i = 0;
	while (i < piles->sizemax)
	{
		temp->a[i] = piles->a[i];
		i++;
	}
}
