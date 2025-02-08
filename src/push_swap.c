/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledos-s <aledos-s@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 22:20:11 by aledos-s          #+#    #+#             */
/*   Updated: 2025/02/07 15:01:19 by aledos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// =============================================================================
// main
// =============================================================================

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
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
	// printf("Stack A initialized: ");
	// print_stack(a);
	// printf("Stack B initialized: ");
	// print_stack(b);
	if (!is_sorted(a))
	{
		sort_stack(a, b);
		// printf("Sorting completed!\n");
		// ft_printf("STACK AT THE END :\n");
		// print_stacks(a, b);
	}
	free_stack(a);
	free_stack(b);
	return (SUCCESS);
}
