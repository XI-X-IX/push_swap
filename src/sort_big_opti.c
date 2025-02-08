/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_opti.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledos-s <aledos-s@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:13:01 by aledos-s          #+#    #+#             */
/*   Updated: 2025/02/06 12:17:51 by aledos-s         ###   ########.fr       */
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

// =============================================================================
// calculate_cost
// =============================================================================
//
// Calcule le coût de déplacement d'un nœud pour le tri.
//
// Alloue une structure de coût pour le nœud et calcule le nombre de mouvements
// nécessaires pour déplacer le nœud à sa position cible dans les piles
// `a` et `b`.
// Le coût total est la somme des mouvements nécessaires pour les deux piles.
//
// @param node: pointeur vers le nœud pour lequel calculer le coût
// @param a: pointeur vers la pile `a`
// @param b: pointeur vers la pile `b`
// =============================================================================

void	calculate_cost(t_node *node, t_stack *a, t_stack *b)
{
	node->cost = malloc(sizeof(t_cost));
	if (!node->cost)
		return ;
	if (node->pos <= a->size / 2)
		node->cost->moves_a = node->pos;
	else
		node->cost->moves_a = -(a->size - node->pos);
	if (node->index <= b->size / 2)
		node->cost->moves_b = node->index;
	else
		node->cost->moves_b = -(b->size - node->index);
	node->cost->total_cost = abs(node->cost->moves_a)
		+ abs(node->cost->moves_b);
}
