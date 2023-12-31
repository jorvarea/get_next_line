/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 13:35:05 by jorvarea          #+#    #+#             */
/*   Updated: 2023/12/31 03:09:37 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(char *buffer_fd, bool *ok, bool *full_line)
{
	char	*line;
	int		line_len;
	int		i;

	*full_line = false;
	line_len = line_length(buffer_fd);
	line = malloc(line_len * sizeof(char));
	if (line == NULL)
		*ok = false;
	else
	{
		i = 0;
		while (i < line_len)
		{
			line[i] = buffer_fd[i];
			i++;
		}
		line[i] = '\0';
		if (buffer_fd[i] == '\n')
			*full_line = true;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer[FD_LIMIT];
	char		*line;
	int			bytes_read;
	bool		full_line;
	bool		ok;

	ok = true;
	if (buffer[fd] == NULL)
		allocate_buffer_memory(buffer, fd, &ok);
	if (ok)
	{
		line = get_line(buffer[fd], &ok, &full_line);
		while (!full_line)
		{
			bytes_read = read(fd, buffer[fd], BUFFER_SIZE);
			buffer[fd][bytes_read] = '\0';
			line = fill_line(buffer[fd], line, &full_line);
		}
		delete_buffer_line(buffer, fd);
	}
	if (!ok || line[0] == '\0')
		line = NULL;
	return (line);
}
