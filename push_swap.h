/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/15 17:50:17 by username         #+#    #+#              */
/*   Updated: 2026/11/15 18:20:28 by sdubuiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

/* ************************************************************************** */
/*                                OPERATIONS                                  */
/* ************************************************************************** */

/* Generic operations */
int		swap(t_stack **stack);
int		push(t_stack **stack_a, t_stack **stack_b);
int		rotate(t_stack **stack);
int		reverse_rotate(t_stack **stack);

/* ************************************************************************** */
/*                               INSTRUCTIONS                                 */
/* ************************************************************************** */

/* Swap */
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);

/* Push */
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);

/* Rotate */
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);

/* Reverse rotate */
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);

#endif
