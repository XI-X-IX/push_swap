/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledos-s <alex>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:41:06 by aledos-s          #+#    #+#             */
/*   Updated: 2025/02/12 14:48:17 by aledos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int    get_index_at(t_stack *s, int pos)
{
    t_node  *current;
    int     i;

    if (!s || !s->top)
        return (-1);
    current = s->top;
    i = 0;
    while (current && i < pos)
    {
        current = current->next;
        i++;
    }
    if (!current)
        return (-1);
    return (current->index);
}

static int    get_target(t_stack *a, int b_val)
{
    t_node  *current;
    t_node  *next;
    int     pos;
    int     max_pos;

    if (!a->top)
        return (0);
    current = a->top;
    pos = 0;
    max_pos = find_max(a);
    if (b_val > a->top->index && b_val > get_index_at(a, max_pos))
        return ((max_pos + 1) % a->size);
    while (current && current->next)
    {
        next = current->next;
        if (b_val > current->index && b_val < next->index)
            return (pos + 1);
        current = current->next;
        pos++;
    }
    return (0);
}

static int    get_cost(t_stack *s, int pos)
{
	if (pos <= s->size / 2)
		return (pos);
	return (s->size - pos);
}

static void    do_rotations(t_stack *s, int cost, char stack_name)
{
	while (cost > 0)
	{
		if (stack_name == 'a')
			ra(s);
		else
			rb(s);
		cost--;
	}
}

static void    move_stack(t_stack *s, int pos, char stack_name)
{
	int cost;

	cost = get_cost(s, pos);
	do_rotations(s, cost, stack_name);
}

void    sort_big(t_stack *a, t_stack *b)
{
    int     target_pos;

    push_to_b(a, b);
    sort_three(a);
    while (b->size > 0)
    {
        target_pos = get_target(a, b->top->index);
        move_stack(a, target_pos, 'a');
        pa(a, b);
        if (a->top->index > a->top->next->index)
            ra(a);
    }
}