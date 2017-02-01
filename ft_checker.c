/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <jdesmare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 18:31:28 by jdesmare          #+#    #+#             */
/*   Updated: 2017/02/01 17:11:33 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	ft_checker(t_struct *piles)
{
	char	*line;

	while (get_next_line(0, &line) > 0)
	{
		if (ft_exec_command(line, piles) == 0)
		{
			piles->error = 1;
			ft_putstr_fd("Error\n", 2);
			break ;
		}
		free(line);
	}
	if (piles->error == 0)
	{
		if (ft_is_finished(piles) == 1)
			ft_putstr("OK\n");
		else
			ft_putstr("KO\n");
	}
}

int		main(int argc, char **argv)
{
	int			i;
	t_struct	*piles;

	piles = ft_init_struct(argc);
	i = 0;
	piles->error = 0;
	if (argc < 2)
		return (0);
	while (i++ < argc)
	{
		if (ft_valid_num(argv[i], argv, argc) == 1 &&
									ft_valid_int(argv[i]) == 1)
			piles->a[i - 1] = ft_atoi(argv[i]);
		else
			piles->error = 1;
	}
	if (piles->error == 1)
	{
		ft_putstr_fd("Error\n", 2);
		return (-1);
	}
	ft_checker(piles);
	if (piles)
		ft_free_piles(&piles);
	return (0);
}
