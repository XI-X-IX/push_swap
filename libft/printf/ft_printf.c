/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledos-s <aledos-s@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 14:49:39 by aledos-s          #+#    #+#             */
/*   Updated: 2024/11/19 22:08:15 by aledos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_specifier(char s, va_list *args, int *i, int *len)
{
	if (s == 'c')
		ft_putchar(va_arg(*args, int), len);
	else if (s == 's')
		ft_putstr(va_arg(*args, char *), len);
	else if (s == 'd' || s == 'i')
		ft_putnbr(va_arg(*args, int), len);
	else if (s == 'p')
		ft_pointer(va_arg(*args, size_t), len);
	else if (s == 'u')
		ft_unsigned(va_arg(*args, unsigned int), len);
	else if (s == 'x' || s == 'X')
		ft_hexadecimal(va_arg(*args, unsigned int), len, s);
	else if (s == '%')
		ft_putchar('%', len);
	else
		(*i)--;
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		len;
	int		i;

	va_start(args, str);
	len = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			ft_specifier(str[i], &args, &i, &len);
			i++;
		}
		else
		{
			ft_putchar(str[i], &len);
			i++;
		}
	}
	va_end(args);
	return (len);
}

// int main(void)
// {
// 	ft_printf("ft_printf: %%d: %d, %%i: %i, %%c: %c, %%s: %s, %%p: %p,
// 			%%u: %u, %%x: %x, %%X: %X, %%%%: %%\n",
// 			-42, 42, 'A', "Hello, world!", (void *)0x12345678,
// 			4294967295U, 255, 255);
// 	printf("printf:    %%d: %d, %%i: %i, %%c: %c, %%s: %s, %%p: %p,
// 			%%u: %u, %%x: %x, %%X: %X, %%%%: %%\n",
// 			-42, 42, 'A', "Hello, world!", (void *)0x12345678,
// 			4294967295U, 255, 255);
// 	return (0);
// }
