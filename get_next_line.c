/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantacr <csantacr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 15:52:43 by csantacr          #+#    #+#             */
/*   Updated: 2023/08/15 20:04:41 by csantacr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

static char	*update_stash(char *stash)
{
	char	*ustash;
	int		i;
	int		j;

	printf("old stash: %s\n", stash);
	i = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	ustash = ft_calloc(sizeof(char), (ft_strlen(stash) - i + 1));
	if (!ustash)
		return (NULL);
	i++;
	j = 0;
	while (stash[i])
		ustash[j++] = stash[i++];
	free(stash);
	printf("new stash: %s\n", ustash);
	return (ustash);
}

static char	*get_line(char *stash)
{
	char	*line;
	int		i;

	i = 0;
	if (!stash[i])
		return (NULL);
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	line = ft_calloc((i + 2), sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] != '\0' && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n' && stash[i])
		line[i] = stash[i];
	printf("line: %s\n", line);
	return (line);
}

static char	*get_stash(int fd, char *stash)
{
	char	*buffer;
	int		readed;

	if (!stash)
		stash = ft_calloc(1, sizeof(char));
	buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buffer)
		return (NULL);
	readed = 1;
	while (!ft_strchr(buffer, '\n') && readed != 0)
	{
		readed = read(fd, buffer, BUFFER_SIZE);
		if (readed == -1)
		{
			free(stash);
			free(buffer);
			return (NULL);
		}
		buffer[readed] = '\0';
		printf("buffer: %s\n", buffer);
		stash = ft_strjoin(stash, buffer);
		printf("stash: %s\n", stash);
	}
	free(buffer);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	stash = get_stash(fd, stash);
	if (!stash)
		return (NULL);
	line = get_line(stash);
	stash = update_stash(stash);
	return (line);
}
