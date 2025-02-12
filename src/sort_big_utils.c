/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledos-s <alex>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 11:43:17 by aledos-s          #+#    #+#             */
/*   Updated: 2025/02/11 14:37:52 by aledos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_all_costs(t_stack *stack)
{
	t_node	*current;

	current = stack->top;
	while (current)
	{
		free_cost(current);
		current = current->next;
	}
}

void	cleanup_costs(t_stack *b)
{
	t_node	*current;

	current = b->top;
	while (current)
	{
		free_cost(current);
		current = current->next;
	}
}

int	abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}
