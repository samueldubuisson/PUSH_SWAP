/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdubuiss <sdubuiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 17:56:21 by sdubuiss          #+#    #+#             */
/*   Updated: 2026/11/26 01:33:32 by sdubuiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_sort_adaptive(t_data *data, float disorder)
{
	if (disorder < 0.2)
	{
		data->stats.strategy = "simple";
		ft_sort_simple(data);
	}
	else if (disorder < 0.5)
	{
		data->stats.strategy = "medium";
		ft_sort_medium(data);
	}
	else
	{
		data->stats.strategy = "complex";
		ft_sort_complex(data);
	}
}

static int	ft_sort_small(t_data *data)
{
	int	size;

	size = ft_stack_size(data->stack_a);
	if (size <= 1)
		return (1);
	data->stats.strategy = "simple";
	if (size == 2)
		ft_sort_two(data);
	else if (size == 3)
		ft_sort_three(data);
	else if (size == 4)
		ft_sort_four(data);
	else if (size == 5)
		ft_sort_five(data);
	else
		return (0);
	return (1);
}

void	ft_sort_stack(t_data *data)
{
	data->stats.disorder = ft_compute_disorder(data->stack_a);
	if (data->stats.disorder == 0.00f)
		return ;
	if (ft_sort_small(data))
		return ;
	if (data->config.simple)
	{
		data->stats.strategy = "simple";
		ft_sort_simple(data);
	}
	else if (data->config.medium)
	{
		data->stats.strategy = "medium";
		ft_sort_medium(data);
	}
	else if (data->config.complex)
	{
		data->stats.strategy = "complex";
		ft_sort_complex(data);
	}
	else
		ft_sort_adaptive(data, data->stats.disorder);
}
