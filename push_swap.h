/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledos-s <alex>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 22:20:24 by aledos-s          #+#    #+#             */
/*   Updated: 2025/01/21 11:20:11 by aledos-s         ###   ########.fr       */
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
# define ERR_ARGS	"🛑 May use more than 3 arguments"
# define ERR_MAP	"🛑 Error reading map file."
# define ERR_MLX	"🛑 Error initializing MLX."
# define ERR_OPEN	"🛑 Unable to open the file: "
# define ERR_PATH	"🛑 No valid path to exit !"

// COLORS
# define OK_COLOR		= "\033[0;32m"
# define NO_COLOR 		= "\033[0m"
# define WARN_COLOR 	= "\033[0;33m"
# define ERROR_COLOR 	= "\033[0;31m"

// STRUCTURES
typedef struct s_node
{
	int				data;
	struct s_node	*next;
}			t_node;

typedef struct s_stack
{
	int		data;
	t_node	*top ;
}			t_stack;

#endif