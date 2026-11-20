/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdubuiss <sdubuiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 18:39:48 by username          #+#    #+#             */
/*   Updated: 2026/11/19 13:14:38 by sdubuiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_data *data)
{
	if (push(&data->stack_a, &data->stack_b))
	{
		data->stats.total_ops++;
		data->stats.count_pb++;
		write(1, "pb\n", 3);
	}
}
