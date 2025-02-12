/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledos-s <alex>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 22:35:22 by aledos-s          #+#    #+#             */
/*   Updated: 2025/02/10 11:07:28 by aledos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
{
	t_node	*first;
	t_node	*second;
	int		swp;

	if (!stack || !stack->top || !stack->top->next)
		return ;
	first = stack->top;
	second = stack->top->next;
	swp = first->data;
	first->data = second->data;
	second->data = swp;
}

// =============================================================================
// sa & sb & ss
// =============================================================================
//
// Échange les deux premiers éléments de la pile a | b.
//
// Si la pile a | b contient moins de deux éléments, la fonction ne fait rien.
//
// @param a | b: pointeur vers la pile a | b
// =============================================================================

void	sa(t_stack *a)
{
	swap(a);
	ft_putendl_fd("sa", 1);
}

void	sb(t_stack *b)
{
	swap(b);
	ft_putendl_fd("sb", 1);
}

void	ss(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
	ft_putendl_fd("ss", 1);
}
