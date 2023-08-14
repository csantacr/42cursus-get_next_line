/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantacr <csantacr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 15:52:43 by csantacr          #+#    #+#             */
/*   Updated: 2023/08/14 18:38:45 by csantacr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_stash(int fd, char *stash)
{
	char	*buffer;
	int		readed;

	if (!stash)
		stash = ft_calloc(1, sizeof(char));
	buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buffer)
		return (0);
	readed = 1; // es prescindible esta línea?
	while (!ft_strchr(stash, '\n') && readed != 0) // para qué es necesario el readed != 0?
	{
		readed = read(fd, buffer, BUFFER_SIZE);
		if (readed == -1)
		{
			free(stash);
			free(buffer);
			return (0);
		}
		// buffer[readed] = '\0'; // ésto no debería hacer falta al usar calloc?
		stash = ft_strjoin(stash, buffer);
	}
	free(buffer);
	return (stash);
}

static char *get_line(char *stash)
{
	char	*line;
	int		i;

	i = 0;
	if (!stash[i])	// o !stash porque es un puntero e i=0(ya va a la primera posición)
		return (0);
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	line = ft_calloc((i + 2), sizeof(char));
	if (!line)
		return (0);
	i = 0;
	while (stash[i] != '\0' && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n' && stash[i])
		line[i] = '\n';
	return (line);
}

static char *update_stash(char *stash)
{
	char	*ustash;
	int		i;
	int		j;

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
	return (ustash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0) // || read(fd, buffer, 0) < 0;
		return (NULL);
	stash = get_stash(fd, stash);
	if (!stash)
		return (0);
	line = get_line(stash);
	stash = update_stash(stash);
	return (line);
}

int main(void)
{
	char *filename;
	int fd;
	int lineas;
	char	*line;
	
	lineas = 7;
	filename = "test.txt";
	fd = open(filename, O_RDONLY);
	while (lineas > 0)
	{
		line = get_next_line(fd);
		printf("line: %s", line);
		free(line);
		lineas--;
	}
	close(fd);
	return (0);
}
