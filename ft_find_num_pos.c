/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_half_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <jdesmare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 10:00:47 by jdesmare          #+#    #+#             */
/*   Updated: 2017/02/01 17:01:07 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

int		ft_find_num_pos(int *tab, int num, int size)
{
	int		i;

	i = 0;
	while (tab[i] != num && i <= size)
		i++;
	if (i < size)
		return (i);
	else
		return (-1);
}
