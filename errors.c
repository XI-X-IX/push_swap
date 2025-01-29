/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledos-s <aledos-s@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:46:50 by aledos-s          #+#    #+#             */
/*   Updated: 2025/01/29 10:08:11 by aledos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// =========================================
// has_duplicates
// =========================================
//
// Vérifie s'il y a des doublons parmi
// les arguments.
//
// Retour: SUCCESS (pas de doublons)
//         ERROR  (doublons trouvés)
// =========================================

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
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
				return (ERROR);
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

// =========================================
// is_number
// =========================================
//
// Vérifie si une chaîne de caractères
// représente un nombre valide.
//
// Retour: SUCCESS (nombre valide)
//         ERROR  (invalide)
// =========================================

static int	is_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (ERROR);
	while (str[i])
	{
		if (str[i] == '-' && i == 0)
			i++;
		if (!ft_isdigit(str[i]))
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}

// =========================================
// check_number_and_duplicates
// =========================================
//
// Vérifie les arguments pour s'assurer
// qu'ils sont des nombres valides et qu'il
// n'y a pas de doublons.
//
// Affiche erreur et termine si invalide
// ou si doublons trouvés.
// =========================================

void	check_number_and_duplicates(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (is_number(av[i]) == ERROR)
		{
			ft_printf("%s%s%s", ERROR_COLOR, ERR_DIGIT, NO_COLOR);
			exit(ERROR);
		}
		i++;
	}
	if (has_duplicates(ac, av) == ERROR)
	{
		ft_printf("%s%s%s", ERROR_COLOR, ERR_DOUBLE, NO_COLOR);
		exit(ERROR);
	}
}

// =========================================
// check_args
// =========================================
//
// Vérifie le nombre d'arguments et appelle
// check_number pour leur validation.
//
// Affiche erreur et termine si nombre
// d'arguments insuffisant.
// =========================================

void	check_args(int ac, char **av)
{
	if (ac < 3)
	{
		ft_printf("%s %s %s", OK_COLOR, ERR_ARGS, NO_COLOR);
		exit(ERROR);
	}
	check_numbers_and_duplicates(ac, av);
}
