/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <jdesmare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 10:50:38 by jdesmare          #+#    #+#             */
/*   Updated: 2017/01/30 20:15:53 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"
/*
static t_struct		*ft_init_temp(t_struct *piles, t_struct *temp)
{
	temp = ft_init_struct(piles->sizemax + 1);
	temp->push_swap = 1;
	temp->test = 1;
	ft_copy_pile_a(temp, piles);
	return (temp);
}
*/
int		ft_minimum(t_algos *algos)
{
	int		val;

	val = algos->insertion;
	if (val > algos->half_sort)
		val = algos->half_sort;
	if (val > algos->middle_sort)
		val = algos->middle_sort;
	if (val > algos->full_tab_sort)
		val = algos->full_tab_sort;
	if (val > algos->card_sort)
		val = algos->card_sort;
	return (val);
}

void	ft_push_swap(t_struct *piles)
{
//	t_algos		*algos;
//	t_struct	 *temp;

//	algos = ft_memalloc(sizeof(t_algos));
//	temp = ft_init_struct(piles->sizemax + 1);
	piles->push_swap = 1;
/*	temp = ft_init_temp(piles, temp);
	ft_full_tab_sort(temp);
	algos->full_tab_sort = temp->moves;
	temp = ft_init_temp(piles, temp);
	ft_half_sort(temp);
	algos->half_sort = temp->moves;
	temp = ft_init_temp(piles, temp);
	ft_card_sort(temp);
	algos->card_sort = temp->moves;
	temp = ft_init_temp(piles, temp);
	ft_middle_sort(temp);
	algos->middle_sort = temp->moves;
	algos->middle_sort = 50;
	temp = ft_init_temp(piles, temp);
	ft_insertion(temp);
	algos->insertion = temp->moves;
	if (ft_minimum(algos) == algos->insertion)
	{
		ft_insertion(piles);
		ft_putstr("insertion\n");
	}
	else if (ft_minimum(algos) == algos->half_sort)
	{
		ft_half_sort(piles);
		ft_putstr("half_sort\n");
	}
	else if (ft_minimum(algos) == algos->full_tab_sort)
	{
		ft_full_tab_sort(piles);
		ft_putstr("full_tab_sort\n");
	}
	else if (ft_minimum(algos) == algos->card_sort)
	{
		ft_card_sort(piles);
		ft_putstr("card_sort\n");
	}
	else
	{
		ft_middle_sort(piles);
		ft_putstr("middle_sort\n");
	}*/
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
