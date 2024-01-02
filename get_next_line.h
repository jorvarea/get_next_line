/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 13:35:12 by jorvarea          #+#    #+#             */
/*   Updated: 2024/01/02 16:53:44 by jorvarea         ###   ########.fr       */
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
# ifndef FD_LIMIT
#  define FD_LIMIT 1024
# endif

typedef struct s_Flags
{
	bool	ok;
	bool	eof;
	bool	read_error;
	bool	full_line;
}			t_Flags;

void		allocate_buffer_memory(char *buffer[FD_LIMIT], int fd,
				t_Flags *flags);
char		*reallocate_line_memory(char *line, int new_line_len,
				t_Flags *flags);
char		*handle_errors(char *line, t_Flags *flags);
int			line_length(char *buffer_fd);
void		shift_buffer(char *buffer[FD_LIMIT], int fd);
void		read_file(char *buffer[FD_LIMIT], int fd, t_Flags *flags);
char		*fill_line(char *buffer_fd, char *line, t_Flags *flags);
char		*get_line(char *buffer_fd, t_Flags *flags);
char		*get_next_line(int fd);

#endif