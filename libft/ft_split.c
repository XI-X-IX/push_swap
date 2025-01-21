/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledos-s <aledos-s@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 23:35:07 by aledos-s          #+#    #+#             */
/*   Updated: 2024/10/15 17:57:38 by aledos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char const *s, char c)
{
	size_t	words;
	size_t	i;

	i = 0;
	words = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			words++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (words);
}

static char	*ft_copy_word(const char *s, int start, int end)
{
	size_t	i;
	char	*word;

	i = 0;
	word = malloc ((end - start + 1) * sizeof (char));
	if (!word)
		return (NULL);
	while (start < end)
	{
		word[i] = s[start];
		i++;
		start++;
	}
	word[i] = '\0';
	return (word);
}

static void	ft_free(char **split)
{
	size_t	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static char	**ft_fill(char **split, char const *s, char c)
{
	size_t	start;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		if (start < i)
		{
			split[j] = ft_copy_word(s, start, i);
			if (!split[j])
				return (ft_free(split), NULL);
			j++;
		}
	}
	split[j] = NULL;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	size_t	words;
	char	**split;

	if (s == NULL)
		return (NULL);
	words = ft_count_words(s, c);
	split = malloc ((words + 1) * sizeof (char *));
	if (!split)
		return (NULL);
	split = ft_fill(split, s, c);
	return (split);
}

/*
char	**ft_split(char const *s, char c)
{
	size_t	words;
	char	**split;

	if (s == NULL)
		return (NULL);
	words = ft_count_words(s, c);
	split = malloc ((words + 1) * sizeof (char *));
	if (!split)
		return (NULL);
	if (!ft_fill(split, s, c))
	{
		free(split);
		return (NULL);
	}
	return (split);
}*/
