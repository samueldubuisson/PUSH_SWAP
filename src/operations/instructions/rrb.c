/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdubuiss <sdubuiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 18:41:07 by username          #+#    #+#             */
/*   Updated: 2026/11/19 12:59:35 by sdubuiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrb(t_data *data)
{
	if (reverse_rotate(&data->stack_b))
	{
		data->stats.total_ops++;
		data->stats.count_rrb++;
		write(1, "rrb\n", 4);
	}
}
