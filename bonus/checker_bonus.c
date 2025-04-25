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
	if (ft_strstr(instruction, "rrr"))
	{
		rev_rot(a);
		rev_rot(b);
	}
	else if (ft_strstr(instruction, "rra"))
		rev_rot(a);
	else if (ft_strstr(instruction, "rrb"))
		rev_rot(b);
	else if (ft_strstr(instruction, "rr"))
	{
		rotate(a);
		rotate(b);
	}
	else if (ft_strstr(instruction, "ra"))
		rotate(a);
	else if (ft_strstr(instruction, "rb"))
		rotate(b);
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
		byte = get_next_line(0, &line);
		if (byte < 0 || !line)
			return (ERROR);
		if (byte == 0)
		{
			free(line);
			break ;
		}
		if (ft_strlen(line) > 1)
		{
			if (execute_instruction(a, b, line) == ERROR)
			{
				free(line);
				return (ERROR);
			}
		}
		free(line);
	}
	return (SUCCESS);
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
	if (is_sorted(a) && is_empty(b))
		ok_end();
	else
		ft_putendl_fd("\033[0;31mKO\033[0m", 1);
	free_stacks(a, b);
	return (SUCCESS);
}
