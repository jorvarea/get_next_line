/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 13:35:10 by jorvarea          #+#    #+#             */
/*   Updated: 2023/12/31 03:04:28 by jorvarea         ###   ########.fr       */
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
	return (i);
}

char	*reallocate_line_memory(char *line, int new_line_len)
{
	char	*new_line;
	int		i;

	new_line = malloc(new_line_len * sizeof(char)); // hay que proteger este malloc
	i = 0;
	while (line[i] != '\0')
	{
		new_line[i] = line[i];
		i++;
	}
	return (new_line);
}

char	*fill_line(char *buffer_fd, char *line, bool *full_line)
{
	int		new_line_len;
	char	*new_line;
	int		i;
	int		j;

    *full_line = false;
	new_line_len = line_length(line);
	new_line_len += line_length(buffer_fd);
	new_line = reallocate_line_memory(line, new_line_len);
	i = 0;
	while (line[i] != '\0')
	{
		new_line[i] = line[i];
		i++;
	}
    free(line);
	j = 0;
	while (buffer_fd[j] != '\n' && buffer_fd[j] != '\0')
		new_line[i++] = buffer_fd[j++];
	new_line[i] = '\0';
    if (buffer_fd[j] == '\n')
        *full_line = true;
    return (new_line);
}

void	delete_buffer_line(char *buffer[FD_LIMIT], int fd)
{
	int	i;

	i = 0;
	while (buffer[fd][i] != '\n' && buffer[fd][i] != '\0')
		i++;
	buffer[fd] = &buffer[fd][i + 1];
}
