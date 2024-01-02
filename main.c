/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 00:24:05 by jorvarea          #+#    #+#             */
/*   Updated: 2024/01/02 00:37:35 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int	fd;

	fd = open("test.txt", O_RDONLY);
	if (fd)
	{
		for (int i = 0; i < 100; i++)
			printf("%s", get_next_line(fd));
	}
	close(fd);
}
