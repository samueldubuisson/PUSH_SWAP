/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_benchmark.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdubuiss <sdubuiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 13:37:41 by sdubuiss          #+#    #+#             */
/*   Updated: 2026/11/20 19:04:22 by sdubuiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_stat(char *name, int value)
{
	ft_putstr_fd(name, 2);
	ft_putnbr_fd(value, 2);
}

static void	print_disorder(float disorder)
{
	int	value;

	value = (int)(disorder * 10000 + 0.5);
	ft_putstr_fd("[bench] disorder: ", 2);
	ft_putnbr_fd(value / 100, 2);
	ft_putchar_fd('.', 2);
	if (value % 100 < 10)
		ft_putchar_fd('0', 2);
	ft_putnbr_fd(value % 100, 2);
	ft_putendl_fd("%", 2);
}

static void	print_strategy(t_data data)
{
	if (data.config.adaptive)
	{
		ft_putstr_fd("[bench] strategy: adaptive / ", 2);
		if (ft_strcmp(data.stats.strategy, "simple") == 0)
			ft_putendl_fd("O(n²)", 2);
		else if (ft_strcmp(data.stats.strategy, "medium") == 0)
			ft_putendl_fd("O(n √n)", 2);
		else if (ft_strcmp(data.stats.strategy, "complex") == 0)
			ft_putendl_fd("O(n log n)", 2);
	}
	else
	{
		ft_putstr_fd("[bench] strategy: ", 2);
		ft_putendl_fd(data.stats.strategy, 2);
	}
}

void	ft_print_benchmark(t_data data)
{
	print_disorder(data.stats.disorder);
	print_strategy(data);
	print_stat("[bench] total_ops: ", data.stats.total_ops);
	ft_putendl_fd("", 2);
	print_stat("[bench] sa: ", data.stats.count_sa);
	print_stat(" sb: ", data.stats.count_sb);
	print_stat(" ss: ", data.stats.count_ss);
	print_stat(" pa: ", data.stats.count_pa);
	print_stat(" pb: ", data.stats.count_pb);
	print_stat(" ra: ", data.stats.count_ra);
	print_stat(" rb: ", data.stats.count_rb);
	print_stat(" rr: ", data.stats.count_rr);
	print_stat(" rra: ", data.stats.count_rra);
	print_stat(" rrb: ", data.stats.count_rrb);
	print_stat(" rrr: ", data.stats.count_rrr);
	ft_putendl_fd("", 2);
}
