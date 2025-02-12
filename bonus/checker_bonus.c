/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledos-s <alex>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 23:57:38 by aledos-s          #+#    #+#             */
/*   Updated: 2025/02/10 17:50:18 by aledos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int	first_exe(t_stack *a, t_stack *b, char *instruction)
{
	if (ft_strstr(instruction, "sa"))
		swap(a);
	else if (ft_strstr(instruction, "sb"))
		swap(b);
	else if (ft_strstr(instruction, "ss"))
	{
		swap(a);
		swap(b);
	}
	else if (ft_strstr(instruction, "pa"))
		push(b, a);
	else if (ft_strstr(instruction, "pb"))
		push(a, b);
	else
		return (0);
	return (1);
}

static int	second_exe(t_stack *a, t_stack *b, char *instruction)
{
	if (ft_strstr(instruction, "ra") && !ft_strstr(instruction, "rra"))
		rotate(a);
	else if (ft_strstr(instruction, "rb") && !ft_strstr(instruction, "rrb"))
		rotate(b);
	else if (ft_strstr(instruction, "rr") && !ft_strstr(instruction, "rrr"))
	{
		rotate(a);
		rotate(b);
	}
	else if (ft_strstr(instruction, "rra"))
		rev_rot(a);
	else if (ft_strstr(instruction, "rrb"))
		rev_rot(b);
	else if (ft_strstr(instruction, "rrr"))
	{
		rev_rot(a);
		rev_rot(b);
	}
	else
		return (0);
	return (1);
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
	if (!first_exe(a, b, instruction) && !second_exe(a, b, instruction))
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
		print_stack(a, "A");
		print_stack(b, "B");  // Optionnel
		byte = get_next_line(0, &line);
		if (byte < 0 || !line)
			return (ERROR);
		if (byte == 0)
		{
			free(line);
			break ;
		}
		if (ft_strlen(line) > 1 && execute_instruction(a, b, line) == ERROR)
		{
			free(line);
			return (ERROR);
		}
		free(line);
	}
	return (SUCCESS);
}

void print_stack(t_stack *stack, char *name)
{
    t_node *current;

    printf("\nStack %s:", name);
    if (!stack || !stack->top || stack->size == 0)
    {
        printf(" (empty)\n");
        return;
    }
    current = stack->top;
    while (current)
    {
        printf(" %d", current->data);
        current = current->next;
    }
    printf("\n");
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	if (ac == 1)
		return (0);
	else if (ac == 2)
		split_and_init(&a, &b, av);
	else
	{
		check_args(ac, av);
		if (init_stacks(&a, &b, ac, av) == ERROR)
			exit_error(a, b);
	}
	if (read_and_execute(a, b) == ERROR)
	{
		ft_putendl_fd("Error", 2);
		free_stacks(a, b);
		return (ERROR);
	}
	print_stack(a, "A");
	print_stack(b, "B");
	if (is_sorted(a) && is_empty(b))
		ft_putendl_fd("\033[0;32mOK\033[0m", 1);
	else
		ft_putendl_fd("\033[0;31mKO\033[0m", 1);
	free_stacks(a, b);
	return (SUCCESS);
}
