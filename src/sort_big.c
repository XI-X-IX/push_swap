/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledos-s <aledos-s@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:41:06 by aledos-s          #+#    #+#             */
/*   Updated: 2025/02/06 12:22:11 by aledos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	find_best_move(t_stack *a, t_stack *b, t_node **best)
{
	t_node	*current;
	int		best_cost;

	current = b->top;
	best_cost = INT_MAX;
	*best = NULL;
	while (current)
	{
		calculate_cost(current, a, b);
		if (current->cost->total_cost < best_cost)
		{
			best_cost = current->cost->total_cost;
			*best = current;
		}
		current = current->next;
	}
}

void	sort_big(t_stack *a, t_stack *b)
{
	t_node	*best_node;

	index_stack(a);
	init_chunks(a);
	push_to_b(a, b);
	sort_three(a);
	while (b->size > 0)
	{
		find_best_move(a, b, &best_node);
		execute_moves(a, b, best_node);
		pa(a, b);
	}
}

