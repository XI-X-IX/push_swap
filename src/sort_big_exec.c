/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_exec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledos-s <alex>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 11:43:34 by aledos-s          #+#    #+#             */
/*   Updated: 2025/02/12 11:54:00 by aledos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	do_combined_rotations(t_stack *a, t_stack *b, t_node *node)
{
	while (node->cost->moves_a > 0 && node->cost->moves_b > 0)
	{
		rr(a, b);
		node->cost->moves_a--;
		node->cost->moves_b--;
	}
}

static void	do_combined_rev_rotations(t_stack *a, t_stack *b, t_node *node)
{
	while (node->cost->moves_a < 0 && node->cost->moves_b < 0)
	{
		rrr(a, b);
		node->cost->moves_a++;
		node->cost->moves_b++;
	}
}

static void	do_remaining_rotations(t_stack *stack, int *moves,
		void (*rotate)(t_stack *), void (*rev_rotate)(t_stack *))
{
	while (*moves > 0)
	{
		rotate(stack);
		(*moves)--;
	}
	while (*moves < 0)
	{
		rev_rotate(stack);
		(*moves)++;
	}
}

void	execute_optimized_moves(t_stack *a, t_stack *b, t_node *node)
{
	do_combined_rotations(a, b, node);
	do_combined_rev_rotations(a, b, node);
	do_remaining_rotations(a, &node->cost->moves_a, ra, rra);
	do_remaining_rotations(b, &node->cost->moves_b, rb, rrb);
}
