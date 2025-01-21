/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledos-s <aledos-s@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:33:53 by aledos-s          #+#    #+#             */
/*   Updated: 2024/10/31 15:24:21 by aledos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hexadecimal(unsigned int x, int *len, char xx)
{
	char	string[16];
	char	*base;
	int		i;

	i = 0;
	if (xx == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (x == 0)
	{
		ft_putchar('0', len);
		return ;
	}
	while (x != 0)
	{
		string[i] = base[x % 16];
		x = x / 16;
		i++;
	}
	while (i != 0)
	{
		i--;
		ft_putchar(string[i], len);
	}
}

void	ft_unsigned(unsigned int u, int *len)
{
	if (u >= 10)
		ft_unsigned(u / 10, len);
	ft_putchar(u % 10 + '0', len);
}

void	ft_pointer(size_t p, int *len)
{
	char	string[16];
	int		i;
	char	*base;

	i = 0;
	base = "0123456789abcdef";
	ft_putchar('0', len);
	ft_putchar('x', len);
	if (p == 0)
	{
		ft_putchar('0', len);
		return ;
	}
	while (p != 0)
	{
		string[i] = base[p % 16];
		p = p / 16;
		i++;
	}
	while (i != 0)
	{
		i--;
		ft_putchar(string[i], len);
	}
}

void	ft_putnbr(int nb, int *len)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		(*len) += 11;
		return ;
	}
	if (nb < 0)
	{
		ft_putchar('-', len);
		ft_putnbr(nb * -1, len);
	}
	else
	{
		if (nb > 9)
			ft_putnbr(nb / 10, len);
		ft_putchar(nb % 10 + '0', len);
	}
}
