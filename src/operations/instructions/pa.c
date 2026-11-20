/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdubuiss <sdubuiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 18:39:29 by username          #+#    #+#             */
/*   Updated: 2026/11/19 12:46:31 by sdubuiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_data *data)
{
	if (push(&data->stack_b, &data->stack_a))
	{
		data->stats.total_ops++;
		data->stats.count_pa++;
		write(1, "pa\n", 3);
	}
}
