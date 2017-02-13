/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <jdesmare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 10:50:38 by jdesmare          #+#    #+#             */
/*   Updated: 2017/02/10 21:12:33 by jdesmare         ###   ########.fr       */
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

static void			ft_minimum(t_algos *algos, t_struct *piles)
{
	int		val;

	val = algos->insertion;
	if (val > algos->median_sort)
		val = algos->median_sort;
	if (val > algos->merge_sort)
		val = algos->merge_sort;
	if (val == algos->insertion)
		ft_insertion(piles);
	else if (val == algos->merge_sort)
		ft_merge_sort(piles);
	else
		ft_median_sort(piles);
}

void				ft_push_swap(t_struct *piles)
{
	t_algos		*algos;
	t_struct	*temp;

	piles->push_swap = 1;
	algos = ft_memalloc(sizeof(t_algos));
	temp = NULL;
	temp = ft_init_temp(piles, temp);
	ft_merge_sort(temp);
	algos->merge_sort = temp->moves;
	ft_free_piles(temp);
	free(temp);
	temp = ft_init_temp(piles, temp);
	ft_median_sort(temp);
	algos->median_sort = temp->moves;
	ft_free_piles(temp);
	free(temp);
	temp = ft_init_temp(piles, temp);
	ft_insertion(temp);
	algos->insertion = temp->moves;
	ft_free_piles(temp);
	free(temp);
	ft_minimum(algos, piles);
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
	ft_free_piles(piles);
	free(piles);
	return (0);
}
