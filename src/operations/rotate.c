/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdubuiss <sdubuiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 17:25:08 by sdubuiss          #+#    #+#             */
/*   Updated: 2026/11/15 17:25:23 by sdubuiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate(t_stack	**stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return (0);
	first = *stack;
	last = first;
	while (last->next)
		last = last->next;
	*stack = first->next;
	first->next = NULL;
	last->next = first;
	return (1);
}
/*
** ROTATE:
** 1. Check if the stack has at least two elements.
** 2. Store the first node in 'first'.
** 3. Find the last node in the stack.
** 4. Move the stack head to the second node.
** 5. Detach the first node by setting first->next to NULL.
** 6. Link the last node to the first node.
**
** Before: A -> B -> C -> D
** After:  B -> C -> D -> A
*/
