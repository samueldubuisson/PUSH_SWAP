/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdubuiss <sdubuiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 18:41:38 by sdubuiss          #+#    #+#             */
/*   Updated: 2026/11/15 18:41:41 by sdubuiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	int	a;
	int	b;

	a = reverse_rotate(stack_a);
	b = reverse_rotate(stack_b);
	if (a || b)
		write(1, "rrr\n", 4);
}
