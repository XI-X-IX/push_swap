/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledos-s <alex>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:41:36 by aledos-s          #+#    #+#             */
/*   Updated: 2025/02/13 23:32:18 by aledos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_stack *stack)
{
	t_node	*current;
	t_node	*min_node;
	int		min_pos;
	int		current_pos;

	if (!stack || !stack->top)
		return (0);
	current = stack->top;
	min_node = current;
	min_pos = 0;
	current_pos = 0;
	while (current)
	{
		if (current->data < min_node->data)
		{
			min_node = current;
			min_pos = current_pos;
		}
		current = current->next;
		current_pos++;
	}
	return (min_pos);
}

int	find_max(t_stack *stack)
{
	t_node	*current;
	t_node	*max_node;

	if (!stack || !stack->top)
		return (0);
	current = stack->top;
	max_node = current;
	while (current)
	{
		if (current->data > max_node->data)
			max_node = current;
		current = current->next;
	}
	return (max_node->pos);
}

int	find_position(t_stack *a, int index)
{
	t_node	*i;
	int		position;

	if (!a || !a->top)
		return (-1);
	i = a->top;
	position = 0;
	while (i)
	{
		if (i->index == index)
			return (position);
		i = i->next;
		position++;
	}
	return (-1);
}

int	is_sorted(t_stack *stack)
{
	t_node	*current;

	if (!stack || !stack->top)
		return (1);
	current = stack->top;
	while (current && current->next)
	{
		if (current->data > current->next->data)
			return (0);
		current = current->next;
	}
	return (1);
}
