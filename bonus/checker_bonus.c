/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledos-s <aledos-s@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 23:57:38 by aledos-s          #+#    #+#             */
/*   Updated: 2025/02/07 16:25:55 by aledos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void print_detailed_stack(t_stack *stack, const char *message)
{
    t_node *current = stack->top;

    ft_printf("%s (size: %d): ", message, stack->size);
    while (current)
    {
        ft_printf("[%d(pos:%d)] ", current->data, current->pos);
        current = current->next;
    }
    ft_printf("\n");
}

// =========================================
// execute_instruction
// =========================================
//
// Execute une instruction sur les piles
//
// @param a: pile a
// @param b: pile b
// @param instruction: commande à executer
// @return: SUCCESS ou ERROR
// =========================================

int	execute_instruction(t_stack *a, t_stack *b, char *instruction)
{
	if (ft_strcmp(instruction, "sa\n") == 0)
		sa(a);
	else if (ft_strcmp(instruction, "sb\n") == 0)
		sb(b);
	else if (ft_strcmp(instruction, "ss\n") == 0)
		ss(a, b);
	else if (ft_strcmp(instruction, "pa\n") == 0)
		pa(a, b);
	else if (ft_strcmp(instruction, "pb\n") == 0)
		pb(a, b);
	else if (ft_strcmp(instruction, "ra\n") == 0)
		ra(a);
	else if (ft_strcmp(instruction, "rb\n") == 0)
		rb(b);
	else if (ft_strcmp(instruction, "rr\n") == 0)
		rr(a, b);
	else if (ft_strcmp(instruction, "rra\n") == 0)
		rra(a);
	else if (ft_strcmp(instruction, "rrb\n") == 0)
		rrb(b);
	else if (ft_strcmp(instruction, "rrr\n") == 0)
		rrr(a, b);
	else
		return (ERROR);
	return (SUCCESS);
}

// =========================================
// read_and_execute
// =========================================
//
// Lit les instructions et les execute
//
// @param a: pile a
// @param b: pile b
// @return: SUCCESS ou ERROR
// =========================================

int	read_and_execute(t_stack *a, t_stack *b)
{
	char	*line;
	int		byte;

	while (1)
	{
		byte = get_next_line(0, &line);
		if (byte < 0 || !line)
			return (ERROR);
		if (byte == 0)
		{
			free(line);
			break ;
		}
		if (execute_instruction(a, b, line) == ERROR)
		{
			free(line);
			return (ERROR);
		}
		free(line);
	}
	return (SUCCESS);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	if (ac < 2)
		return (0);
	if (init_stacks(&a, &b, ac, av) == ERROR)
	{
		ft_putendl_fd("Error", 2);
		return (ERROR);
	}
	if (read_and_execute(a, b) == ERROR)
	{
		ft_putendl_fd("Error", 2);
		free_stacks(a, b);
		return (ERROR);
	}
	if (is_sorted(a) && is_empty(b))
		ft_putendl_fd("\033[0;32mOK\033[0m", 1);
	else
		ft_putendl_fd("\033[0;31mKO\033[0m", 1);
	free_stacks(a, b);
	return (SUCCESS);
}
