/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdubuiss <sdubuiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 18:42:30 by username          #+#    #+#             */
/*   Updated: 2026/11/19 13:11:51 by sdubuiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_data *data)
{
	int	a;
	int	b;

	a = swap(&data->stack_a);
	b = swap(&data->stack_b);
	if (a || b)
	{
		data->stats.total_ops++;
		data->stats.count_ss++;
		write(1, "ss\n", 3);
	}
}
