#
#	 __  __    __    _  _  ____  ____  ____  __    ____
#	(  \/  )  /__\  ( )/ )( ___)( ___)(_  _)(  )  ( ___)
#	 )    (  /(__)\  )  (  )__)  )__)  _)(_  )(__  )__)
#	(_/\/\_)(__)(__)(_)\_)(____)(__)  (____)(____)(____)    aledos-s
#

#•❅──────✧❅✦❅✧──────❅••❅──────✧❅✦❅✧──NAME──✧❅✦❅✧──────❅••❅──────✧❅✦❅✧──────❅•#

NAME 		:= push_swap
BONUS_NAME 	:= checker
WASM_NAME 	:= push_swap.wasm

#•❅──────✧❅✦❅✧──────❅••❅──────✧❅✦❅✧───CC───✧❅✦❅✧──────❅••❅──────✧❅✦❅✧──────❅•#

CC 			:= gcc
CFLAGS 		:= -Wall -Wextra -Werror
EMCC		:= emcc

COMMON_SRC  := $(filter-out src/push_swap.c, $(wildcard src/*.c))
MAIN_SRC    := src/push_swap.c
BONUS_SRC   := $(wildcard bonus/*.c)

OBJDIR      := obj
COMMON_OBJS := $(COMMON_SRC:src/%.c=$(OBJDIR)/%.o)
MAIN_OBJ    := $(MAIN_SRC:src/%.c=$(OBJDIR)/%.o)
BONUS_OBJS  := $(BONUS_SRC:bonus/%.c=$(OBJDIR)/%.o)

DEPS		= push_swap.h
BONUS_DEPS	= bonus/checker_bonus.h

LIBFT 		= libft
LIBFT_LIB 	= $(LIBFT)/libft.a
INCLUDES 	= -Ilibft -I. -Isrc
LIBFT_PATH	= libft/*.c


#•❅──────✧❅✦❅✧──────❅••❅──────✧❅✦❅✧─RULES─✧❅✦❅✧──────❅••❅──────✧❅✦❅✧──────❅•#

all: $(NAME)

$(NAME): $(COMMON_OBJS) $(MAIN_OBJ) $(LIBFT_LIB)
		@$(CC) $(CFLAGS) $(COMMON_OBJS) $(MAIN_OBJ) -L$(LIBFT) -lft -o $(NAME)
		@echo "\n\n\033[0;32m✅ push_swap ready\033[0m\n\n"

$(BONUS_NAME): $(COMMON_OBJS) $(BONUS_OBJS) $(LIBFT_LIB)
	@$(CC) $(CFLAGS) $(COMMON_OBJS) $(BONUS_OBJS) -L$(LIBFT) -lft -o $(BONUS_NAME)
		@echo "\n\n\033[0;32m✅ checker ready\033[0m\n\n"

wasm: $(LIBFT_LIB)
	@echo "\n\n\033[0;34m🔄 Compiling WebAssembly...\033[0m"
	@docker run --rm -v $(shell pwd):/src emscripten/emsdk emcc \
		$(MAIN_SRC) $(COMMON_SRC) $(LIBFT_PATH) \
		$(INCLUDES) -L$(LIBFT) -lft \
		-o $(WASM_NAME) 2>/dev/null || \
	(echo "\033[0;31m❌ WebAssembly compilation failed\033[0m" && exit 1)
	@echo "\n\n$(OK_COLOR)✅  push_swap.wasm created\n\n$(NO_COLOR)"

$(LIBFT_LIB):
		@make -C $(LIBFT) >/dev/null

$(OBJDIR)/%.o: src/%.c $(DEPS) | $(OBJDIR)
		@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

$(OBJDIR)/%.o: bonus/%.c $(BONUS_DEPS) | $(OBJDIR)
		@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

$(OBJDIR):
		@mkdir -p $@

bonus: $(BONUS_NAME)

bonus_clean:
		@rm -rf $(OBJDIR)
		@echo "\n$(WARN_COLOR)Cleaned bonus object files\n$(NO_COLOR)"

bonus_fclean:
		@rm -rf $(OBJDIR)
		@rm -f $(BONUS_NAME)
		@echo "\n\n$(WARN_COLOR)Cleaned bonus object files$(NO_COLOR)"
		@echo "\n$(ERROR_COLOR)🚮 Checker program removed\n\n$(NO_COLOR)"

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

.PHONY: all clean fclean re bonus

#•❅──────✧❅✦❅✧──────❅••❅──────✧❅✦❅✧─COLOR──✧❅✦❅✧──────❅••❅──────✧❅✦❅✧──────❅•#

NO_COLOR = \033[0m
OK_COLOR = \033[0;32m
ERROR_COLOR = \033[0;31m
WARN_COLOR = \033[0;33m
