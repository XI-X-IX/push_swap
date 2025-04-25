#include "push_swap.h"

void	sort_stack(t_stack *a, t_stack *b)
{
	if (a->size == 2)
	{
		if (a->top->data > a->top->next->data)
			sa(a);
	}
	else if (a->size == 3)
		sort_three(a);
	else if (a->size == 4)
		sort_four(a, b);
	else if (a->size == 5)
		sort_five(a, b);
	else
		smart_push_swap(a, b);
}
