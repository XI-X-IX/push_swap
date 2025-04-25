#include "push_swap.h"

void	push(t_stack *src, t_stack *dst)
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
	ft_putendl_fd("pa", 1);
}

void	pb(t_stack *a, t_stack *b)
{
	push(a, b);
	ft_putendl_fd("pb", 1);
}
