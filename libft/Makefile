# MON PREMIER MAKEFILE

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRC = $(wildcard *.c)

OBJ = $(SRC:.c=.o)

all: $(NAME)

#cible: dépendances				target: dependancies
#	commande						command
$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

# Compile fichers .c en fichiers .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Efface fichiers .o
clean:
	rm -f $(OBJ)

# Efface fichiers .o + lib compilée
fclean: clean
	rm -f $(NAME)

# Supprime complet puis execute cible all: pour tout recompiler a zero
re: fclean all

# Assure que les commandes suivantes ne sont pas des fichiers du même nom
.PHONY: all clean fclean re
