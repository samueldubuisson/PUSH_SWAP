/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdubuiss <sdubuiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 18:42:12 by username          #+#    #+#             */
/*   Updated: 2026/11/19 13:08:02 by sdubuiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_data *data)
{
	if (swap(&data->stack_b))
	{
		data->stats.total_ops++;
		data->stats.count_sb++;
		write(1, "sb\n", 3);
	}
}
