/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <jdesmare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 10:50:38 by jdesmare          #+#    #+#             */
/*   Updated: 2017/02/02 08:48:44 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

static t_struct		*ft_init_temp(t_struct *piles, t_struct *temp)
{
	temp = ft_init_struct(piles->sizemax + 1);
	temp->push_swap = 1;
	temp->test = 1;
	ft_copy_pile_a(temp, piles);
	return (temp);
}

static int			ft_minimum(t_algos *algos)
{
	int		val;

	val = algos->insertion;
	if (val > algos->median_sort)
		val = algos->median_sort;
	if (val > algos->merge_sort)
		val = algos->merge_sort;
	return (val);
}

void				ft_push_swap(t_struct *piles)
{
	t_algos		*algos;
	t_struct	*temp;

	piles->push_swap = 1;
	algos = ft_memalloc(sizeof(t_algos));
	temp = ft_init_struct(piles->sizemax + 1);
	temp = ft_init_temp(piles, temp);
	ft_merge_sort(temp);
	algos->merge_sort = temp->moves;
	temp = ft_init_temp(piles, temp);
	ft_median_sort(temp);
	algos->median_sort = temp->moves;
	temp = ft_init_temp(piles, temp);
	ft_insertion(temp);
	algos->insertion = temp->moves;
	if (ft_minimum(algos) == algos->insertion)
		ft_insertion(piles);
	else if (ft_minimum(algos) == algos->merge_sort)
		ft_merge_sort(piles);
	else
		ft_median_sort(piles);
	ft_free_piles(&temp);
	free(algos);
}

int					main(int argc, char **argv)
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
