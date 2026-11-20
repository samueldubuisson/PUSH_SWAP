/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdubuiss <sdubuiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 18:41:23 by sdubuiss          #+#    #+#             */
/*   Updated: 2026/11/19 13:17:43 by sdubuiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_data *data)
{
	int	a;
	int	b;

	a = rotate(&data->stack_a);
	b = rotate(&data->stack_b);
	if (a || b)
	{
		data->stats.total_ops++;
		data->stats.count_rr++;
		write(1, "rr\n", 3);
	}
}
