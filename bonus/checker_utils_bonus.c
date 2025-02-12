/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledos-s <alex>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 19:47:48 by aledos-s          #+#    #+#             */
/*   Updated: 2025/02/10 09:17:45 by aledos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	is_empty(t_stack *b)
{
	return (b->size == 0);
}

static char	*extract_line(char **save)
{
	char	*line;
	char	*temp;
	int		i;

	if (!*save)
		return (NULL);
	i = 0;
	while ((*save)[i] && (*save)[i] != '\n')
		i++;
	if ((*save)[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	ft_strlcpy(line, *save, i + 1);
	temp = ft_strdup(*save + i);
	free(*save);
	*save = temp;
	return (line);
}

static int	read_file(int fd, char **save)
{
	char	buf[BUFFER_SIZE + 1];
	char	*temp;
	int		bytes;

	while (!ft_strchr(*save, '\n'))
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes <= 0)
			return (bytes);
		buf[bytes] = '\0';
		temp = ft_strjoin(*save, buf);
		free(*save);
		*save = temp;
	}
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char	*save = NULL;
	int			result;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!save)
		save = ft_strdup("");
	result = read_file(fd, &save);
	*line = extract_line(&save);
	if (!*line)
		return (-1);
	return (result > 0);
}
