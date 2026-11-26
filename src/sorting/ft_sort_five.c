/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_five.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdubuiss <sdubuiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 00:05:10 by sdubuiss          #+#    #+#             */
/*   Updated: 2026/11/26 00:20:51 by sdubuiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_min(t_stack *stack)
{
	int	min;

	min = stack->value;
	while (stack)
	{
		if (stack->value < min)
			min = stack->value;
		stack = stack->next;
	}
	return (min);
}

void	ft_sort_two(t_data *data)
{
	if (data->stack_a->value > data->stack_a->next->value)
		sa(data);
}

void	ft_sort_three(t_data *data)
{
	int	a;
	int	b;
	int	c;

	a = data->stack_a->value;
	b = data->stack_a->next->value;
	c = data->stack_a->next->next->value;
	if (a > b && b < c && a < c)
		sa(data);
	else if (a > b && b > c)
	{
		sa(data);
		rra(data);
	}
	else if (a > b && b < c && a > c)
		ra(data);
	else if (a < b && b > c && a < c)
	{
		sa(data);
		ra(data);
	}
	else if (a < b && b > c && a > c)
		rra(data);
}

void	ft_sort_four(t_data *data)
{
	int	min;

	min = ft_find_min(data->stack_a);
	while (data->stack_a->value != min)
		ra(data);
	pb(data);
	ft_sort_three(data);
	pa(data);
}

void	ft_sort_five(t_data *data)
{
	int	min;

	min = ft_find_min(data->stack_a);
	while (data->stack_a->value != min)
		ra(data);
	pb(data);
	min = ft_find_min(data->stack_a);
	while (data->stack_a->value != min)
		ra(data);
	pb(data);
	ft_sort_three(data);
	pa(data);
	pa(data);
}
