/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti_sort_cheap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledos-s <alex>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:49:57 by aledos-s          #+#    #+#             */
/*   Updated: 2025/02/14 00:34:01 by aledos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// =============================================================================
// find_best_position
// =============================================================================
//
// Trouve la meilleure position pour insérer un élément dans la pile a.
//
// @param a: pile a
// @param b_element: élément de la pile b à insérer
// @param best_pos: pointeur vers la meilleure position trouvée
// @param best_val: pointeur vers la meilleure valeur trouvée
// =============================================================================

void	find_best_position(t_stack *a, t_node *b_element, int *best_pos,
		int *best_val)
{
	t_node	*current;
	int		i;

	current = a->top;
	i = 0;
	while (i < a->size)
	{
		if (current->data > b_element->data && current->data < *best_val)
		{
			*best_val = current->data;
			*best_pos = i;
		}
		current = current->next;
		i++;
	}
}

// =============================================================================
// find_min_position_w_pointer
// =============================================================================
//
// Trouve la position du plus petit élément dans la pile a et met à jour les
// pointeurs best_pos et best_val.
//
// @param a: pile a
// @param best_pos: pointeur vers la meilleure position trouvée
// @param best_val: pointeur vers la meilleure valeur trouvée
// =============================================================================

void	find_min_position_w_pointer(t_stack *a, int *best_pos, int *best_val)
{
	t_node	*current;
	int		i;

	current = a->top;
	i = 0;
	while (i < a->size)
	{
		if (current->data < *best_val)
		{
			*best_val = current->data;
			*best_pos = i;
		}
		current = current->next;
		i++;
	}
}

// =============================================================================
// find_insert_position
// =============================================================================
//
// Trouve la position d'insertion pour un élément de la pile b dans la pile a.
//
// @param a: pile a
// @param b_element: élément de la pile b à insérer
// =============================================================================

void	find_insert_position(t_stack *a, t_node *b_element)
{
	int		best_pos;
	int		best_val;

	if (!a->top)
		return ;
	best_pos = 0;
	best_val = INT_MAX;
	find_best_position(a, b_element, &best_pos, &best_val);
	if (best_val == INT_MAX)
	{
		find_min_position_w_pointer(a, &best_pos, &best_val);
	}
	b_element->target_pos = best_pos;
}

// =============================================================================
// find_cheapest_element
// =============================================================================
//
// Trouve l'élément avec le coût total de rotation le plus bas dans la pile b.
//
// @param b: pile b
// @return: pointeur vers l'élément avec le coût le plus bas
// =============================================================================

t_node	*find_cheapest_element(t_stack *b)
{
	t_node	*current;
	t_node	*cheapest;

	current = b->top;
	cheapest = current;
	while (current)
	{
		if (current->cost->total_cost < cheapest->cost->total_cost)
			cheapest = current;
		current = current->next;
	}
	return (cheapest);
}
