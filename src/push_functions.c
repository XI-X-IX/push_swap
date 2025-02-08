/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledos-s <aledos-s@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:23:59 by aledos-s          #+#    #+#             */
/*   Updated: 2025/02/06 00:18:17 by aledos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack *src, t_stack *dst)
{
	t_node	*temp;

	if (!src || !src->top)
		return ;
	temp = src->top;
	src->top = src->top->next;
	if (src->top)
		src->top->prev = NULL;
	else
		src->last = NULL;
	src->size--;
	temp->next = dst->top;
	if (dst->top)
		dst->top->prev = temp;
	dst->top = temp;
	if (!dst->last)
		dst->last = temp;
	dst->size++;
}

// =============================================================================
// pa & pb
// =============================================================================
//
// Prend le premier élément au sommet de b | a et le met sur le sommet de a | b.
// Ne fait rien si b | a est vide.
//
// @param a: pointeur vers la pile a
// @param b: pointeur vers la pile b
// =============================================================================

void	pa(t_stack *a, t_stack *b)
{
	push(b, a);
	// print_stacks(a, b);
	ft_putendl_fd("pa", 1);
}

void	pb(t_stack *a, t_stack *b)
{
	push(a, b);
	// print_stacks(a, b);
	ft_putendl_fd("pb", 1);
}
