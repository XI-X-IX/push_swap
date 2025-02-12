/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_cost.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledos-s <alex>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:13:01 by aledos-s          #+#    #+#             */
/*   Updated: 2025/02/12 15:32:52 by aledos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calculate_basic_cost(t_node *node, int pos, int size)
{
	init_cost(node);
	if (pos <= size / 2)
		node->cost->moves_a = pos;
	else
		node->cost->moves_a = -(size - pos);
	node->cost->total_cost = abs(node->cost->moves_a);
}

void	calculate_dual_cost(t_node *node, t_stack *a, t_stack *b)
{
	int	combined_moves;

	init_cost(node);
	node->cost->moves_a = get_rotation_cost(node->pos, a->size);
	node->cost->moves_b = get_rotation_cost(node->index, b->size);
	combined_moves = 0;
	if ((node->cost->moves_a > 0 && node->cost->moves_b > 0)
		|| (node->cost->moves_a < 0 && node->cost->moves_b < 0))
		combined_moves = min(abs(node->cost->moves_a),
				abs(node->cost->moves_b));
	node->cost->total_cost = abs(node->cost->moves_a)
		+ abs(node->cost->moves_b) - (combined_moves / 2);
}

int	get_rotation_cost(int pos, int size)
{
	if (pos <= size / 2)
		return (pos);
	return (-(size - pos));
}

void calculate_optimized_cost(t_node *node, t_stack *a, t_stack *b)
{
	int target_pos;
	int combined_moves;

	node->cost = malloc(sizeof(t_cost));
	if (!node->cost)
		return;

	target_pos = get_insert_position(a, node->data);

	// Calcul des coûts de rotation
	node->cost->moves_a = get_rotation_cost(target_pos, a->size);
	node->cost->moves_b = get_rotation_cost(node->pos, b->size);

	// Détection des mouvements combinés (rr ou rrr)
	combined_moves = 0;
	if ((node->cost->moves_a > 0 && node->cost->moves_b > 0) || (node->cost->moves_a < 0 && node->cost->moves_b < 0))
		combined_moves = min(abs(node->cost->moves_a), abs(node->cost->moves_b));

	node->cost->total_cost = abs(node->cost->moves_a) + abs(node->cost->moves_b) - combined_moves;
}


void	init_cost(t_node *node)
{
	if (!node->cost)
	{
		node->cost = malloc(sizeof(t_cost));
		if (!node->cost)
			return ;
		ft_memset(node->cost, 0, sizeof(t_cost));
	}
}
