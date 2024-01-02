/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 00:24:05 by jorvarea          #+#    #+#             */
/*   Updated: 2024/01/02 16:24:38 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int	fd;
	int	fd2;
	int	i;

	fd = open("test.txt", O_RDONLY);
	fd2 = open("test2.txt", O_RDONLY);
	if (fd)
	{
		i = 0;
		while (i < 100)
		{
			printf("%s", get_next_line(fd));
			i++;
		}
	}
	close(fd);
	close(fd2);
}
