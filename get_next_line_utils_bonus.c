/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantacr <csantacr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 16:51:22 by csantacr          #+#    #+#             */
/*   Updated: 2023/08/16 17:38:38 by csantacr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*res;
	size_t	i;

	if (sizeof(size_t) < count && sizeof(size_t) < size)
		return (0);
	res = malloc(count * size);
	if (!res)
		return (0);
	i = 0;
	while (i < count * size)
	{
		res[i] = 0;
		i++;
	}
	return (res);
}

char	*ft_strchr(char *str, int c)
{
	if (!str)
		return (NULL);
	while (*str)
	{
		if (*str == c)
			return (str);
		str++;
	}
	if (*str == c)
		return (str);
	return (NULL);
}

char	*ft_strjoin(char *stash, char *buffer)
{
	int		ustash_len;
	char	*ustash;
	int		i;
	int		j;

	ustash_len = (ft_strlen(stash) + ft_strlen(buffer) + 1);
	ustash = ft_calloc(sizeof(char), ustash_len);
	if (!stash || !buffer || !ustash)
		return (NULL);
	i = -1;
	while (stash[++i])
		ustash[i] = stash[i];
	j = -1;
	while (buffer[++j])
		ustash[i++] = buffer[j];
	free(stash);
	return (ustash);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
