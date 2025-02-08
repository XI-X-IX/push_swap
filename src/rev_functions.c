/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledos-s <aledos-s@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:49:58 by aledos-s          #+#    #+#             */
/*   Updated: 2025/02/06 00:18:01 by aledos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	t_node	*prev;
	t_node	*i;

	if (!a || !a->top || !a->top->next)
		return ;
	if (a->size == 2)
	{
		sa(a);
		return ;
	}
	prev = NULL;
	i = a->top;
	while (i->next != NULL)
	{
		prev = i;
		i = i->next;
	}
	prev->next = NULL;
	i->next = a->top;
	a->top = i;
	// ft_printf("Stack A: ");
	// print_stack(a);
	ft_putendl_fd("rra", 1);
}

void	rrb(t_stack *b)
{
	t_node	*prev;
	t_node	*i;

	if (!b || !b->top || !b->top->next)
		return ;
	if (b->size == 2)
	{
		sa(b);
		return ;
	}
	prev = NULL;
	i = b->top;
	while (i->next != NULL)
	{
		prev = i;
		i = i->next;
	}
	prev->next = NULL;
	i->next = b->top;
	b->top = i;
	// ft_printf("Stack B: ");
	// print_stack(b);
	ft_putendl_fd("rrb", 1);
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
	// print_stacks(a, b);
	ft_putendl_fd("rrr", 1);
}
