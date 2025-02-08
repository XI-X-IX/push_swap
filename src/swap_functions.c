/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledos-s <aledos-s@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 22:35:22 by aledos-s          #+#    #+#             */
/*   Updated: 2025/02/07 15:23:13 by aledos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	t_node	*first;
	t_node	*second;
	int		swp;

	if (!a || !a->top || !a->top->next)
		return ;
	first = a->top;
	second = a->top->next;
	swp = first->data;
	first->data = second->data;
	second->data = swp;
	ft_putendl_fd("sa", 1);
}

void	sb(t_stack *b)
{
	t_node	*first;
	t_node	*second;
	int		swp;

	if (!b || !b->top || !b->top->next)
		return ;
	first = b->top;
	second = b->top->next;
	swp = first->data;
	first->data = second->data;
	second->data = swp;
	ft_putendl_fd("sb", 1);
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
	ft_putendl_fd("ss", 1);
}
