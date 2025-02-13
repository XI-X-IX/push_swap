/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti_sort_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledos-s <alex>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:44:59 by aledos-s          #+#    #+#             */
/*   Updated: 2025/02/14 00:30:49 by aledos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// =============================================================================
// calculate_rotations
// =============================================================================
//
// Calcule les rotations nécessaires pour un élément.
//
// @param element: élément pour lequel calculer les rotations
// =============================================================================

static void	calculate_rotations(t_node *element)
{
	element->a_forward_rot = element->target_pos;
	element->a_reverse_rot = -(element->a_size - element->target_pos);
	element->b_forward_rot = element->b_pos;
	element->b_reverse_rot = -(element->b_size - element->b_forward_rot);
	if (abs(element->a_forward_rot) <= abs(element->a_reverse_rot))
		element->cost->moves_a = element->a_forward_rot;
	else
		element->cost->moves_a = element->a_reverse_rot;
	if (abs(element->b_forward_rot) <= abs(element->b_reverse_rot))
		element->cost->moves_b = element->b_forward_rot;
	else
		element->cost->moves_b = element->b_reverse_rot;
	element->cost->total_cost = abs(element->cost->moves_a)
		+ abs(element->cost->moves_b);
}

// =============================================================================
// calculate_element_cost
// =============================================================================
//
// Calcule le coût de rotation d'un élément.
//
// @param a: pile a
// @param b: pile b
// @param element: élément pour lequel calculer le coût
// =============================================================================

static void	calculate_element_cost(t_stack *a, t_stack *b, t_node *element)
{
	element->a_size = a->size;
	element->b_size = b->size;
	element->b_pos = get_element_position(b, element);
	calculate_rotations(element);
}

// =============================================================================
// calculate_rotation_costs
// =============================================================================
//
// Calcule les coûts de rotation pour tous les éléments de la pile b.
//
// @param a: pile a
// @param b: pile b
// =============================================================================

void	calculate_rotation_costs(t_stack *a, t_stack *b)
{
	t_node	*current_b;

	current_b = b->top;
	while (current_b)
	{
		find_insert_position(a, current_b);
		calculate_element_cost(a, b, current_b);
		current_b = current_b->next;
	}
}
