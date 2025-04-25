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
	if (!is_sorted(a))
	{
		sort_stack(a, b);
	}
	free_stack(a);
	free_stack(b);
	return (SUCCESS);
}
