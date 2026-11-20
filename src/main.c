/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdubuiss <sdubuiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 13:36:21 by sdubuiss          #+#    #+#             */
/*   Updated: 2026/11/20 22:25:25 by sdubuiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_error(void)
{
	ft_putendl_fd("Error", 2);
	return (1);
}

static int	ft_parse_input(int argc, char **argv, t_data *data)
{
	char	***parse;
	char	***numbers;

	parse = ft_parse_arguments(argc - 1, argv + 1);
	if (!parse)
		return (ft_error());
	numbers = ft_parse_options(parse, &data->config);
	if (!numbers)
		return (free_parse(parse), ft_error());
	if (!ft_parse_numbers(numbers))
		return (free_parse(parse), ft_error());
	if (!ft_fill_stack(numbers, &data->stack_a))
		return (free_parse(parse), ft_stackclear(&data->stack_a), 1);
	free_parse(parse);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc <= 1)
		return (1);
	ft_init_struct(&data);
	if (ft_parse_input(argc, argv, &data))
		return (1);
	ft_sort_stack(&data);
	ft_print_benchmark(data);
	ft_stackclear(&data.stack_a);
	return (0);
}
