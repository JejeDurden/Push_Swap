/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <jdesmare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 18:31:28 by jdesmare          #+#    #+#             */
/*   Updated: 2017/01/25 17:59:41 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	ft_checker(t_struct *piles)
{
	char	*line;
	int		i;

	while (get_next_line(0, &line) > 0)
	{
		ft_exec_command(line, piles);
		free(line);
	}
	if (ft_is_sorted(piles) == 1)
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
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
	ft_checker(piles);
	return (0);
}
