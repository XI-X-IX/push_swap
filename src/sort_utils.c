/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledos-s <alex>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:41:36 by aledos-s          #+#    #+#             */
/*   Updated: 2025/02/12 14:44:14 by aledos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_stack *a)
{
	t_node	*current;
	int		min;
	int		pos;
	int		min_pos;

	if (!a || !a->top)
		return (-1);

	current = a->top;
	min = current->data;
	min_pos = 0;
	pos = 0;
	while (current)
	{
		if (current->data < min)
		{
			min = current->data;
			min_pos = pos;
		}
		current = current->next;
		pos++;
	}
	return (min_pos);
}

int	find_max(t_stack *a)
{
	t_node	*current;
	int		max;
	int		pos;
	int		max_pos;

	if (!a || !a->top)
		return (-1);
	current = a->top;
	max = current->index;
	max_pos = 0;
	pos = 0;
	while (current)
	{
		if (current->index > max)
		{
			max = current->index;
			max_pos = pos;
		}
		current = current->next;
		pos++;
	}
	return (max_pos);
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
