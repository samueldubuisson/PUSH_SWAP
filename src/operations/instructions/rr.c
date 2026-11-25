/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   rr.c                                              :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/15 18:41:23 by username         #+#    #+#              */
/*   Updated: 2026/11/25 04:51:15 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_data *data)
{
	int	a;
	int	b;

	a = rotate(&data->stack_a);
	b = rotate(&data->stack_b);
	if (a || b)
	{
		data->stats.total_ops++;
		data->stats.count_rr++;
		if (!data->silent)
			write(1, "rr\n", 3);
	}
}
