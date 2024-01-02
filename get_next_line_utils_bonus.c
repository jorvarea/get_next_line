/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 13:35:10 by jorvarea          #+#    #+#             */
/*   Updated: 2024/01/02 17:11:56 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	allocate_buffer_memory(char *buffer[FD_LIMIT], int fd, t_Flags *flags)
{
	buffer[fd] = malloc((BUFFER_SIZE + 1) * sizeof(char));
	flags->ok = (buffer[fd] != NULL);
	if (flags->ok)
		buffer[fd][0] = '\0';
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

char	*reallocate_line_memory(char *line, int new_line_len, t_Flags *flags)
{
	char	*new_line;
	int		i;

	new_line = malloc((new_line_len + 1) * sizeof(char));
	flags->ok = (new_line != NULL);
	if (flags->ok)
	{
		i = 0;
		while (line[i] != '\0')
		{
			new_line[i] = line[i];
			i++;
		}
		new_line[i] = '\0';
		free(line);
	}
	return (new_line);
}

void	shift_buffer(char *buffer[FD_LIMIT], int fd)
{
	int	line_len;
	int	i;

	line_len = line_length(buffer[fd]);
	i = line_len;
	while (buffer[fd][i] != '\0')
	{
		buffer[fd][i - line_len] = buffer[fd][i];
		i++;
	}
	buffer[fd][i - line_len] = '\0';
}
