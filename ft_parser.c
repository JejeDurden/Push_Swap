/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <jdesmare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 10:49:29 by jdesmare          #+#    #+#             */
/*   Updated: 2017/01/24 19:44:51 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"
}

int		ft_valid_int(char *argv)
{
	long long int	nb;

	nb = ft_atol(argv);
	if (nb <= INT_MAX && nb >= INT_MIN)
		return (1);
	else
		return (0);
}

int		ft_valid_num(char *argv, char **tabstr, int n)
{
	int		i;
	int		flag;

	i = 0;
	flag = 0;
	while (i < n)
	{
		if (ft_strcmp(argv, tabstr[i]) == 0)
			flag++;
		i++;
	}
	if (flag > 1)
		return (0);
	else if (!ft_isdigit(argv[0]) && argv[0] != '-' && argv[0] != '+')
		return (0);
	else
	{
		i = 1;
		while (argv[i] && ft_isdigit(argv[i]))
			i++;
		if (argv[i] != '\0')
			return (0);
		return (1);
	}
}

int		main(int argc, char **argv)
{
	int		*tab;
	int		i;
	int		error;

	tab = ft_memalloc(sizeof(int) * (argc - 1));
	i = 1;
	error = 0;
	while (i < argc)
	{
		if (ft_valid_num(argv[i], argv, argc) == 1 &&
									ft_valid_int(argv[i]) == 1)
			tab[argc - i] = ft_atoi(argv[i]);
		else
			error = 1;
		i++;
	}
	if (error == 1 || argc < 2)
	{
		ft_putstr_fd("Error\n", 2);
		return (-1);
	}
	ft_checker(tab);
	return (0);
}
