/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdubuiss <sdubuiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 13:36:21 by sdubuiss          #+#    #+#             */
/*   Updated: 2026/11/17 13:38:09 by sdubuiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_data	data;
	char	***parse;
	char	***numbers;
	t_stack	*stack_a;

	stack_a = NULL;
	if (argc <= 1)
		return (1);
	parse = ft_parse_arguments(argc - 1, argv + 1);
	if (!parse)
		return (1);
	ft_init_struct(&data);
	numbers = ft_parse_options(parse, &data.config);
	if (!numbers)
	{
		free_parse(parse);
		return (1);
	}
	if (!ft_parse_numbers(numbers))
	{
		ft_putendl_fd("Error", 2);
		free_parse(parse);
		return (1);
	}
	if (!ft_fill_stack(numbers, &stack_a))
	{
		free_parse(parse);
		ft_stackclear(&stack_a);
		return (1);
	}
	t_stack	*tmp;
	tmp = stack_a;
	while (tmp)
	{
		ft_printf("%d", tmp->value);
		tmp = tmp->next;
	}
	free_parse(parse);
	ft_stackclear(&stack_a);
	return (0);
}
