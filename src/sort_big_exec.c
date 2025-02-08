/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_exec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledos-s <aledos-s@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 11:43:34 by aledos-s          #+#    #+#             */
/*   Updated: 2025/02/06 12:06:00 by aledos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	do_double_rotations(t_stack *a, t_stack *b, t_node *node)
{
	while (node->cost->moves_a > 0 && node->cost->moves_b > 0)
	{
		rr(a, b);
		node->cost->moves_a--;
		node->cost->moves_b--;
	}
}

static void	do_double_reverse_rotations(t_stack *a, t_stack *b, t_node *node)
{
	while (node->cost->moves_a < 0 && node->cost->moves_b < 0)
	{
		rrr(a, b);
		node->cost->moves_a++;
		node->cost->moves_b++;
	}
}

static void	do_remaining_a_rotations(t_stack *a, t_node *node)
{
	while (node->cost->moves_a > 0)
	{
		ra(a);
		node->cost->moves_a--;
	}
	while (node->cost->moves_a < 0)
	{
		rra(a);
		node->cost->moves_a++;
	}
}

static void	do_remaining_b_rotations(t_stack *b, t_node *node)
{
	while (node->cost->moves_b > 0)
	{
		rb(b);
		node->cost->moves_b--;
	}
	while (node->cost->moves_b < 0)
	{
		rrb(b);
		node->cost->moves_b++;
	}
}

// =============================================================================
// exec_moves
// =============================================================================
//
// Exécute les mouvements nécessaires pour déplacer les éléments des piles a & b
//
// Cette fonction exécute les rotations et les rotations inverses sur les
// deux piles simultanément, puis exécute les rotations restantes sur chaque
// pile individuellement.
//
// @param a: pointeur vers la pile `a`
// @param b: pointeur vers la pile `b`
// @param cost_a: coût des mouvements pour la pile `a`
// @param cost_b: coût des mouvements pour la pile `b`
// =============================================================================

void	execute_moves(t_stack *a, t_stack *b, t_node *node)
{
	do_double_rotations(a, b, node);
	do_double_reverse_rotations(a, b, node);
	do_remaining_a_rotations(a, node);
	do_remaining_b_rotations(b, node);
}
