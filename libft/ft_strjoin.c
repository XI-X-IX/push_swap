/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledos-s <aledos-s@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:47:51 by aledos-s          #+#    #+#             */
/*   Updated: 2024/10/08 13:21:03 by aledos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	size_t	total;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	total = ft_strlen(s1) + ft_strlen(s2) + 1;
	dst = malloc(total * sizeof(char));
	if (!dst)
		return (NULL);
	dst[0] = '\0';
	ft_strlcat(dst, s1, total);
	ft_strlcat(dst, s2, total);
	return (dst);
}
// erreur, dst non initialisé
