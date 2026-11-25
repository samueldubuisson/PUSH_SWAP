/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   pb.c                                              :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/15 18:39:48 by username         #+#    #+#              */
/*   Updated: 2026/11/25 04:18:56 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_data *data)
{
	if (push(&data->stack_a, &data->stack_b))
	{
		data->stats.total_ops++;
		data->stats.count_pb++;
		if (!data->silent)
			write(1, "pb\n", 3);
	}
}
