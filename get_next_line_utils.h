/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:55:25 by jorvarea          #+#    #+#             */
/*   Updated: 2024/01/18 14:06:40 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_UTILS_H
# define GET_NEXT_LINE_UTILS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 33
# endif

# ifndef FD_LIMIT
#  define FD_LIMIT 1024
# endif

# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_Flags
{
	bool	ok;
	bool	eof;
	bool	full_line;
}			t_Flags;

void	allocate_buffer_memory(char *buffer[FD_LIMIT], int fd, t_Flags *flags);
char	*reallocate_line_memory(char *line, int new_line_len, t_Flags *flags);
int		line_length(char *buffer_fd);
void	shift_buffer(char *buffer[FD_LIMIT], int fd);

#endif