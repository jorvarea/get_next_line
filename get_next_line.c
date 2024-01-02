/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 13:35:05 by jorvarea          #+#    #+#             */
/*   Updated: 2024/01/02 02:17:37 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	read_file(char *buffer_fd, int fd, bool *ok)
{
	int	bytes_read;

	bytes_read = read(fd, buffer_fd, BUFFER_SIZE);
	if (bytes_read >= 0)
		buffer_fd[bytes_read] = '\0';
	if (bytes_read <= 0)
		*ok = false;
}

char	*fill_line(const char *buffer_fd, char *line, bool *ok, bool *full_line)
{
	int		line_len;
	int		new_line_len;
	char	*new_line;
	int		i;
	int		j;

	line_len = line_length(line);
	new_line_len = line_len + line_length(buffer_fd);
	new_line = reallocate_line_memory(line, new_line_len, ok);
	if (*ok)
	{
		i = line_len;
		j = 0;
		while (i < new_line_len)
			new_line[i++] = buffer_fd[j++];
		new_line[i] = '\0';
		if (new_line[i - 1] == '\n')
			*full_line = true;
	}
	return (new_line);
}

char	*get_line(const char *buffer_fd, bool *ok, bool *full_line)
{
	char	*line;
	int		line_len;
	int		i;

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
		if (line[i - 1] == '\n')
			*full_line = true;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer[FD_LIMIT];
	char		*line;
	bool		full_line;
	bool		ok;

	ok = true;
	full_line = false;
	if (buffer[fd] == NULL)
		allocate_buffer_memory(buffer, fd, &ok);
	if (ok)
	{
		line = get_line(buffer[fd], &ok, &full_line);
		while (ok && !full_line)
		{
			read_file(buffer[fd], fd, &ok);
			line = fill_line(buffer[fd], line, &ok, &full_line);
		}
		shift_buffer(buffer, fd);
	}
	if (!ok)
		line = NULL;
	return (line);
}
