/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledos-s <alex>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 00:11:07 by aledos-s          #+#    #+#             */
/*   Updated: 2025/02/12 14:55:47 by aledos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "push_swap.h"

void    print_stack(t_stack *a)
{
	t_node  *current;

	if (!a)
	{
		printf("\nEmpty stack\n");
		return ;
	}
	printf("\nStack info:\n");
	printf("Size: %d | Median: %d | Chunks: %d\n", a->size, a->median, a->chunks);
	printf("---------------\n");
	
	current = a->top;
	while (current)
	{
		printf("%-7d\n", current->data);
		current = current->next;
	}
	printf("---------------\n");
}

void    print_stacks(t_stack *a, t_stack *b)
{
	t_node  *current_a;
	t_node  *current_b;
	int     max_len;
	int     size_a;
	int     size_b;

	size_a = a ? a->size : 0;
	size_b = b ? b->size : 0;
	max_len = size_a > size_b ? size_a : size_b;
	current_a = a ? a->top : NULL;
	current_b = b ? b->top : NULL;

	printf("\nStack A  |  Stack B\n");
	printf("-------------------\n");
	
	if (a || b)
	{
		if (a)
			printf("Size: %d, Med: %d, Ch: %d", a->size, a->median, a->chunks);
		printf("  |  ");
		if (b)
			printf("Size: %d, Med: %d, Ch: %d", b->size, b->median, b->chunks);
		printf("\n-------------------\n");
	}

	while (max_len--)
	{
		if (current_a)
		{
			printf("%-7d ", current_a->data);
			current_a = current_a->next;
		}
		else
			printf("        ");
		printf("|  ");
		if (current_b)
		{
			printf("%-7d", current_b->data);
			current_b = current_b->next;
		}
		printf("\n");
	}
	printf("-------------------\n");
}



void    prints(t_stack *a)
{
	t_node  *current;

	if (!a || !a->top)
	{
		printf("\n");
		return ;
	}
	current = a->top;
	while (current)
	{
		printf("%d\t", current->data);
		if (current->next)
			printf(" ");
		current = current->next;
	}
	printf("\n");
}