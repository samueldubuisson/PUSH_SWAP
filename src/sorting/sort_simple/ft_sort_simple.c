/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_sort_simple.c                                   :+:      :+:    :+:   */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/19 22:08:12 by username         #+#    #+#              */
/*   Updated: 2026/11/23 01:37:10 by sdubuiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_insert_position(t_stack *stack, int value)
{
	t_stack	*current;
	t_stack	*next;
	int		i;
	int		size;

	size = ft_stack_size(stack);
	current = stack;
	i = 0;
	while (i < size)
	{
		next = current->next;
		if (!next)
			next = stack;
		if (current->value > value && value > next->value)
			return (i + 1);
		if (current->value < next->value
			&& (value < current->value || value > next->value))
			return ((i + 1) % size);
		current = current->next;
		i++;
	}
	return (0);
}

static void	ft_rotate_to_position_b(t_data *data, int pos)
{
	int	size;
	int	rotate;

	size = ft_stack_size(data->stack_b);
	if (pos > size / 2)
	{
		rotate = size - pos;
		while (rotate--)
			rrb(data);
	}
	else
	{
		rotate = pos;
		while (rotate--)
			rb(data);
	}
}

static void	ft_rotate_max_to_top(t_data *data)
{
	int		i;
	int		pos;
	int		max;
	t_stack	*tmp;

	i = 0;
	pos = 0;
	max = data->stack_b->value;
	tmp = data->stack_b;
	while (tmp)
	{
		if (tmp->value > max)
		{
			max = tmp->value;
			pos = i;
		}
		i++;
		tmp = tmp->next;
	}
	ft_rotate_to_position_b(data, pos);
}

void	ft_sort_simple(t_data *data)
{
	int			pos_b;
	t_candidate	c;

	pb(data);
	pb(data);
	if (data->stack_b->value < data->stack_b->next->value)
		sb(data);
	while (data->stack_a)
	{
		c = ft_find_best_candidate(data);
		pos_b = ft_find_insert_position(data->stack_b, c.value);
		ft_rotate_both(data, c.best_pos, pos_b);
		pb(data);
	}
	ft_rotate_max_to_top(data);
	while (data->stack_b)
		pa(data);
}
