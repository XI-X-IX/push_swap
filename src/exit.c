/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledos-s <alex>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 22:41:03 by aledos-s          #+#    #+#             */
/*   Updated: 2025/02/11 14:52:41 by aledos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stacks(t_stack *a, t_stack *b)
{
	if (a)
		free_stack(a);
	if (b)
		free_stack(b);
}

void	free_cost(t_node *node)
{
	if (node && node->cost)
	{
		free(node->cost);
		node->cost = NULL;
	}
}

void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*next;

	if (!stack)
		return ;
	current = stack->top;
	while (current)
	{
		next = current->next;
		free_cost(current);
		free(current);
		current = next;
	}
	free(stack);
}

void	free_split(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	exit_error(t_stack *a, t_stack *b)
{
	ft_putendl_fd("Error", 2);
	free_stacks(a, b);
	exit (ERROR);
}
