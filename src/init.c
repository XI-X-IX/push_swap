/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledos-s <alex>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 20:33:18 by aledos-s          #+#    #+#             */
/*   Updated: 2025/02/13 12:28:25 by aledos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// =============================================================================
// init_cost
// =============================================================================
//
// Alloue et initialise une structure t_cost.
//
// Retourne un pointeur vers la nouvelle structure t_cost allouée et
// initialisée à 0. Si l'allocation échoue, retourne NULL.
//
// @return: pointeur vers la structure t_cost, ou NULL si l'allocation échoue
// =============================================================================

t_cost	*init_cost(void)
{
	t_cost	*cost;

	cost = malloc(sizeof(t_cost));
	if (!cost)
		return (NULL);
	ft_memset(cost, 0, sizeof(t_cost));
	return (cost);
}

// =============================================================================
// init_empty_stack
// =============================================================================
//
// Initialise une pile vide.
//
// Alloue de la mémoire pour une nouvelle pile et initialise ses champs.
// Si l'allocation de mémoire échoue, la fonction ne fait rien.
//
// @param stack: double pointeur vers la pile à initialiser
// =============================================================================

void	init_empty_stack(t_stack **stack)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return ;
	ft_memset(new, 0, sizeof(t_stack));
	*stack = new;
}

// =============================================================================
// new_node
// =============================================================================
//
// Crée un nouveau nœud avec la valeur donnée et l'initialise.
//
// Alloue de la mémoire pour un nouveau nœud et initialise ses champs.
// Si l'allocation de mémoire échoue, retourne NULL.
//
// @param data: valeur à stocker dans le nœud
// @return: pointeur vers le nouveau nœud, ou NULL si l'allocation échoue
// =============================================================================

t_node	*new_node(int data)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	ft_memset(new, 0, sizeof(t_node));
	new->data = data;
	new->cost = init_cost();
	if (!new->cost)
	{
		free(new);
		return (NULL);
	}
	return (new);
}

// =============================================================================
// fill_stack
// =============================================================================
//
// Remplit une pile avec les arguments passés en paramètres.
//
// Parcourt les arguments en ordre inverse, crée un nouveau nœud pour chaque
// argument, et insère le nœud au sommet de la pile. Si une allocation échoue,
// libère la pile et retourne une erreur.
//
// @param stack: pointeur vers la pile à remplir
// @param ac: nombre d'arguments
// @param av: tableau d'arguments
// @return: SUCCESS si la pile est remplie avec succès, sinon ERROR
// =============================================================================

int	fill_stack(t_stack *a, int ac, char **av)
{
	t_node	*node;
	int		i;

	i = ac - 1;
	while (i > 0)
	{
		node = new_node(ft_atol(av[i]));
		if (!node)
		{
			free_stack(a);
			return (ERROR);
		}
		node->next = a->top;
		if (a->top)
			a->top->prev = node;
		a->top = node;
		if (!a->last)
			a->last = node;
		a->size++;
		i--;
	}
	return (SUCCESS);
}

// =============================================================================
// init_stacks
// =============================================================================
//
// Initialise deux piles avec les arguments passés en paramètres.
//
// Initialise une pile vide pour `a`, la remplit avec les arguments, et
// initialise une pile vide pour `b`. Si une allocation échoue ou si le
// remplissage de la pile `a` échoue, libère les piles et retourne une erreur.
//
// @param a: double pointeur vers la pile `a` à initialiser
// @param b: double pointeur vers la pile `b` à initialiser
// @param ac: nombre d'arguments
// @param av: tableau d'arguments
// @return: SUCCESS si les piles sont initialisées avec succès, sinon ERROR
// =============================================================================

int	init_stacks(t_stack **a, t_stack **b, int ac, char **av)
{
	init_empty_stack(a);
	if (!*a)
		return (ERROR);
	if (fill_stack(*a, ac, av) == ERROR)
	{
		free_stack(*a);
		return (ERROR);
	}
	init_empty_stack(b);
	if (!*b)
	{
		free_stack(*a);
		return (ERROR);
	}
	return (SUCCESS);
}
