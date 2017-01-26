/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <jdesmare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 10:50:38 by jdesmare          #+#    #+#             */
/*   Updated: 2017/01/26 19:47:55 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	ft_push_swap(t_struct *piles)
{
	int		insertion;
	int		merge;
	t_struct *temp;

	temp = ft_init_struct(piles->sizemax + 1);
	ft_copy_pile_a(temp, piles);
	piles->push_swap = 1;
	piles->test = 1;
	ft_insertion(temp);
	insertion = piles->moves;
	piles->moves = 150;
//	ft_merge(piles);
	merge = piles->moves;
	piles->test = 0;
//	if (insertion > merge)
//		ft_merge(piles);
//	else
	ft_insertion(piles);
}

int		main(int argc, char **argv)
{
	int			i;
	t_struct	*piles;

	piles = ft_init_struct(argc);
	i = 1;
	piles->error = 0;
	while (i < argc)
	{
		if (ft_valid_num(argv[i], argv, argc) == 1 &&
									ft_valid_int(argv[i]) == 1)
			piles->a[i - 1] = ft_atoi(argv[i]);
		else
			piles->error = 1;
		i++;
	}
	if (piles->error == 1)
	{
		ft_putstr_fd("Error\n", 2);
		return (-1);
	}
	ft_push_swap(piles);
	if (piles)
		ft_free_piles(&piles);
	return (0);
}
