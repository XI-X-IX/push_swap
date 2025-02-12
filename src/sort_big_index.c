/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_index.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledos-s <alex>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:34:47 by aledos-s          #+#    #+#             */
/*   Updated: 2025/02/11 13:52:22 by aledos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// =============================================================================
// index_stack
// =============================================================================
//
// Indexe les éléments d'une pile.
//
// Parcourt chaque élément de la pile et lui attribue un index basé sur sa
// position relative par rapport aux autres éléments. L'index est déterminé
// en comptant le nombre d'éléments ayant une valeur inférieure à celle de
// l'élément courant.
//
// @param a: pointeur vers la pile à indexer
// =============================================================================

void	index_stack(t_stack *a)
{
	t_node	*current;
	t_node	*compare;
	int		index;

	current = a->top;
	while (current)
	{
		index = 0;
		compare = a->top;
		while (compare)
		{
			if (current->data > compare->data)
				index++;
			compare = compare->next;
		}
		current->index = index;
		current = current->next;
	}
}