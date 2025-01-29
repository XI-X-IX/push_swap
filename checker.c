/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledos-s <aledos-s@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 23:57:38 by aledos-s          #+#    #+#             */
/*   Updated: 2025/01/29 00:04:12 by aledos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// =========================================
// checker.h
// =========================================

#include <unistd.h>

// Les mêmes structures que push_swap
typedef struct s_node
{
    int             data;
    struct s_node   *next;
}   t_node;

typedef struct s_stack
{
    t_node  *top;
    int     size;
}   t_stack;

// =========================================
// checker.c
// =========================================

// Pour lire les instructions
#define BUFFER_SIZE 4

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

int execute_instruction(t_stack *a, t_stack *b, char *instruction)
{
    if (ft_strcmp(instruction, "sa\n") == 0)
        return (sa(a));
    else if (ft_strcmp(instruction, "sb\n") == 0)
        return (sb(b));
    else if (ft_strcmp(instruction, "ss\n") == 0)
        return (ss(a, b));
    else if (ft_strcmp(instruction, "pa\n") == 0)
        return (pa(a, b));
    else if (ft_strcmp(instruction, "pb\n") == 0)
        return (pb(a, b));
    else if (ft_strcmp(instruction, "ra\n") == 0)
        return (ra(a));
    else if (ft_strcmp(instruction, "rb\n") == 0)
        return (rb(b));
    else if (ft_strcmp(instruction, "rr\n") == 0)
        return (rr(a, b));
    else if (ft_strcmp(instruction, "rra\n") == 0)
        return (rra(a));
    else if (ft_strcmp(instruction, "rrb\n") == 0)
        return (rrb(b));
    else if (ft_strcmp(instruction, "rrr\n") == 0)
        return (rrr(a, b));
    return (ERROR);
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

int read_and_execute(t_stack *a, t_stack *b)
{
    char    *line;
    int     ret;

    while ((ret = get_next_line(0, &line)) > 0)
    {
        if (execute_instruction(a, b, line) == ERROR)
        {
            free(line);
            return (ERROR);
        }
        free(line);
    }
    return (SUCCESS);
}

int main(int ac, char **av)
{
    t_stack *a;
    t_stack *b;

    if (ac < 2)
        return (0);

    // Initialisation des piles (comme dans push_swap)
    if (init_stack(&a, ac, av) == ERROR)
    {
        ft_putstr_fd("Error\n", 2);
        return (ERROR);
    }
    b = create_empty_stack();

    // Lecture et exécution des instructions
    if (read_and_execute(a, b) == ERROR)
    {
        ft_putstr_fd("Error\n", 2);
        free_stacks(a, b);
        return (ERROR);
    }

    // Vérification du résultat
    if (is_sorted(a) && is_empty(b))
        ft_putstr_fd("OK\n", 1);
    else
        ft_putstr_fd("KO\n", 1);

    free_stacks(a, b);
    return (SUCCESS);
}
