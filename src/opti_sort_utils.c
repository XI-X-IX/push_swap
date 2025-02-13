/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti_sort_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledos-s <alex>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:44:01 by aledos-s          #+#    #+#             */
/*   Updated: 2025/02/14 00:26:17 by aledos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// =============================================================================
// find_min_max
// =============================================================================
//
// Trouve les valeurs minimales et maximales dans la pile a.
//
// @param a: pile a
// @param min: pointeur vers la valeur minimale
// @param max: pointeur vers la valeur maximale
// =============================================================================

void	find_min_max(t_stack *a, int *min, int *max)
{
	t_node	*current;

	current = a->top;
	*min = INT_MAX;
	*max = INT_MIN;
	while (current)
	{
		if (current->data < *min)
			*min = current->data;
		if (current->data > *max)
			*max = current->data;
		current = current->next;
	}
}

// =============================================================================
// get_element_position
// =============================================================================
//
// Obtient la position d'un élément dans la pile.
//
// @param stack: pile
// @param element: élément dont on veut connaître la position
// @return: position de l'élément dans la pile, ou -1 si l'élément n'est pas 
// 			trouvé
// =============================================================================

int	get_element_position(t_stack *stack, t_node *element)
{
	t_node	*current;
	int		position;

	current = stack->top;
	position = 0;
	while (current)
	{
		if (current == element)
			return (position);
		current = current->next;
		position++;
	}
	return (-1);
}

// =============================================================================
// find_min_position
// =============================================================================
//
// Trouve la position du plus petit élément dans la pile a.
//
// @param a: pile a
// @param min_val: pointeur vers la valeur minimale
// @return: position du plus petit élément dans la pile
// =============================================================================

static int	find_min_position(t_stack *a, int *min_val)
{
	t_node	*current;
	int		min_pos;
	int		i;

	current = a->top;
	min_pos = 0;
	i = 0;
	*min_val = current->data;
	while (i < a->size)
	{
		if (current->data < *min_val)
		{
			*min_val = current->data;
			min_pos = i;
		}
		current = current->next;
		i++;
	}
	return (min_pos);
}

// =============================================================================
// align_stack
// =============================================================================
//
// Aligne la pile a de sorte que le plus petit élément soit en haut.
//
// @param a: pile a
// =============================================================================

void	align_stack(t_stack *a)
{
	int		min_pos;
	int		min_val;

	if (!a || a->size <= 1)
		return ;
	min_pos = find_min_position(a, &min_val);
	if (min_pos > a->size / 2)
	{
		min_pos = a->size - min_pos;
		while (min_pos-- > 0)
			rra(a);
	}
	else
	{
		while (min_pos-- > 0)
			ra(a);
	}
}
