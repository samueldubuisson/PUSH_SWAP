/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdubuiss <sdubuiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 17:26:10 by sdubuiss          #+#    #+#             */
/*   Updated: 2026/11/15 17:26:17 by sdubuiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (!*stack || !(*stack)->next)
		return (0);
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
	return (1);
}
/*
** SWAP:
** 1. Store the first two nodes (first and second).
** 2. Make first point to the node after second.
** 3. Make second point to first.
** 4. Update the stack head to second.
**
** Before: A -> B -> C
** After:  B -> A -> C
*/
