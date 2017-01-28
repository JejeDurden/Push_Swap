/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_yolo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <jdesmare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 20:02:20 by jdesmare          #+#    #+#             */
/*   Updated: 2017/01/28 20:25:19 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	ft_yolo(t_struct *piles)
{
	while (piles->size_a > 0)
		ft_pb(piles);
	while (ft_is_finished(piles) == 0)
	{
		ft_pa(piles);
		ft_insertion(piles);
	}
}
