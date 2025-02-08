#
#	 __  __    __    _  _  ____  ____  ____  __    ____
#	(  \/  )  /__\  ( )/ )( ___)( ___)(_  _)(  )  ( ___)
#	 )    (  /(__)\  )  (  )__)  )__)  _)(_  )(__  )__)
#	(_/\/\_)(__)(__)(_)\_)(____)(__)  (____)(____)(____)    aledos-s
#

#•❅──────✧❅✦❅✧──────❅••❅──────✧❅✦❅✧──NAME──✧❅✦❅✧──────❅••❅──────✧❅✦❅✧──────❅•#

NAME 		:= push_swap
WASM_NAME 	:= push_swap.wasm

#•❅──────✧❅✦❅✧──────❅••❅──────✧❅✦❅✧───CC───✧❅✦❅✧──────❅••❅──────✧❅✦❅✧──────❅•#

CC 			:= gcc
CFLAGS 		:= -Wall -Wextra -Werror
EMCC		:= emcc

SOURCE 		= $(wildcard src/*.c)
BONUS_SOURCES := $(wildcard bonus/*.c)

OBJDIR 		= obj
OBJS 		= $(SOURCE:src/%.c=$(OBJDIR)/%.o)
DEPS		= push_swap.h

LIBFT 		= libft
LIBFT_LIB 	= $(LIBFT)/libft.a
INCLUDES 	= -Ilibft -I.

BONUS_NAME	= checker
BONUS_PATH	= bonus

#•❅──────✧❅✦❅✧──────❅••❅──────✧❅✦❅✧─RULES─✧❅✦❅✧──────❅••❅──────✧❅✦❅✧──────❅•#

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_LIB)
	@$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT) -lft -o $(NAME)
	@echo "\n\n$(OK_COLOR)✅  push_swap ready\n\n$(NO_COLOR)"

$(BONUS_NAME): $(BONUS_OBJS) $(LIBFT_LIB) bonus/main_bonus.o
	@$(CC) $(CFLAGS) $(BONUS_OBJS) bonus/main_bonus.o -L$(LIBFT) -lft -o $(BONUS_NAME)
	@echo "\n\n$(OK_COLOR)✅  checker ready\n\n$(NO_COLOR)"

wasm: $(WASM_NAME)

$(WASM_NAME): $(OBJS) $(LIBFT_LIB)
	@$(EMCC) $(CFLAGS) $(OBJS) -L$(LIBFT) -lft -o $(WASM_NAME)
	@echo "\n\n$(OK_COLOR)✅  push_swap.wasm ready\n\n$(NO_COLOR)"

$(LIBFT_LIB):
	@make -C $(LIBFT) >/dev/null

$(OBJDIR)/%.o: src/%.c $(DEPS) | makedirs
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

$(OBJDIR)/%.o: bonus/%.c $(DEPS) | makedirs
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

bonus/main_bonus.o: bonus/main_bonus.c
	@$(CC) $(CFLAGS) -c $< -o $@

makedirs:
	@mkdir -p $(OBJDIR)

bonus: $(BONUS_NAME)

clean:
	@make clean -C $(LIBFT) >/dev/null
	@rm -rf $(OBJDIR)
	@echo "\n\n$(WARN_COLOR)Cleaned object files\n$(NO_COLOR)"

fclean: clean
	@make fclean -C $(LIBFT) >/dev/null
	@rm -rf $(NAME) $(BONUS_NAME) $(WASM_NAME)
	@echo "\n$(ERROR_COLOR)🚮 Program removed\n\n$(NO_COLOR)"

re: fclean all

#•❅──────✧❅✦❅✧──────❅••❅──────✧❅✦❅✧─IGNORE─✧❅✦❅✧──────❅••❅──────✧❅✦❅✧──────❅•#

.PHONY: all clean fclean re makedirs bonus

#•❅──────✧❅✦❅✧──────❅••❅──────✧❅✦❅✧─COLOR──✧❅✦❅✧──────❅••❅──────✧❅✦❅✧──────❅•#

NO_COLOR = \033[0m
OK_COLOR = \033[0;32m
ERROR_COLOR = \033[0;31m
WARN_COLOR = \033[0;33m
