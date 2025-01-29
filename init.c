/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledos-s <aledos-s@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 20:33:18 by aledos-s          #+#    #+#             */
/*   Updated: 2025/01/29 12:28:47 by aledos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// =============================================================================
// init_empty_stack
// =============================================================================
//
// Initialise une pile vide.
//
// Alloue de la mémoire pour une nouvelle pile et initialise ses champs.
// Si l'allocation de mémoire échoue, la fonction ne fait rien.
//
// @param b: double pointeur vers la pile à initialiser
// =============================================================================


void	init_empty_stack(t_stack **b)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return ;
	new->top = NULL;
	new->size = 0;
	*b = new;
}

// =============================================================================
// new_node
// =============================================================================
//
// Crée un nouveau nœud avec la valeur
// donnée et l'initialise.
//
// @param data: valeur à stocker dans le nœud
// @return: pointeur vers le nouveau nœud
//         NULL si l'allocation échoue
// =============================================================================

t_node	*new_node(int data)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->data = data;
	new->next = NULL;
	return (new);
}

// =============================================================================
// init_stack
// =============================================================================
//
// Initialise une pile avec les arguments
// passés en paramètres.
//
// @param stack: pointeur vers la pile
// @param ac: nombre d'arguments
// @param av: tableau d'arguments
// =============================================================================

void	init_stack(t_stack **a, int ac, char **av)
{
	t_stack	*new_stack;
	t_node	*node;
	int		i;

	new_stack = malloc(sizeof(t_stack));
	if (!new_stack)
		return ;

	new_stack->top = NULL;
	new_stack->size = 0;
	i = ac - 1;
	while (i > 0)
	{
		node = new_node(ft_atoi(av[i]));
		if (!node)
			return ;
		node->next = new_stack->top;
		new_stack->top = node;
		new_stack->size++;
		i--;
	}
	*a = new_stack;
}
