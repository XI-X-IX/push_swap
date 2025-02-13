/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti_sort_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledos-s <alex>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:44:36 by aledos-s          #+#    #+#             */
/*   Updated: 2025/02/14 00:29:03 by aledos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// =============================================================================
// rotate_both_forward
// =============================================================================
//
// Effectue les rotations simultanées (rr) sur les piles a et b.
//
// @param a: pile a
// @param b: pile b
// @param moves_a: nombre de rotations à effectuer sur la pile a
// @param moves_b: nombre de rotations à effectuer sur la pile b
// =============================================================================

static void	rotate_both_forward(t_stack *a, t_stack *b, int *moves_a,
		int *moves_b)
{
	while (*moves_a > 0 && *moves_b > 0)
	{
		rr(a, b);
		(*moves_a)--;
		(*moves_b)--;
	}
}

// =============================================================================
// rotate_both_reverse
// =============================================================================
//
// Effectue les rotations inverses simultanées (rrr) sur les piles a et b.
//
// @param a: pile a
// @param b: pile b
// @param moves_a: nombre de rotations inverses à effectuer sur la pile a
// @param moves_b: nombre de rotations inverses à effectuer sur la pile b
// =============================================================================

static void	rotate_both_reverse(t_stack *a, t_stack *b, int *moves_a,
		int *moves_b)
{
	while (*moves_a < 0 && *moves_b < 0)
	{
		rrr(a, b);
		(*moves_a)++;
		(*moves_b)++;
	}
}

// =============================================================================
// rotate_stack_a
// =============================================================================
//
// Effectue les rotations simples (ra ou rra) sur la pile a.
//
// @param a: pile a
// @param moves_a: nombre de rotations à effectuer sur la pile a
// =============================================================================

static void	rotate_stack_a(t_stack *a, int *moves_a)
{
	while (*moves_a > 0)
	{
		ra(a);
		(*moves_a)--;
	}
	while (*moves_a < 0)
	{
		rra(a);
		(*moves_a)++;
	}
}

// =============================================================================
// rotate_stack_b
// =============================================================================
//
// Effectue les rotations simples (rb ou rrb) sur la pile b.
//
// @param b: pile b
// @param moves_b: nombre de rotations à effectuer sur la pile b
// =============================================================================

static void	rotate_stack_b(t_stack *b, int *moves_b)
{
	while (*moves_b > 0)
	{
		rb(b);
		(*moves_b)--;
	}
	while (*moves_b < 0)
	{
		rrb(b);
		(*moves_b)++;
	}
}

// =============================================================================
// rotate_stacks
// =============================================================================
//
// Effectue les rotations nécessaires sur les piles a et b pour aligner
// l'élément donné.
//
// @param a: pile a
// @param b: pile b
// @param element: élément à aligner
// =============================================================================

void	rotate_stacks(t_stack *a, t_stack *b, t_node *element)
{
	int	moves_a;
	int	moves_b;

	moves_a = element->cost->moves_a;
	moves_b = element->cost->moves_b;
	rotate_both_forward(a, b, &moves_a, &moves_b);
	rotate_both_reverse(a, b, &moves_a, &moves_b);
	rotate_stack_a(a, &moves_a);
	rotate_stack_b(b, &moves_b);
}
