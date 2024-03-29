/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 13:35:05 by jorvarea          #+#    #+#             */
/*   Updated: 2024/01/18 14:06:48 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_utils.h"

static char	*handle_errors(char *line, t_Flags *flags)
{
	if (!flags->ok || line[0] == '\0')
	{
		if (line != NULL)
			free(line);
		line = NULL;
	}
	return (line);
}

static void	read_file(char *buffer[FD_LIMIT], int fd, t_Flags *flags)
{
	int	bytes_read;

	bytes_read = read(fd, buffer[fd], BUFFER_SIZE);
	if (bytes_read < 0)
		flags->ok = false;
	flags->eof = bytes_read == 0;
	if (flags->ok)
		buffer[fd][bytes_read] = '\0';
	if ((flags->eof || !flags->ok) && buffer[fd] != NULL)
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
	}
}

static char	*fill_line(char *buffer_fd, char *line, t_Flags *flags)
{
	int		line_len;
	int		new_line_len;
	char	*new_line;
	int		i;
	int		j;

	line_len = line_length(line);
	new_line_len = line_len + line_length(buffer_fd);
	new_line = reallocate_line_memory(line, new_line_len, flags);
	if (flags->ok)
	{
		i = line_len;
		j = 0;
		while (i < new_line_len)
			new_line[i++] = buffer_fd[j++];
		new_line[i] = '\0';
		if (new_line[i - 1] == '\n')
			flags->full_line = true;
	}
	return (new_line);
}

static char	*ft_get_line(char *buffer_fd, t_Flags *flags)
{
	char	*line;
	int		line_len;
	int		i;

	line_len = line_length(buffer_fd);
	line = malloc((line_len + 1) * sizeof(char));
	flags->ok = line != NULL;
	if (flags->ok)
	{
		i = 0;
		while (i < line_len)
		{
			line[i] = buffer_fd[i];
			i++;
		}
		line[i] = '\0';
		if (line_len > 0 && line[i - 1] == '\n')
			flags->full_line = true;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer[FD_LIMIT];
	char		*line;
	t_Flags		flags;

	flags.ok = (fd >= 0) && (fd < FD_LIMIT);
	line = NULL;
	flags.full_line = false;
	flags.eof = false;
	if (flags.ok && buffer[fd] == NULL)
		allocate_buffer_memory(buffer, fd, &flags);
	if (flags.ok)
	{
		line = ft_get_line(buffer[fd], &flags);
		while (flags.ok && !flags.full_line && !flags.eof)
		{
			read_file(buffer, fd, &flags);
			if (flags.ok && !flags.eof)
				line = fill_line(buffer[fd], line, &flags);
		}
		if (flags.ok && !flags.eof)
			shift_buffer(buffer, fd);
	}
	line = handle_errors(line, &flags);
	return (line);
}
