/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledos-s <aledos-s@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:46:50 by aledos-s          #+#    #+#             */
/*   Updated: 2025/01/21 20:29:22 by aledos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* ************************************************************************** */
/*                                                                            */
/*   is_double                                                                */
/*                                                                            */
/*   Vérifie s'il y a des doublons parmi les arguments.                       */
/*   Retourne SUCCESS s'il n'y a pas de doublons, sinon retourne ERROR.       */
/*                                                                            */
/* ************************************************************************** */

static int	is_double(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 2;
	while (i < ac)
	{
		while (j < ac)
		{
			if (ft_atoi(av[i] == ft_atoi(av[j])))
				return (ERROR);
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

/* ************************************************************************** */
/*                                                                            */
/*   is_number                                                                */
/*                                                                            */
/*   Vérifie si une chaîne de caractères représente un nombre valide.         */
/*   Retourne SUCCESS si c'est un nombre valide, sinon retourne ERROR.        */
/*                                                                            */
/* ************************************************************************** */

static int	is_number(char *str)
{
	int	i;

	i = 0;
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

/* ************************************************************************** */
/*                                                                            */
/*   check_number                                                             */
/*                                                                            */
/*   Vérifie les arguments pour s'assurer qu'ils sont des nombres valides     */
/*   et qu'il n'y a pas de doublons. Si un argument n'est pas valide ou       */
/*   s'il y a des doublons, affiche un message d'erreur et termine le         */
/*   programme.                                                               */
/*                                                                            */
/* ************************************************************************** */

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
	if (is_double(ac, av) == ERROR)
	{
		ft_printf("%s%s%s", ERROR_COLOR, ERR_DOUBLE, NO_COLOR);
		exit(ERROR);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*   check_args                                                               */
/*                                                                            */
/*   Vérifie le nombre d'arguments et appelle check_number pour valider       */
/*   les arguments. Si le nombre d'arguments est insuffisant, affiche un      */
/*   message d'erreur et termine le programme.                                */
/*                                                                            */
/* ************************************************************************** */

void	check_args(int ac, char **av)
{
	if (ac < 3)
	{
		ft_printf("%s %s %s", OK_COLOR, ERR_ARGS, NO_COLOR);
		exit(ERROR);
	}
	check_numbers_and_duplicates(ac, av);
}
