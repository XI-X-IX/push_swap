/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledos-s <aledos-s@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 22:20:24 by aledos-s          #+#    #+#             */
/*   Updated: 2025/01/29 11:52:34 by aledos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h> // write & read
# include <stdlib.h> // malloc & exit
# include "libft/libft.h"
# include "libft/printf/ft_printf.h"
# include <stdio.h> // A ENLEVER

// ERRORS
# define ERR_ARGS		"🛑 May use more than 3 arguments"
# define ERR_DOUBLE		"🛑 Same number found"
# define ERR_DIGIT		"🛑 Error : invalid digit "
# define ERR_MALLOC		"🛑 Error : malloc "
# define ERR_PATH		"🛑 No valid path to exit !"

// COLORS
# define OK_COLOR		"\033[0;32m"
# define NO_COLOR		"\033[0m"
# define WARN_COLOR		"\033[0;33m"
# define ERROR_COLOR	"\033[0;31m"

// RETURN CODES
# define SUCCESS		0
# define ERROR			1

# define TRUE			1
# define FALSE			0

// STRUCTURES
typedef struct s_node
{
	int				data;
	struct s_node	*next;
}				t_node;

typedef struct s_stack
{
	int				size;
	struct s_node	*top;
}				t_stack;

#endif
