/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdubuiss <sdubuiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 12:14:22 by sdubuiss          #+#    #+#             */
/*   Updated: 2026/11/17 12:14:36 by sdubuiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_fill_stack(char ***parse, t_stack **stack_a)
{
	int		a;
	int		i;
	int		j;
	t_stack	*new;

	i = 0;
	while (parse[i])
	{
		j = 0;
		while (parse[i][j])
		{
			a = ft_atoi(parse[i][j]);
			new = ft_stack_new(a);
			if (!new)
				return (0);
			ft_stackadd_back(stack_a, new);
			j++;
		}
		i++;
	}
	return (1);
}
