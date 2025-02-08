/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledos-s <aledos-s@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 22:20:24 by aledos-s          #+#    #+#             */
/*   Updated: 2025/02/07 14:26:02 by aledos-s         ###   ########.fr       */
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
	int		moves_a;	// Nombre de mouvements nécessaires dans la pile A
	int		moves_b;	// Nombre de mouvements nécessaires dans la pile B
	int		total_cost;	// Coût total des mouvements
}			t_cost;

typedef struct s_node
{
	int				data;	// La valeur du nombre
	int				index;	// Position finale dans la pile triée
	int				pos;	// Position actuelle dans la pile
	t_cost			*cost;	// Structure des coûts de déplacement
	struct s_node	*next;
	struct s_node	*prev;
}				t_node;

typedef struct s_stack
{
	int				size;
	int				median;	// Médiane de la pile
	int				chunks;	// Nombre de chunks pour le tri
	struct s_node	*top;
	struct s_node	*last;
}				t_stack;

// INIT
void	init_empty_stack(t_stack **b);
int		init_stacks(t_stack **a, t_stack **b, int ac, char **av);
int		fill_stack(t_stack *a, int ac, char **av);
t_node	*new_node(int data);

// ERRORS
int		is_number(const char *str);
long	ft_atol(const char *str);
int		check_limits(const char *str);
void	check_args(int ac, char **av);

// EXIT
void	free_stacks(t_stack *a, t_stack *b);
void	free_stack(t_stack *stack);
void	exit_error(t_stack *a, t_stack *b);

// SWAP
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);

// PUSH
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);

// ROTATE
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);

// REVERSE
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
void	index_stack(t_stack *a);
void	calculate_cost(t_node *node, t_stack *a, t_stack *b);

// SORT_BIG_EXEC
void	execute_moves(t_stack *a, t_stack *b, t_node *node);

// SORT_BIG_MEDIAN
void	find_median(t_stack *stack);

// SORT_BIG_CHUNKS
void	init_chunks(t_stack *a);
void	push_to_b(t_stack *a, t_stack *b);

// SORT_UTILS
int		find_min(t_stack *a);
int		find_max(t_stack *a);
int		find_position(t_stack *a, int min);
void	sort_stack(t_stack *a, t_stack *b);
int		is_sorted(t_stack *a);

// PARSER
void	parse_arg(t_stack **a, t_stack **b, char **av);
void	split_and_init(t_stack **a, t_stack **b, char **av);

// LIST /////////////////////////////////////////////////////////
void	print_stacks(t_stack *a, t_stack *b);
void	print_stack(t_stack *a);

#endif
