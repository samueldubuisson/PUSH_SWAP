/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_both.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdubuiss <sdubuiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 01:06:46 by sdubuiss          #+#    #+#             */
/*   Updated: 2026/11/23 01:32:09 by sdubuiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_execute_double_rotate(t_data *data, t_rotation *r)
{
	while (r->rotate_a > 0 && r->rotate_b > 0)
	{
		if (r->direction_a == ROTATE_UP)
			rr(data);
		else
			rrr(data);
		r->rotate_a--;
		r->rotate_b--;
	}
}

static void	ft_execute_remaining_a(t_data *data, t_rotation *r)
{
	while (r->rotate_a > 0)
	{
		if (r->direction_a == ROTATE_UP)
			ra(data);
		else
			rra(data);
		r->rotate_a--;
	}
}

static void	ft_execute_remaining_b(t_data *data, t_rotation *r)
{
	while (r->rotate_b > 0)
	{
		if (r->direction_b == ROTATE_UP)
			rb(data);
		else
			rrb(data);
		r->rotate_b--;
	}
}

void	ft_rotate_both(t_data *data, int pos_a, int pos_b)
{
	t_rotation	r;

	r = ft_calculate_rotation(data, pos_a, pos_b);
	if (r.direction_a == r.direction_b)
		ft_execute_double_rotate(data, &r);
	ft_execute_remaining_a(data, &r);
	ft_execute_remaining_b(data, &r);
}
