/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   pa.c                                              :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/15 18:39:29 by username         #+#    #+#              */
/*   Updated: 2026/11/25 04:19:11 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_data *data)
{
	if (push(&data->stack_b, &data->stack_a))
	{
		data->stats.total_ops++;
		data->stats.count_pa++;
		if (!data->silent)
			write(1, "pa\n", 3);
	}
}
