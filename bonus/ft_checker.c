/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdubuiss <sdubuiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 22:32:00 by sdubuiss          #+#    #+#             */
/*   Updated: 2026/11/25 04:00:50 by sdubuiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	ft_execute_instruction(char *order, t_data *data)
{
	if (!ft_strcmp(order, "sa\n"))
		sa(data);
	else if (!ft_strcmp(order, "sb\n"))
		sb(data);
	else if (!ft_strcmp(order, "ss\n"))
		ss(data);
	else if (!ft_strcmp(order, "pa\n"))
		pa(data);
	else if (!ft_strcmp(order, "pb\n"))
		pb(data);
	else if (!ft_strcmp(order, "ra\n"))
		ra(data);
	else if (!ft_strcmp(order, "rb\n"))
		rb(data);
	else if (!ft_strcmp(order, "rra\n"))
		rra(data);
	else if (!ft_strcmp(order, "rrb\n"))
		rrb(data);
	else if (!ft_strcmp(order, "rr\n"))
		rr(data);
	else if (!ft_strcmp(order, "rrr\n"))
		rrr(data);
	else
		return (-1);
	return (0);
}

int	ft_checker(t_data *data)
{
	char	*order;

	order = get_next_line(STDIN_FILENO);
	while (order)
	{
		if (ft_execute_instruction(order, data) == -1)
		{
			free(order);
			return (ft_putendl_fd("Error", 2), -1);
		}
		free(order);
		order = get_next_line(STDIN_FILENO);
	}
	return (0);
}
