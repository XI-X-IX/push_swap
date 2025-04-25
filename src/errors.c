#include "push_swap.h"

// =============================================================================
// has_duplicates
// =============================================================================
//
// Vérifie s'il y a des doublons parmi les arguments.
//
// @param ac: nombre d'arguments
// @param av: tableau d'arguments
// @return: SUCCESS (pas de doublons), ERROR (doublons trouvés)
// =============================================================================

static int	has_duplicates(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = i + 1;
		while (j < ac)
		{
			if (ft_atol(av[i]) == ft_atol(av[j]))
				return (ERROR);
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

// =============================================================================
// is_number
// =============================================================================
//
// Vérifie si une chaîne représente un nombre.
//
// @param str: chaîne de caractères à vérifier
// @return: SUCCESS (nombre), ERROR (non nombre)
// =============================================================================

int	is_number(const char *str)
{
	int	i;

	if (!str || !str[0])
		return (ERROR);
	i = 0;
	if (str[i] == '-')
		i++;
	if (str[i] == '\0')
		return (ERROR);
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}

// =============================================================================
// ft_atol
// =============================================================================
//
// Convertit une chaîne de caractères en entier long, en gérant les dépassements
// de capacité. Retourne 0 en cas d'erreur.
//
// @param str: chaîne de caractères à convertir
// @return: l'entier converti, ou 0 en cas d'erreur
// =============================================================================

long	ft_atol(const char *str)
{
	long	nb;
	int		sign;
	int		i;

	nb = 0;
	sign = 1;
	i = 0;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		nb = (nb * 10) + (str[i] - '0');
		i++;
	}
	return (nb * sign);
}

// =============================================================================
// check_limits
// =============================================================================
//
// Vérifie si une chaîne de caractères représente un entier valide dans les
// limites d'un int. Retourne une erreur si la chaîne n'est pas un nombre ou
// si elle dépasse les limites.
//
// @param str: chaîne de caractères à vérifier
// @return: SUCCESS si la chaîne est un entier valide, sinon ERROR
// =============================================================================

int	check_limits(const char *str)
{
	long	nb;

	if (is_number(str) == ERROR)
		return (ERROR);
	nb = ft_atol(str);
	if (nb > INT_MAX || nb < INT_MIN)
		return (ERROR);
	return (SUCCESS);
}

// =============================================================================
// check_args
// =============================================================================
//
// Vérifie si les arguments sont des nombres, s'il y a des doublons,
// et si les arguments sont des entiers valides. Affiche une erreur
// et termine le programme si une vérification échoue.
//
// @param ac: nombre d'arguments
// @param av: tableau d'arguments
// =============================================================================

void	check_args(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (check_limits(av[i]) == ERROR)
		{
			ft_putendl_fd("Error", 2);
			exit(ERROR);
		}
		i++;
	}
	if (has_duplicates(ac, av) == ERROR)
	{
		ft_putendl_fd("Error", 2);
		exit(ERROR);
	}
}
