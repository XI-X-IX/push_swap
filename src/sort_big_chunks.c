/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_chunks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledos-s <aledos-s@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:17:19 by aledos-s          #+#    #+#             */
/*   Updated: 2025/02/06 12:25:23 by aledos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	has_remaining_in_chunk(t_stack *a, int min_index, int max_index)
{
	t_node	*current;

	current = a->top;
	while (current)
	{
		if (current->index >= min_index && current->index < max_index)
			return (1);
		current = current->next;
	}
	return (0);
}

void	push_to_b(t_stack *a, t_stack *b)
{
	int	chunk_size;
	int	min_index;
	int	max_index;


	chunk_size = a->size / 5;
	min_index = 0;
	max_index = chunk_size;
	while (a->size > 3)
	{
		if (a->top->index >= min_index && a->top->index < max_index)
		{
			pb(a, b);
			if (a->top->index < (min_index + max_index) / 2)
				rb(b);
		}
		else
			ra(a);
		if (has_remaining_in_chunk(a, min_index, max_index) == 0)
		{
			min_index = max_index;
			max_index += chunk_size;
		}
	}
}

// =============================================================================
// init_chunks
// =============================================================================
//
// Initialise le nombre de chunks et la médiane pour la pile `a`.
//
// @param a: pointeur vers la pile `a`
// =============================================================================

void	init_chunks(t_stack *a)
{
	if (a->size <= 100)
		a->chunks = 5;
	else
		a->chunks = 11;
	find_median(a);
}
