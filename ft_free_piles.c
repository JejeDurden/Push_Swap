/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_piles.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <jdesmare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 19:07:54 by jdesmare          #+#    #+#             */
/*   Updated: 2017/02/02 10:06:11 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	ft_free_piles(t_struct **piles)
{
	t_struct	*temp;

	temp = *piles;
	free(temp->a);
	free(temp->b);
}
