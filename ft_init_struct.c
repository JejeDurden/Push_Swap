/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <jdesmare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 13:51:21 by jdesmare          #+#    #+#             */
/*   Updated: 2017/01/25 18:06:30 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

t_struct	*ft_init_struct(int argc)
{
	t_struct	*piles;

	piles = ft_memalloc(sizeof(t_struct));
	piles->a = ft_memalloc(sizeof(int) * (argc - 1));
	piles->b = ft_memalloc(sizeof(int) * (argc - 1));
	piles->sizemax = argc - 1;
	piles->size_a = argc - 1;
	piles->size_b = 0;
	piles->push_swap = 0;
	return (piles);
}
