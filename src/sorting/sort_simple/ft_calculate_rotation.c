/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculate_rotation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdubuiss <sdubuiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 01:30:04 by sdubuiss          #+#    #+#             */
/*   Updated: 2026/11/23 01:31:41 by sdubuiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_set_rotation(int size, int pos, int *rotate, int *direction)
{
	if (pos > size / 2)
	{
		*rotate = size - pos;
		*direction = ROTATE_DOWN;
	}
	else
	{
		*rotate = pos;
		*direction = ROTATE_UP;
	}
}

t_rotation	ft_calculate_rotation(t_data *data, int pos_a, int pos_b)
{
	t_rotation	r;

	r.size_a = ft_stack_size(data->stack_a);
	r.size_b = ft_stack_size(data->stack_b);
	ft_set_rotation(r.size_a, pos_a, &r.rotate_a, &r.direction_a);
	ft_set_rotation(r.size_b, pos_b, &r.rotate_b, &r.direction_b);
	return (r);
}
