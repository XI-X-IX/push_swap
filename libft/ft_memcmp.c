/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledos-s <aledos-s@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 14:23:45 by aledos-s          #+#    #+#             */
/*   Updated: 2024/10/02 14:36:45 by aledos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*ps1 = (const unsigned char *)s1;
	const unsigned char	*ps2 = (const unsigned char *)s2;

	while (n > 0)
	{
		if (*ps1 != *ps2)
			return ((unsigned char)*ps1 - (unsigned char)*ps2);
		ps1++;
		ps2++;
		n--;
	}
	return (0);
}
