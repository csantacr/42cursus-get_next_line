/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantacr <csantacr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 18:34:02 by csantacr          #+#    #+#             */
/*   Updated: 2023/08/14 18:34:33 by csantacr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*str;

	if (!s1 || !s2)
		return (0);
	str = (char *) malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s1))
	{
		str[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < ft_strlen(s2))
	{
		str[i + ft_strlen(s1)] = s2[i];
		i++;
	}
	str[i + ft_strlen(s1)] = '\0';
	return (str);
}

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

// refactorizar esta función
char	*ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (c == '\0')
		return (str);
	while (str[i])
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i++;
	}
	return (0);
}
