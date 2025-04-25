#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h> // write & read
# include <stdlib.h> // malloc & exit
# include <stdbool.h>
# include "libft/libft.h"
# include "libft/printf/ft_printf.h"

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
	int				target_pos;
	int				b_pos;
	struct s_node	*target_node;
	bool			above_median;
	bool			cheapest;
	int				a_forward_rot;
	int				a_reverse_rot;
	int				b_forward_rot;
	int				b_reverse_rot;
	int				a_size;
	int				b_size;
	t_cost			*cost;
	struct s_node	*next;
	struct s_node	*prev;
}				t_node;

typedef struct s_stack
{
	int				size;
	int				median;
	struct s_node	*top;
	struct s_node	*last;
}				t_stack;

// INIT
t_cost	*init_cost(void);
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

// SORT_BIG_UTILS
void	set_position(t_stack *s);
void	pre_push(t_stack *stack, t_node *top_node, char stack_name);
void	min_on_top(t_stack *a);

// SORT_A
void	set_cheapest(t_stack *stack);
void	sort_a(t_stack *a, t_stack *b);

// SORT_B
void	sort_b(t_stack *a, t_stack *b);

// SORT_PUSH
void	rotate_both(t_stack *a, t_stack *b, t_node *cheapest_node);
void	rev_rotate_both(t_stack *a, t_stack *b, t_node *cheapest_node);
void	push_to_b(t_stack *a, t_stack *b);
void	push_to_a(t_stack *a, t_stack *b);

// SORT_UTILS
t_node	*find_min_node(t_stack *a);
t_node	*find_max_node(t_stack *a);
int		find_min(t_stack *stack);
int		find_max(t_stack *stack);
int		find_position(t_stack *a, int min);
void	sort_stack(t_stack *a, t_stack *b);
int		is_sorted(t_stack *a);
int		get_element_position(t_stack *stack, t_node *element);

void	print_stack(t_stack *a);
void	print_stacks(t_stack *a, t_stack *b);
void	prints(t_stack *a);
int		min(int a, int b);

// SORT_BIG_INDEX
void	index_stack(t_stack *a);

// OPTI_SORT
void	rotate_stacks(t_stack *a, t_stack *b, t_node *element);
t_node	*find_cheapest_element(t_stack *b);

void	smart_push_swap(t_stack *a, t_stack *b);
void	find_best_position(t_stack *a, t_node *b_element, int *best_pos,
			int *best_val);
void	find_min_position_w_pointer(t_stack *a, int *best_pos, int *best_val);
void	find_insert_position(t_stack *a, t_node *b_element);
void	find_min_max(t_stack *a, int *min, int *max);
int		get_element_position(t_stack *stack, t_node *element);
void	align_stack(t_stack *a);

void	calculate_rotation_costs(t_stack *a, t_stack *b);

#endif
