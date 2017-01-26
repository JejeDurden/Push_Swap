/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <jdesmare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 13:27:16 by jdesmare          #+#    #+#             */
/*   Updated: 2017/01/26 13:33:32 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

int		main(int argc, char **argv)
{
	t_struct *piles;
	int		i;

	i = 1;
	piles = ft_init_struct(argc);
	while (i < argc)
	{
		piles->a[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	ft_sort_rate(piles);
}
