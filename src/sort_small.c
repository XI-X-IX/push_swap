/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledos-s <alex>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:02:43 by aledos-s          #+#    #+#             */
/*   Updated: 2025/02/13 23:32:35 by aledos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_to_target_a(t_stack *a, int target_pos)
{
	if (target_pos <= a->size / 2)
	{
		while (target_pos > 0)
		{
			ra(a);
			target_pos--;
		}
	}
	else
	{
		while (target_pos < a->size)
		{
			rra(a);
			target_pos++;
		}
	}
}

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
	int	min_pos;

	if (!a || !b || a->size < 4)
		return ;
	min_pos = find_min(a);
	rotate_to_target_a(a, min_pos);
	pb(a, b);
	sort_three(a);
	pa(a, b);
}

void	sort_five(t_stack *a, t_stack *b)
{
	int	i;
	int	min_pos;

	i = 0;
	while (i < 2)
	{
		min_pos = find_min(a);
		rotate_to_target_a(a, min_pos);
		pb(a, b);
		i++;
	}
	sort_three(a);
	pa(a, b);
	pa(a, b);
}
