/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledos-s <aledos-s@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 12:34:58 by aledos-s          #+#    #+#             */
/*   Updated: 2024/11/19 22:02:25 by aledos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <stddef.h>

// MAIN
int		ft_printf(const char *str, ...);
// CHARACTERS
void	ft_putchar(char c, int *len);
void	ft_putstr(const char *s, int *len);
// NUMBERS
void	ft_pointer(size_t p, int *len);
void	ft_putnbr(int nb, int *len);
void	ft_hexadecimal(unsigned int x, int *len, char xx);
void	ft_unsigned(unsigned int u, int *len);

#endif
