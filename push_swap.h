/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledos-s <alex>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 22:20:24 by aledos-s          #+#    #+#             */
/*   Updated: 2025/02/12 14:54:27 by aledos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h> // write & read
# include <stdlib.h> // malloc & exit
# include "libft/libft.h"
# include "libft/printf/ft_printf.h"
# include <stdio.h> //////////////

// COLORS
# define OK_COLOR		"\033[0;32m"
# define NO_COLOR		"\033[0m"
# define WARN_COLOR		"\033[0;33m"
# define ERROR_COLOR	"\033[0;31m"

// RETURN CODES
# define SUCCESS		0
# define ERROR			1

# define TRUE			1
# define FALSE			0

# define INT_MAX		2147483647
# define INT_MIN		-2147483648

// STRUCTURES
typedef struct s_cost
{
	int		moves_a;
	int		moves_b;
	int		total_cost;
}			t_cost;

typedef struct s_node
{
	int				data;
	int				index;
	int				pos;
	t_cost			*cost;
	struct s_node	*next;
	struct s_node	*prev;
}				t_node;

typedef struct s_stack
{
	int				size;
	int				median;
	int				chunks;
	struct s_node	*top;
	struct s_node	*last;
}				t_stack;

// INIT
void	init_empty_stack(t_stack **b);
int		init_stacks(t_stack **a, t_stack **b, int ac, char **av);
int		fill_stack(t_stack *a, int ac, char **av);
t_node	*new_node(int data);

// PARSER
void	parse_arg(t_stack **a, t_stack **b, char **av);
void	split_and_init(t_stack **a, t_stack **b, char **av);

// ERRORS
int		is_number(const char *str);
long	ft_atol(const char *str);
int		check_limits(const char *str);
void	check_args(int ac, char **av);

// EXIT
void	free_stacks(t_stack *a, t_stack *b);
void	free_stack(t_stack *stack);
void	exit_error(t_stack *a, t_stack *b);
void	free_split(char **tab);
void	free_cost(t_node *node);

// SWAP
void	swap(t_stack *stack);
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);

// PUSH
void	push(t_stack *src, t_stack *dst);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);

// ROTATE
void	rotate(t_stack *stack);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);

// REVERSE
void	rev_rot(t_stack *stack);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

// SORT_SMALL
void	sort_three(t_stack *a);
void	sort_four(t_stack *a, t_stack *b);
void	sort_five(t_stack *a, t_stack *b);
void	find_and_position_min(t_stack *a, t_stack *b);

// SORT_BIG
void	sort_big(t_stack *a, t_stack *b);

// SORT_BIG_OPTI

// SORT_BIG_COST
// void	calculate_basic_cost(t_node *node, int pos, int size);
// void	calculate_dual_cost(t_node *node, t_stack *a, t_stack *b);
// int		get_rotation_cost(int pos, int size);
// void	calculate_optimized_cost(t_node *node, t_stack *a, t_stack *b);
// void	init_cost(t_node *node);

// void	free_all_costs(t_stack *stack);
// void	cleanup_costs(t_stack *b);
// int		abs(int n);
// int		min(int a, int b);

// SORT_BIG_INDEX
void	index_stack(t_stack *a);

// SORT_BIG_EXEC
void	execute_optimized_moves(t_stack *a, t_stack *b, t_node *node);

// SORT_BIG_MEDIAN
void	find_median(t_stack *stack);

// SORT_BIG_POSITION
// int		get_simple_position(t_stack *stack, int value);
// int		get_best_target(t_stack *stack, int value, int min, int max);
// void	rotate_to_target_a(t_stack *stack, int pos);
// void	rotate_to_target_b(t_stack *stack, int pos);
// int		find_closest_position(t_stack *stack, int value);

// SORT_BIG_CHUNKS
void	push_to_b(t_stack *a, t_stack *b);
void	init_chunks(t_stack *a);

// SORT_UTILS
int		find_min(t_stack *a);
int		find_max(t_stack *a);
int		find_position(t_stack *a, int min);
void	sort_stack(t_stack *a, t_stack *b);
int		is_sorted(t_stack *a);

void	print_stack(t_stack *a);
void	print_stacks(t_stack *a, t_stack *b);
void    prints(t_stack *a);

#endif
