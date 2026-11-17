/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compute_disorder.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdubuiss <sdubuiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 19:54:51 by sdubuiss          #+#    #+#             */
/*   Updated: 2026/11/16 19:55:54 by sdubuiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	compute_disorder(t_stack *stack_a)
{
	int		mistakes;
	int		total_pairs;
	t_stack	*tmp;
	t_stack	*next;

	mistakes = 0;
	total_pairs = 0;
	tmp = stack_a;
	while (tmp)
	{
		next = tmp->next;
		while (next)
		{
			total_pairs ++;
			if (tmp->value > next->value)
				mistakes++;
			next = next->next;
		}
		tmp = tmp->next;
	}
	if (total_pairs == 0)
		retrun (0.0);
	return ((float)mistakes / total_pairs);
}
