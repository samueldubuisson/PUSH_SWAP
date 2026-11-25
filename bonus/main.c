/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdubuiss <sdubuiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 01:58:31 by sdubuiss          #+#    #+#             */
/*   Updated: 2026/11/25 04:17:34 by sdubuiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char **argv)
{
	t_data	data;
	int		result;

	if (argc <= 1)
		return (1);
	ft_init_struct(&data);
	data.silent = 1;
	if (ft_parse_input(argc, argv, &data))
		return (1);
	result = ft_checker(&data);
	if (result == -1)
	{
		ft_stackclear(&data.stack_a);
		ft_stackclear(&data.stack_b);
		return (1);
	}
	if (ft_check_sorted(data.stack_a, data.stack_b))
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	ft_stackclear(&data.stack_a);
	ft_stackclear(&data.stack_b);
	return (0);
}
