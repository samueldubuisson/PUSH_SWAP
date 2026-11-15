/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdubuiss <sdubuiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 17:26:32 by sdubuiss          #+#    #+#             */
/*   Updated: 2026/11/15 17:26:35 by sdubuiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	if (!*stack_a)
		return (0);
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	tmp->next = *stack_b;
	*stack_b = tmp;
	return (1);
}
/*
** PUSH:
** 1. Check if the source stack is empty.
**    If empty, return 0 (no operation performed).
** 2. Store the first node of stack_a in 'tmp'.
** 3. Move stack_a's head to the next node.
** 4. Make tmp point to the current head of stack_b.
** 5. Update stack_b's head to tmp.
** 6. Return 1 to indicate that the operation was successful.
**
** Before:
** Stack A: A -> B -> C
** Stack B: D -> E
**
** After:
** Stack A: B -> C
** Stack B: A -> D -> E
*/
