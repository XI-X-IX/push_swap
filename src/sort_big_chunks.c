/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_chunks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledos-s <alex>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:17:19 by aledos-s          #+#    #+#             */
/*   Updated: 2025/02/12 14:29:43 by aledos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int    is_swap_needed_b(t_stack *b)
{
    if (!b->top || !b->top->next)
        return (0);
    if (b->top->index < b->top->next->index)
        return (1);
    return (0);
}

void    push_to_b(t_stack *a, t_stack *b)
{
    t_node  *current;
    int     max_keep;
    int     pushed;

    max_keep = a->size - 3;
    pushed = 0;
    while (pushed < max_keep)
    {
        current = a->top;
        if (current->index < max_keep)
        {
            pb(a, b);
            if (is_swap_needed_b(b))
                sb(b);
			else
				rb(b);
            pushed++;
        }
        else
            ra(a);
    }
}
