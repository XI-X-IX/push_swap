/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledos-s <aledos-s@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 11:34:38 by aledos-s          #+#    #+#             */
/*   Updated: 2025/02/06 11:40:44 by aledos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_numbers(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static void	sort_array(int *numbers, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (numbers[j] > numbers[j + 1])
				swap_numbers(&numbers[j], &numbers[j + 1]);
			j++;
		}
		i++;
	}
}

static int	*copy_stack_to_array(t_stack *stack)
{
	int		*numbers;
	t_node	*current;
	int		i;

	numbers = malloc(sizeof(int) * stack->size);
	if (!numbers)
		return (NULL);
	current = stack->top;
	i = 0;
	while (current)
	{
		numbers[i] = current->data;
		current = current->next;
		i++;
	}
	return (numbers);
}

// =============================================================================
// find_median
// =============================================================================
//
// Calcule la médiane des éléments de la pile `stack`.
//
// Copie les éléments de la pile dans un tableau, trie le tableau, et
// détermine la médiane. La médiane est ensuite stockée dans la structure
// de la pile. Libère la mémoire allouée pour le tableau.
//
// @param stack: pointeur vers la pile dont la médiane doit être calculée
// =============================================================================

void	find_median(t_stack *stack)
{
	int	*numbers;

	numbers = copy_stack_to_array(stack);
	if (!numbers)
		return ;
	sort_array(numbers, stack->size);
	stack->median = numbers[stack->size / 2];
	free(numbers);
}
