/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdubuiss <sdubuiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 17:25:38 by sdubuiss          #+#    #+#             */
/*   Updated: 2026/11/15 17:25:42 by sdubuiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	reverse_rotate(t_stack **stack)
{
	t_stack	*before_last;
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return (0);
	before_last = *stack;
	while (before_last->next->next)
		before_last = before_last->next;
	last = before_last->next;
	before_last->next = NULL;
	last->next = *stack;
	*stack = last;
	return (1);
}
/*
** REVERSE ROTATE:
** 1. Check if the stack has at least two elements.
** 2. Find the second-to-last node (before_last).
** 3. Store the last node in 'last'.
** 4. Detach the last node by setting before_last->next to NULL.
** 5. Link the last node to the current stack head.
** 6. Update the stack head to the last node.
**
** Before: A -> B -> C -> D
** After:  D -> A -> B -> C
*/
