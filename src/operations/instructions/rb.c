/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdubuiss <sdubuiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 18:40:30 by username          #+#    #+#             */
/*   Updated: 2026/11/19 13:15:23 by sdubuiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_data *data)
{
	if (rotate(&data->stack_b))
	{
		data->stats.total_ops++;
		data->stats.count_rb++;
		write(1, "rb\n", 3);
	}
}
