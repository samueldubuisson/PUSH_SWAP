/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   rra.c                                             :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/15 18:40:52 by username         #+#    #+#              */
/*   Updated: 2026/11/25 04:51:00 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_data *data)
{
	if (reverse_rotate(&data->stack_a))
	{
		data->stats.total_ops++;
		data->stats.count_rra++;
		if (!data->silent)
			write(1, "rra\n", 4);
	}
}
