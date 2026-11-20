/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/15 17:50:17 by username         #+#    #+#              */
/*   Updated: 2026/11/20 23:20:37 by sdubuiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

typedef struct s_config
{
	int	bench;
	int	simple;
	int	medium;
	int	complex;
	int	adaptive;
}	t_config;

typedef struct s_stats
{
	float	disorder;
	char	*strategy;
	int		total_ops;
	int		count_sa;
	int		count_sb;
	int		count_ss;
	int		count_pa;
	int		count_pb;
	int		count_ra;
	int		count_rb;
	int		count_rr;
	int		count_rra;
	int		count_rrb;
	int		count_rrr;
}	t_stats;

typedef struct s_data
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_config	config;
	t_stats		stats;
}	t_data;

/* Generic operations */
int		swap(t_stack **stack);
int		push(t_stack **stack_a, t_stack **stack_b);
int		rotate(t_stack **stack);
int		reverse_rotate(t_stack **stack);

/* Swap */
void	sa(t_data *data);
void	sb(t_data *data);
void	ss(t_data *data);

/* Push */
void	pa(t_data *data);
void	pb(t_data *data);

/* Rotate */
void	ra(t_data *data);
void	rb(t_data *data);
void	rr(t_data *data);

/* Reverse rotate */
void	rra(t_data *data);
void	rrb(t_data *data);
void	rrr(t_data *data);

/* Parsing */
int		ft_fill_stack(char ***parse, t_stack **stack_a);
void	ft_init_struct(t_data *data);
char	***ft_parse_arguments(int argc, char *argv[]);
int		ft_parse_numbers(char ***numbers);
int		ft_check_duplicates(char ***numbers);
int		ft_check_int_limits(char ***numbers);
char	***ft_parse_options(char ***parse, t_config *config);
void	ft_print_benchmark(t_data data);

/* Utils */
t_stack	*ft_stack_new(int value);
t_stack	*ft_stacklast(t_stack *stack);
void	ft_stackadd_front(t_stack **stack, t_stack *new);
void	ft_stackadd_back(t_stack **stack, t_stack *new);
void	ft_stackclear(t_stack **stack);
void	free_parse(char ***parse);
int		ft_strcmp(char *s1, char *s2);

/* Sorting */
void	ft_sort_stack(t_data *data);
float	ft_compute_disorder(t_stack *stack_a);
void	ft_sort_simple(t_data *data);
void	ft_sort_medium(t_data *data);
void	ft_sort_complex(t_data *data);

#endif
