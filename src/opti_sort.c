/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledos-s <alex>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:40:38 by aledos-s          #+#    #+#             */
/*   Updated: 2025/02/14 00:23:45 by aledos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// =============================================================================
// initial_split
// =============================================================================
//
// Divise initialement la pile a en deux moitiés et pousse les éléments
// inférieurs ou égaux à la médiane dans la pile b.
//
// @param a: pile a
// @param b: pile b
// =============================================================================

static void	initial_split(t_stack *a, t_stack *b)
{
	int	min;
	int	max;
	int	mid;
	int	pushed;
	int	size;

	find_min_max(a, &min, &max);
	mid = (min + max) / 2;
	pushed = 0;
	size = a->size;
	while (pushed < size / 2)
	{
		if (a->top->data <= mid)
		{
			pb(a, b);
			pushed++;
		}
		else
			ra(a);
	}
	while (a->size > 3)
		pb(a, b);
}

// =============================================================================
// smart_push_swap
// =============================================================================
//
// Trie les piles a et b en utilisant une stratégie de tri optimisée.
//
// @param a: pile a
// @param b: pile b
// =============================================================================

void	smart_push_swap(t_stack *a, t_stack *b)
{
	t_node	*cheapest;

	initial_split(a, b);
	sort_three(a);
	while (b->size > 0)
	{
		calculate_rotation_costs(a, b);
		cheapest = find_cheapest_element(b);
		rotate_stacks(a, b, cheapest);
		pa(a, b);
	}
	align_stack(a);
}
