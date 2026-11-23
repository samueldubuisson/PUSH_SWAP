/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdubuiss <sdubuiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 17:56:21 by sdubuiss          #+#    #+#             */
/*   Updated: 2026/11/21 18:01:21 by sdubuiss         ###   ########.fr       */
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

void	ft_sort_stack(t_data *data)
{
	if (!data->stack_a || !data->stack_a->next)
		return ;
	data->stats.disorder = ft_compute_disorder(data->stack_a);
	if (data->stats.disorder == 0.00f)
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
