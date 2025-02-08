/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledos-s <aledos-s@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:43:16 by aledos-s          #+#    #+#             */
/*   Updated: 2025/02/06 00:17:45 by aledos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// =============================================================================
// ra & rb & rr
// =============================================================================
//
// Décale d’une position vers le haut tous les éléments de la pile a | b.
// Le premier élément devient le dernier.
//
// @param a: pointeur vers la pile a
// @param b: pointeur vers la pile b
// =============================================================================

void	ra(t_stack *a)
{
	t_node	*tmp;
	t_node	*last;

	if (!a || !a->top || !a->top->next || a->size < 2)
		return ;
	tmp = a->top;
	a->top = tmp->next;
	last = a->top;
	while (last->next)
		last = last->next;
	last->next = tmp;
	tmp->next = NULL;
	// ft_printf("Stack A: ");
	// print_stack(a);
	ft_putendl_fd("ra", 1);
}

void	rb(t_stack *b)
{
	t_node	*tmp;
	t_node	*last;

	if (!b || !b->top || !b->top->next || b->size < 2)
		return ;
	tmp = b->top;
	b->top = tmp->next;
	last = b->top;
	while (last->next)
		last = last->next;
	last->next = tmp;
	tmp->next = NULL;
	// ft_printf("Stack B: ");
	// print_stack(b);
	ft_putendl_fd("rb", 1);
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
	// print_stacks(a, b);
	ft_putendl_fd("rr", 1);
}
