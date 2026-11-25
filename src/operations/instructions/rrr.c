/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   rrr.c                                             :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/15 18:41:38 by username         #+#    #+#              */
/*   Updated: 2026/11/25 04:51:10 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_data *data)
{
	int	a;
	int	b;

	a = reverse_rotate(&data->stack_a);
	b = reverse_rotate(&data->stack_b);
	if (a || b)
	{
		data->stats.total_ops++;
		data->stats.count_rrr++;
		if (!data->silent)
			write(1, "rrr\n", 4);
	}
}
