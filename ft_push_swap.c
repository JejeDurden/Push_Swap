/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <jdesmare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 10:50:38 by jdesmare          #+#    #+#             */
/*   Updated: 2017/01/25 18:19:00 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	ft_push_swap(t_struct *piles)
{
	piles->push_swap = 1;
}

int		main(int argc, char **argv)
{
	int			i;
	int			error;
	t_struct	*piles;

	piles = ft_init_struct(argc);
	i = 1;
	error = 0;
	while (i < argc)
	{
		if (ft_valid_num(argv[i], argv, argc) == 1 &&
									ft_valid_int(argv[i]) == 1)
			piles->a[i - 1] = ft_atoi(argv[i]);
		else
			error = 1;
		i++;
	}
	if (error == 1 || argc < 2)
	{
		ft_putstr_fd("Error\n", 2);
		return (-1);
	}
	ft_push_swap(piles);
	return (0);
}
