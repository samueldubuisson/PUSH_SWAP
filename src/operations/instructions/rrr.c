/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdubuiss <sdubuiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 18:41:38 by username          #+#    #+#             */
/*   Updated: 2026/11/19 13:19:24 by sdubuiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_data *data)
{
	int	a;
	int	b;

	a = reverse_rotate(&data->stack_a);
	b = reverse_rotate(&data->stack_b);
	if (a || b)
	{
		data->stats.total_ops++;
		data->stats.count_rrr++;
		write(1, "rrr\n", 4);
	}
}
