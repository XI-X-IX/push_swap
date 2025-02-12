/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledos-s <alex>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:49:58 by aledos-s          #+#    #+#             */
/*   Updated: 2025/02/10 11:08:45 by aledos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rot(t_stack *stack)
{
	t_node	*prev;
	t_node	*last;

	if (!stack || !stack->top || !stack->top->next)
		return ;
	if (stack->size == 2)
	{
		swap(stack);
		return ;
	}
	prev = NULL;
	last = stack->top;
	while (last->next != NULL)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = stack->top;
	stack->top->prev = last;
	stack->top = last;
	last->prev = NULL;
	stack->last = prev;
}

// =============================================================================
// rra & rrb & rrr
// =============================================================================
//
// Décale d’une position vers le bas tous les éléments de la pile a | b.
// Le dernier élément devient le premier.
//
// @param a: pointeur vers la pile a
// @param b: pointeur vers la pile b
// =============================================================================

void	rra(t_stack *a)
{
	rev_rot(a);
	ft_putendl_fd("rra", 1);
}

void	rrb(t_stack *b)
{
	rev_rot(b);
	ft_putendl_fd("rrb", 1);
}

void	rrr(t_stack *a, t_stack *b)
{
	rev_rot(a);
	rev_rot(b);
	ft_putendl_fd("rrr", 1);
}
