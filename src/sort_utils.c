/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledos-s <aledos-s@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:41:36 by aledos-s          #+#    #+#             */
/*   Updated: 2025/02/04 10:54:21 by aledos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_stack *a)
{
	t_node	*i;
	int		min;

	if (!a || !a->top)
		return (INT_MAX);
	i = a->top;
	min = i->data;
	while (i)
	{
		if (i->data < min)
		{
			min = i->data;
		}
		i = i->next;
	}
	return (min);
}

int	find_max(t_stack *a)
{
	int		max;
	t_node	*i;

	if (!a || !a->top)
		return (INT_MIN);
	i = a->top;
	max = i->data;
	while (i)
	{
		if (i->data > max)
			max = i->data;
		i = i->next;
	}
	return (max);
}

int	find_position(t_stack *a, int min)
{
	t_node	*i;
	int		position;

	if (!a || !a->top)
		return (-1);
	i = a->top;
	position = 0;
	while (i)
	{
		if (i->data == min)
			return (position);
		i = i->next;
		position++;
	}
	return (position);
}

void	sort_stack(t_stack *a, t_stack *b)
{
	if (a->size == 2)
	{
		if (a->top->data > a->top->next->data)
			sa(a);
	}
	else if (a->size == 3)
		sort_three(a);
	else if (a->size == 4)
		sort_four(a, b);
	else if (a->size == 5)
		sort_five(a, b);
	else
		sort_big(a, b);
}

int	is_sorted(t_stack *a)
{
	t_node	*i;

	if (!a || !a->top)
		return (FALSE);
	i = a->top;
	while (i->next)
	{
		if (i->data > i->next->data)
			return (FALSE);
		i = i->next;
	}
	return (TRUE);
}
