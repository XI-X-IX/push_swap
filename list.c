/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledos-s <alex>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 23:06:07 by aledos-s          #+#    #+#             */
/*   Updated: 2025/01/21 13:36:51 by aledos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// ATOI & PRINTF DANS CETTE PAGE //

/*typedef struct s_node
{
	int				data;
	struct s_node	*next;
}			t_node;

typedef struct s_stack
{
	int		data;
	t_node	*top ;
}			t_stack;

void	pa(t_stack stack, t_node top)
{
	// Function implementation goes here
}*/

void	add_front(t_stack *stack, int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->data = value;
	new_node->next = stack->top;
	stack->top = new_node;
}

void	add_back(t_stack *stack, int value)
{
	t_node	*last_node;
	t_node	*current;

	last_node = malloc(sizeof(t_node));
	if (!last_node)
		return;
	last_node->data = value;
	last_node->next = NULL;

	if (stack->top == NULL)
	{
		stack->top = last_node;
		return;
	}
	current = stack->top;
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = last_node;
}

int count_nodes(t_stack *stack)
{
	int count;
	t_node *current;

	count = 0;
	current = stack->top;
	while (current != NULL)
	{
		count++;
		current = current->next;
	}
	return (count);
}

int	fill_stack(t_stack *stack, char **av)
{
	t_node *current;
	int	i;


}

void	print_stack(t_stack *stack)
{
	t_node	*current;

	current = stack->top;
	while (current != NULL)
	{
		printf("%d\n", current->data);
		current = current->next;
	}
}

void delete_node(t_stack *stack, int value)
{
	t_node	*current;
	t_node	*prev;

	if (stack->top == NULL)
		return;

	if (stack->top->data == value)
	{
		current = stack->top;
		stack->top = stack->top->next;
		free(current);
		return;
	}
	current = stack->top;
	prev = stack->top;
	while (current != NULL && current->data != value)
	{
		prev = current;
		current = current->next;
	}
	if (current != NULL)
	{
		prev->next = current->next;
		free(current);
	}
}

int main(int ac, char **av)
{
	t_stack stack;

	stack.top = NULL;

	add_back(&stack, 3);
	add_back(&stack, 2);
	add_back(&stack, 1);
	add_front(&stack, 0);

	printf("nb de noeud : %d\n", count_nodes(&stack));
	printf("Contenu de la stack :\n");
	print_stack(&stack);
	return (0);
}
