#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include "../libft/printf/ft_printf.h"
# include "../push_swap.h"

# define BUFFER_SIZE	4

// RETURN CODES
# define SUCCESS		0
# define ERROR			1

// UTILITY FUNCTIONS
void	ok_end(void);
int		is_empty(t_stack *b);
int		get_next_line(int fd, char **line);

// CHECKER FUNCTIONS
int		execute_instruction(t_stack *a, t_stack *b, char *instruction);
int		read_and_execute(t_stack *a, t_stack *b);

#endif
