/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdubuiss <sdubuiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 18:40:52 by username          #+#    #+#             */
/*   Updated: 2026/11/19 13:15:48 by sdubuiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_data *data)
{
	if (reverse_rotate(&data->stack_a))
	{
		data->stats.total_ops++;
		data->stats.count_rra++;
		write(1, "rra\n", 4);
	}
}
