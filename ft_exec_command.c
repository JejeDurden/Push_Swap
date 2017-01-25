/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <jdesmare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 11:05:38 by jdesmare          #+#    #+#             */
/*   Updated: 2017/01/25 14:10:04 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	ft_exec_command(char *line, t_struct *piles)
{
	if (ft_strcmp(line, "sa") == 0)
		ft_sa(piles);
	else if (ft_strcmp(line, "sb") == 0)
		ft_sb(piles);
	else if (ft_strcmp(line, "ss") == 0)
		ft_ss(piles);
	else if (ft_strcmp(line, "pa") == 0)
		ft_pa(piles);
	else if (ft_strcmp(line, "pb") == 0)
		ft_pb(piles);
	else if (ft_strcmp(line, "ra") == 0)
		ft_ra(piles);
	else if (ft_strcmp(line, "rb") == 0)
		ft_rb(piles);
	else if (ft_strcmp(line, "rr") == 0)
		ft_rr(piles);
	else if (ft_strcmp(line, "rra") == 0)
		ft_rra(piles);
	else if (ft_strcmp(line, "rrb") == 0)
		ft_rrb(piles);
	else if (ft_strcmp(line, "rrr") == 0)
		ft_rrr(piles);
}
