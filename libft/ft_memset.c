/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledos-s <aledos-s@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:39:29 by aledos-s          #+#    #+#             */
/*   Updated: 2024/10/02 14:21:32 by aledos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
/*
#include <stdio.h>
#include <string.h>

int main()
{
	char str[10] = {"Hello 42!"};
	char str2[10] = {"Hello 42!"};
	size_t i;

	printf("Avant ft_memset :\t%s\n", str);
	ft_memset(str, '*', 5);
	i = -1;
	printf("Apres ft_memset :\n");
	while (++i < sizeof(str))
		printf("str[%zu] = %c\t\n", i, str[i]);
	printf("Avant memset :\t%s\n", str2);
	memset(str2, '*', 5);
	i = -1;
	printf("Apres memset :\n");
	while (++i < sizeof(str2))
		printf("str[%zu] = %c\t\n", i, str2[i]);
	return (0);
}*/
