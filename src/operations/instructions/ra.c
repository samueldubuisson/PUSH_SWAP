/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ra.c                                              :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/15 18:40:07 by username         #+#    #+#              */
/*   Updated: 2026/11/25 04:19:21 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_data *data)
{
	if (rotate(&data->stack_a))
	{
		data->stats.total_ops++;
		data->stats.count_ra++;
		if (!data->silent)
			write(1, "ra\n", 3);
	}
}
