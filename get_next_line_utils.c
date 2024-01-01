/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 13:35:10 by jorvarea          #+#    #+#             */
/*   Updated: 2024/01/01 22:26:40 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	allocate_buffer_memory(char *buffer[FD_LIMIT], int fd, bool *ok)
{
	buffer[fd] = malloc((BUFFER_SIZE + 1) * sizeof(char));
	buffer[fd][0] = '\0';
	if (buffer[fd] == NULL)
		*ok = false;
}

int	line_length(char *buffer_fd)
{
	int	i;

	i = 0;
	while (buffer_fd[i] != '\0' && buffer_fd[i] != '\n')
		i++;
	if (buffer_fd[i] == '\n')
		i++;
	return (i);
}

char	*reallocate_line_memory(char *line, int new_line_len, bool *ok)
{
	char	*new_line;
	int		i;

	new_line = malloc(new_line_len * sizeof(char));
	if (new_line == NULL)
		*ok = false;
	else
	{
		i = 0;
		while (line[i] != '\0')
		{
			new_line[i] = line[i];
			i++;
		}
		free(line);
	}
	return (new_line);
}

void	delete_buffer_line(char *buffer[FD_LIMIT], int fd)
{
	int	i;

	i = 0;
	while (buffer[fd][i] != '\n' && buffer[fd][i] != '\0')
		i++;
	if (buffer[fd][i] == '\n') 
		buffer[fd] = &buffer[fd][i + 1];
	else
		buffer[fd] = &buffer[fd][i];
}
