/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ss.c                                              :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/15 18:42:30 by username         #+#    #+#              */
/*   Updated: 2026/11/25 04:23:13 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_data *data)
{
	int	a;
	int	b;

	a = swap(&data->stack_a);
	b = swap(&data->stack_b);
	if (a || b)
	{
		data->stats.total_ops++;
		data->stats.count_ss++;
		if (!data->silent)
			write(1, "ss\n", 3);
	}
}
