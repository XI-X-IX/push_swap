#
#	 __  __    __    _  _  ____  ____  ____  __    ____
#	(  \/  )  /__\  ( )/ )( ___)( ___)(_  _)(  )  ( ___)
#	 )    (  /(__)\  )  (  )__)  )__)  _)(_  )(__  )__)
#	(_/\/\_)(__)(__)(_)\_)(____)(__)  (____)(____)(____)    aledos-s
#

#•❅──────✧❅✦❅✧──────❅••❅──────✧❅✦❅✧──NAME──✧❅✦❅✧──────❅••❅──────✧❅✦❅✧──────❅•#

NAME := push_swap

#•❅──────✧❅✦❅✧──────❅••❅──────✧❅✦❅✧───CC───✧❅✦❅✧──────❅••❅──────✧❅✦❅✧──────❅•#

CC := gcc
CFLAGS := -Wall -Wextra -Werror

# System Detection
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Linux)

endif
ifeq ($(UNAME_S), Darwin)

endif

SOURCE 		=  push_swap.c errors.c \
			 \

OBJDIR 		= obj
OBJS 		= $(SOURCE:%.c=$(OBJDIR)/%.o)
DIRS 		= $(OBJDIR)

LIBFT 		= libft/


INCLUDES 	= -Ilibft

#•❅──────✧❅✦❅✧──────❅••❅──────✧❅✦❅✧─RULES─✧❅✦❅✧──────❅••❅──────✧❅✦❅✧──────❅•#

all: 		$(NAME)

$(NAME): 	makedirs $(OBJS)
			@make -C $(LIBFT) >/dev/null
			@$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT) -lft $(MLXFLAGS) -o $(NAME)
			@echo "\n\n$(OK_COLOR)push_swap compiled..\n\n$(NO_COLOR)"

makedirs:
			@mkdir -p $(DIRS)

$(OBJDIR)/%.o: %.c $(DEPS)
			@$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

clean:
			@make clean -C $(LIBFT) >/dev/null
			@rm -rf $(OBJDIR)
			@echo "\n\n$(WARN_COLOR)Cleaned object files\n$(NO_COLOR)"

fclean:		clean
			@make fclean -C $(LIBFT) >/dev/null
			@rm -rf $(NAME)
			@echo "\n$(ERROR_COLOR)Program removed\n\n$(NO_COLOR)"

re:			fclean all

#•❅──────✧❅✦❅✧──────❅••❅──────✧❅✦❅✧─IGNORE─✧❅✦❅✧──────❅••❅──────✧❅✦❅✧──────❅•#

.PHONY: all clean fclean re makedirs

#•❅──────✧❅✦❅✧──────❅••❅──────✧❅✦❅✧─COLOR──✧❅✦❅✧──────❅••❅──────✧❅✦❅✧──────❅•#

NO_COLOR = \033[0m
OK_COLOR = \033[0;32m
ERROR_COLOR = \033[0;31m
WARN_COLOR = \033[0;33m
