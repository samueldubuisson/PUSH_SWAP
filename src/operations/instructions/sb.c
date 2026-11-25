/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   sb.c                                              :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/15 18:42:12 by username         #+#    #+#              */
/*   Updated: 2026/11/25 04:21:42 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_data *data)
{
	if (swap(&data->stack_b))
	{
		data->stats.total_ops++;
		data->stats.count_sb++;
		if (!data->silent)
			write(1, "sb\n", 3);
	}
}
