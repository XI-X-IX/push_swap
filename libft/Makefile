# MON PREMIER MAKEFILE

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
		ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c \
		ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c ft_strdup.c \
		ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c \
		ft_strrchr.c ft_tolower.c ft_toupper.c ft_putchar_fd.c ft_putendl_fd.c \
		ft_putnbr_fd.c ft_putstr_fd.c ft_substr.c ft_strjoin.c ft_strtrim.c \
		ft_itoa.c ft_split.c ft_strmapi.c ft_striteri.c printf/ft_printf.c \
		printf/ft_characters.c printf/ft_numbers.c \

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
