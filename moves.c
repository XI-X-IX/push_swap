/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledos-s <alex>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 22:35:22 by aledos-s          #+#    #+#             */
/*   Updated: 2025/01/30 14:37:46 by aledos-s         ###   ########.fr       */
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
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
}

void	pa(t_stack *a, t_stack *b)
{
	t_node	*psh;

	if (!b || !b->top)
		return ;
	psh = b->top;
	b->top = b->top->next;
	psh->next = a->top;
	a->top = psh;
}

void	pb(t_stack *a, t_stack *b)
{
	t_node	*psh;

	if (!a || !a->top)
		return ;
	psh = a->top;
	a->top = a->top->next;
	psh->next = b->top;
	b->top = psh;
}

void	ra(t_stack *a)
{
	t_node	*tmp;
	t_node	*new;
	t_node	*i;

	tmp = a->top;
	new = a->top->next;
	a->top = new;
	i = new;
	while (i->next != NULL)
		i = i->next;
	i->next = tmp;
	tmp->next = NULL;
}

void	rb(t_stack *b)
{
	t_node	*tmp;
	t_node	*new;
	t_node	*i;

	tmp = b->top;
	new = b->top->next;
	b->top = new;
	i = new;
	while (i->next != NULL)
		i = i->next;
	i->next = tmp;
	tmp->next = NULL;
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
}

void	rra(t_stack *a)
{
	t_node	*new;
	t_node	*tmp;
	t_node	*i;

	tmp = a-

	
}

void	rrb(t_stack *b)
{

}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
}