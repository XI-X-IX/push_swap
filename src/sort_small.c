/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledos-s <aledos-s@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:02:43 by aledos-s          #+#    #+#             */
/*   Updated: 2025/02/05 17:28:03 by aledos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack *a)
{
	int	first;
	int	second;
	int	third;

	if (is_sorted(a))
		return ;
	first = a->top->data;
	second = a->top->next->data;
	third = a->top->next->next->data;
	if (first > second && second < third && third > first)
		sa(a);
	else if (first > second && second > third && third < first)
	{
		sa(a);
		rra(a);
	}
	else if (first < second && second > third && third > first)
	{
		sa(a);
		ra(a);
	}
	else if (first > second && second < third && third < first)
		ra(a);
	else if (first < second && second > third && third < first)
		rra(a);
}

void	sort_four(t_stack *a, t_stack *b)
{
	int	min;
	int	pos;

	min = find_min(a);
	pos = find_position(a, min);
	while (a->top->data != min)
	{
		if (pos <= a->size / 2)
			ra(a);
		else
			rra(a);
	}
	pb(a, b);
	sort_three(a);
	pa(a, b);
}

void	find_and_position_min(t_stack *a, t_stack *b)
{
	int	min;
	int	pos;

	min = find_min(a);
	pos = find_position(a, min);
	while (a->top->data != min)
	{
		if (pos <= a->size / 2)
			ra(a);
		else
			rra(a);
	}
	pb(a, b);
}

void	sort_five(t_stack *a, t_stack *b)
{
	int	i;
	int	min;

	i = 0;
	while (i < 2)
	{
		min = find_min(a);
		while (a->top->data != min)
		{
			if (find_position(a, min) <= a->size / 2)
				ra(a);
			else
				rra(a);
		}
		pb(a, b);
		i++;
	}
	sort_three(a);
	pa(a, b);
	pa(a, b);
}
