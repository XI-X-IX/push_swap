/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledos-s <alex>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:43:16 by aledos-s          #+#    #+#             */
/*   Updated: 2025/02/10 11:09:03 by aledos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack *stack)
{
	t_node	*tmp;
	t_node	*last;

	if (!stack || !stack->top || !stack->top->next || stack->size < 2)
		return ;
	tmp = stack->top;
	stack->top = tmp->next;
	stack->top->prev = NULL;
	last = stack->top;
	while (last->next)
		last = last->next;
	last->next = tmp;
	tmp->prev = last;
	tmp->next = NULL;
	stack->last = tmp;
}

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
	rotate(a);
	ft_putendl_fd("ra", 1);
}

void	rb(t_stack *b)
{
	rotate(b);
	ft_putendl_fd("rb", 1);
}

void	rr(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
	ft_putendl_fd("rr", 1);
}
