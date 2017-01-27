/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <jdesmare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 10:50:38 by jdesmare          #+#    #+#             */
/*   Updated: 2017/01/27 20:20:19 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	ft_push_swap(t_struct *piles)
{
//	int		insertion;
//	int		half_sort;
//	int		merge_sort;
//	t_struct *temp;

	piles->push_swap = 1;
/*	temp = ft_init_struct(piles->sizemax + 1);
	temp->push_swap = 1;
	temp->test = 1;
	ft_copy_pile_a(temp, piles);
	ft_insertion(temp);
	insertion = temp->moves;
	temp = ft_init_struct(piles->sizemax + 1);
	temp->push_swap = 1;
	temp->test = 1;
	ft_copy_pile_a(temp, piles);
	ft_half_sort(temp);
	half_sort = temp->moves;
	temp = ft_init_struct(piles->sizemax + 1);
	temp->push_swap = 1;
	temp->test = 1;
	ft_copy_pile_a(temp, piles);
	ft_merge_sort(temp);
	merge_sort = temp->moves;*/
//	if (insertion < ft_smaller_size(half_sort, merge_sort))
//		ft_insertion(piles);
//	else if (merge_sort < half_sort)
//		ft_half_sort(piles);
//	else
		ft_merge_sort(piles);
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
