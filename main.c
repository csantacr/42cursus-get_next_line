/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantacr <csantacr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 20:32:45 by csantacr          #+#    #+#             */
/*   Updated: 2023/08/15 19:48:29 by csantacr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>
#include <fcntl.h>

void	check_leaks(void)
{
	system("leaks a.out");
}

int	main(void)
{
	char	*filename;
	int		fd;
	int		lineas;
	char	*line;

	lineas = 7;
	filename = "test.txt";
	atexit(check_leaks);
	fd = open(filename, O_RDONLY);
	while (lineas > 0)
	{
		line = get_next_line(fd);
		printf("def line: \n%s\n", line);
		free(line);
		lineas--;
	}
	close(fd);
	return (0);
}
