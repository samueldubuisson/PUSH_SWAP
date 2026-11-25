/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   rb.c                                              :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/15 18:40:30 by username         #+#    #+#              */
/*   Updated: 2026/11/25 04:19:32 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_data *data)
{
	if (rotate(&data->stack_b))
	{
		data->stats.total_ops++;
		data->stats.count_rb++;
		if (!data->silent)
			write(1, "rb\n", 3);
	}
}
