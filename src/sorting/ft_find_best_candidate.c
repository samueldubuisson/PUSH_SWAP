/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_best_candidate.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdubuiss <sdubuiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 19:19:58 by sdubuiss          #+#    #+#             */
/*   Updated: 2026/11/23 01:05:59 by sdubuiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_to_position_a(t_data *data, int pos)
{
	int	size;
	int	rotate;

	size = ft_stack_size(data->stack_a);
	if (pos > size / 2)
	{
		rotate = size - pos;
		while (rotate--)
			rra(data);
	}
	else
	{
		rotate = pos;
		while (rotate--)
			ra(data);
	}
}

static int	ft_calculate_rotation_cost(int size, int pos)
{
	if (pos > size / 2)
		return (size - pos);
	return (pos);
}

static int	ft_calculate_total_cost(t_data *data, int nb, int pos_a)
{
	int	rotate_a;
	int	rotate_b;
	int	size_a;
	int	size_b;
	int	pos_b;

	size_a = ft_stack_size(data->stack_a);
	size_b = ft_stack_size(data->stack_b);
	rotate_a = ft_calculate_rotation_cost(size_a, pos_a);
	pos_b = ft_find_insert_position(data->stack_b, nb);
	rotate_b = ft_calculate_rotation_cost(size_b, pos_b);
	return (rotate_a + rotate_b);
}

t_candidate	ft_find_best_candidate(t_data *data)
{
	t_candidate	c;
	t_stack		*tmp;

	tmp = data->stack_a;
	c.best_pos = 0;
	c.i = 0;
	c.value = tmp->value;
	c.best_cost = ft_calculate_total_cost(data, tmp->value, 0);
	while (tmp)
	{
		c.current_cost = ft_calculate_total_cost(data, tmp->value, c.i);
		if (c.current_cost < c.best_cost)
		{
			c.best_cost = c.current_cost;
			c.best_pos = c.i;
			c.value = tmp->value;
		}
		tmp = tmp->next;
		c.i++;
	}
	return (c);
}
