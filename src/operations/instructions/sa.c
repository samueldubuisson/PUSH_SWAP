/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   sa.c                                              :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/15 18:39:03 by username         #+#    #+#              */
/*   Updated: 2026/11/25 04:21:32 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_data *data)
{
	if (swap(&data->stack_a))
	{
		data->stats.total_ops++;
		data->stats.count_sa++;
		if (!data->silent)
			write(1, "sa\n", 3);
	}
}
