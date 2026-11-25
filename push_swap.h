/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   push_swap.h                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/23 01:41:13 by username         #+#    #+#              */
/*   Updated: 2026/11/25 19:44:33 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

# define ROTATE_UP 1
# define ROTATE_DOWN -1

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
	int			silent;
}	t_data;

typedef struct s_candidate
{
	int	best_cost;
	int	best_pos;
	int	current_cost;
	int	i;
	int	value;
}	t_candidate;

typedef struct s_rotation
{
	int	size_a;
	int	size_b;
	int	rotate_a;
	int	rotate_b;
	int	direction_a;
	int	direction_b;
}	t_rotation;

int			swap(t_stack **stack);
int			push(t_stack **stack_a, t_stack **stack_b);
int			rotate(t_stack **stack);
int			reverse_rotate(t_stack **stack);
void		sa(t_data *data);
void		sb(t_data *data);
void		ss(t_data *data);
void		pa(t_data *data);
void		pb(t_data *data);
void		ra(t_data *data);
void		rb(t_data *data);
void		rr(t_data *data);
void		rra(t_data *data);
void		rrb(t_data *data);
void		rrr(t_data *data);
int			ft_fill_stack(char ***parse, t_stack **stack_a);
void		ft_init_struct(t_data *data);
char		***ft_parse_arguments(int argc, char *argv[]);
int			ft_parse_numbers(char ***numbers);
int			ft_check_duplicates(char ***numbers);
int			ft_check_int_limits(char ***numbers);
char		***ft_parse_options(char ***parse, t_config *config);
void		ft_print_benchmark(t_data data);
int			ft_parse_input(int argc, char **argv, t_data *data);
t_stack		*ft_stack_new(int value);
t_stack		*ft_stacklast(t_stack *stack);
void		ft_stackadd_front(t_stack **stack, t_stack *new);
void		ft_stackadd_back(t_stack **stack, t_stack *new);
void		ft_stackclear(t_stack **stack);
void		free_parse(char ***parse);
int			ft_strcmp(char *s1, char *s2);
int			ft_stack_size(t_stack *stack);
void		ft_sort_stack(t_data *data);
float		ft_compute_disorder(t_stack *stack_a);
void		ft_sort_simple(t_data *data);
void		ft_sort_medium(t_data *data);
void		ft_sort_complex(t_data *data);
void		ft_rotate_to_position_a(t_data *data, int pos);
int			ft_find_insert_position(t_stack *stack, int value);
void		ft_rotate_both(t_data *data, int pos_a, int pos_b);
t_rotation	ft_calculate_rotation(t_data *data, int pos_a, int pos_b);
t_candidate	ft_find_best_candidate(t_data *data);

#endif
