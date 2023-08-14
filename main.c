/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantacr <csantacr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 20:32:45 by csantacr          #+#    #+#             */
/*   Updated: 2023/08/14 20:38:11 by csantacr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	char	*filename;
	int		fd;
	int		lineas;
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
