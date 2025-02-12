/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledos-s <alex>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 22:20:11 by aledos-s          #+#    #+#             */
/*   Updated: 2025/02/12 14:56:19 by aledos-s         ###   ########.fr       */
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
	print_stacks(a, b);
	printf("Stack A : ");
	prints(a);
	printf("Stack B : ");
	prints(b);
	if (!is_sorted(a))
	{
		sort_stack(a, b);
	}
	print_stacks(a, b);
	printf("Stack A : ");
	prints(a);
	printf("Stack B : ");
	prints(b);
	if (is_sorted(a))
		printf("JOB DONE");
	free_stack(a);
	free_stack(b);

	return (SUCCESS);
}
