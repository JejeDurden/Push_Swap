/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <jdesmare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 10:49:29 by jdesmare          #+#    #+#             */
/*   Updated: 2017/02/11 10:34:38 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

int		ft_valid_int(char *argv)
{
	long long int	nb;

	if (ft_strlen(argv) > 11)
		return (0);
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

	i = -1;
	flag = 0;
	while (++i < n)
	{
		if (ft_strcmp(argv, tabstr[i]) == 0)
			flag++;
	}
	if (flag > 1)
		return (0);
	else if (!ft_isdigit(argv[0]) && argv[0] != '-' && argv[0] != '+')
		return (0);
	else if ((argv[0] == '-' || argv[0] == '+') && !ft_isdigit(argv[1]))
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
