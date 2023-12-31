/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 13:35:12 by jorvarea          #+#    #+#             */
/*   Updated: 2023/12/31 03:07:54 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 33
# endif
# define FD_LIMIT 1024

void	allocate_buffer_memory(char *buffer[FD_LIMIT], int fd, bool *ok);
int		line_length(char *buffer_fd);
char	*reallocate_line_memory(char *line, int new_line_len);
char	*fill_line(char *buffer_fd, char *line, bool *full_line);
void	delete_buffer_line(char *buffer[FD_LIMIT], int fd);
char	*get_line(char *buffer_fd, bool *ok, bool *full_line);
char	*get_next_line(int fd);

#endif