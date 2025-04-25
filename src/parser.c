#include "push_swap.h"

static int	has_duplicate(int ac, char **tab)
{
	int	i;
	int	j;

	i = 0;
	while (i < ac - 1)
	{
		j = i + 1;
		while (j < ac)
		{
			if (ft_atol(tab[i]) == ft_atol(tab[j]))
				return (ERROR);
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

static int	ft_tablen(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

static void	check_arg(int len, char **tab)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (check_limits(tab[i]) == ERROR)
		{
			ft_putendl_fd("Error", 2);
			exit(ERROR);
		}
		i++;
	}
	if (has_duplicate(len, tab) == ERROR)
	{
		ft_putendl_fd("Error", 2);
		exit(ERROR);
	}
}

static int	fill_tab(t_stack *a, int ac, char **tab)
{
	t_node	*node;
	int		i;

	i = ac - 1;
	while (i >= 0)
	{
		node = new_node(ft_atol(tab[i]));
		if (!node)
		{
			free_stack(a);
			return (ERROR);
		}
		node->next = a->top;
		if (a->top)
			a->top->prev = node;
		a->top = node;
		if (!a->last)
			a->last = node;
		a->size++;
		i--;
	}
	return (SUCCESS);
}

void	split_and_init(t_stack **a, t_stack **b, char **args)
{
	char	**tab;
	int		i;

	tab = ft_split(args[1], ' ');
	if (!tab || tab[0] == NULL || tab[0][0] == ' ')
	{
		free(tab);
		exit_error(*a, *b);
	}
	i = ft_tablen(tab);
	check_arg(i, tab);
	init_empty_stack(a);
	init_empty_stack(b);
	if (fill_tab(*a, i, tab) == ERROR)
	{
		free_stack(*a);
		free_stack(*b);
		free_split(tab);
		exit(ERROR);
	}
	free_split(tab);
}
