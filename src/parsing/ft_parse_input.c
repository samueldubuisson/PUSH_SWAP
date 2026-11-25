/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdubuiss <sdubuiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 03:49:55 by sdubuiss          #+#    #+#             */
/*   Updated: 2026/11/25 03:50:07 by sdubuiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_error(void)
{
	ft_putendl_fd("Error", 2);
	return (1);
}

int	ft_parse_input(int argc, char **argv, t_data *data)
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
