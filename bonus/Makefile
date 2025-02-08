#
#	 __  __    __    _  _  ____  ____  ____  __    ____
#	(  \/  )  /__\  ( )/ )( ___)( ___)(_  _)(  )  ( ___)
#	 )    (  /(__)\  )  (  )__)  )__)  _)(_  )(__  )__)
#	(_/\/\_)(__)(__)(_)\_)(____)(__)  (____)(____)(____)    aledos-s
#

#•❅──────✧❅✦❅✧──────❅••❅──────✧❅✦❅✧──NAME──✧❅✦❅✧──────❅••❅──────✧❅✦❅✧──────❅•#

NAME 			:= ../checker

#•❅──────✧❅✦❅✧──────❅••❅──────✧❅✦❅✧───CC───✧❅✦❅✧──────❅••❅──────✧❅✦❅✧──────❅•#

CC 				:= gcc
CFLAGS 			:= -Wall -Wextra -Werror

# Chemins importants
MAIN_DIR		= ..
LIBFT_DIR		= ../libft
SRC_DIR			= ../src

# Source files
BONUS_SRCS		:= $(wildcard *.c)
COMMON_SRCS		:= $(filter-out $(SRC_DIR)/push_swap.c, $(wildcard $(SRC_DIR)/*.c))

# Object organization
OBJDIR			:= obj
BONUS_OBJS		:= $(BONUS_SRCS:%.c=$(OBJDIR)/%.o)
COMMON_OBJS		:= $(notdir $(COMMON_SRCS))
COMMON_OBJS		:= $(COMMON_OBJS:%.c=$(OBJDIR)/%.o)

# Headers and libraries
DEPS			:= checker_bonus.h
INCLUDES		:= -I$(LIBFT_DIR) -I$(MAIN_DIR)
LIBFT_LIB		:= $(LIBFT_DIR)/libft.a

# Debug information
$(info BONUS_SRCS = $(BONUS_SRCS))
$(info COMMON_SRCS = $(COMMON_SRCS))
$(info BONUS_OBJS = $(BONUS_OBJS))
$(info COMMON_OBJS = $(COMMON_OBJS))


#•❅──────✧❅✦❅✧──────❅••❅──────✧❅✦❅✧─RULES─✧❅✦❅✧──────❅••❅──────✧❅✦❅✧──────❅•#

all: $(NAME)

# Final compilation and linking
$(NAME): $(BONUS_OBJS) $(COMMON_OBJS) $(LIBFT_LIB)
	@$(CC) $(CFLAGS) $^ -L$(LIBFT_DIR) -lft -o $@
	@echo "\n\n$(OK_COLOR)✅  checker ready\n\n$(NO_COLOR)"

# Compilation rule for bonus source files
$(OBJDIR)/%.o: %.c $(DEPS) | makedirs
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Compilation rule for common source files
$(OBJDIR)/%.o: $(SRC_DIR)/%.c | makedirs
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Ensure libft is compiled
$(LIBFT_LIB):
	@make -C $(LIBFT_DIR)

makedirs:
	@mkdir -p $(OBJDIR)

clean:
	@rm -rf $(OBJDIR)
	@echo "\n\n$(WARN_COLOR)Cleaned checker object files\n$(NO_COLOR)"

fclean: clean
	@rm -f $(NAME)
	@echo "\n$(ERROR_COLOR)🚮 Checker program removed\n\n$(NO_COLOR)"

re: fclean all

#•❅──────✧❅✦❅✧──────❅••❅──────✧❅✦❅✧─IGNORE─✧❅✦❅✧──────❅••❅──────✧❅✦❅✧──────❅•#

.PHONY: all clean fclean re makedirs

#•❅──────✧❅✦❅✧──────❅••❅──────✧❅✦❅✧─COLOR──✧❅✦❅✧──────❅••❅──────✧❅✦❅✧──────❅•#

NO_COLOR = \033[0m
OK_COLOR = \033[0;32m
ERROR_COLOR = \033[0;31m
WARN_COLOR = \033[0;33m
