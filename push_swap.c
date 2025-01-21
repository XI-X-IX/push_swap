/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledos-s <alex>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 22:20:11 by aledos-s          #+#    #+#             */
/*   Updated: 2025/01/21 11:24:02 by aledos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_args(int ac, char **av)
{
	if (ac < 3)
		ft_printf("%s %s %s", OK_COLOR, ERR_ARGS, NO_COLOR);
}

int	main(int ac, char **av)
{
	t_stack	stack_a;
	t_stack	stack_b;

	check_args(ac, av);

}
