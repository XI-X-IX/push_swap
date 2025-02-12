/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledos-s <alex>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 19:31:19 by aledos-s          #+#    #+#             */
/*   Updated: 2025/02/10 12:42:48 by aledos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include "../libft/printf/ft_printf.h"
# include "../push_swap.h"
# include <stdio.h> /////////////////////////

# define BUFFER_SIZE	4

// RETURN CODES
# define SUCCESS		0
# define ERROR			1

// UTILITY FUNCTIONS
int		is_empty(t_stack *b);
int		get_next_line(int fd, char **line);

// CHECKER FUNCTIONS
int		execute_instruction(t_stack *a, t_stack *b, char *instruction);
int		read_and_execute(t_stack *a, t_stack *b);
void	print_stack(t_stack *stack, char *name); ////////////////////////

#endif
