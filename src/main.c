/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdubuiss <sdubuiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 13:36:21 by sdubuiss          #+#    #+#             */
/*   Updated: 2026/11/25 03:50:53 by sdubuiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc <= 1)
		return (1);
	ft_init_struct(&data);
	if (ft_parse_input(argc, argv, &data))
		return (1);
	ft_sort_stack(&data);
	if (data.config.bench)
		ft_print_benchmark(data);
	ft_stackclear(&data.stack_a);
	ft_stackclear(&data.stack_b);
	return (0);
}
