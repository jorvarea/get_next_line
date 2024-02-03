# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/18 01:24:03 by jorvarea          #+#    #+#              #
#    Updated: 2024/02/03 18:08:55 by jorvarea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				= get_next_line.a
CC					= gcc
CFLAGS				= -Wall -Werror -Wextra
SOURCE_FILES   		= get_next_line.c get_next_line_utils.c
OBJECT_DIR 			= obj
OBJECT_FILES		= $(SOURCE_FILES:%.c=$(OBJECT_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJECT_FILES) get_next_line_utils.h
	@ar -rcs $(NAME) $(OBJECT_FILES)

$(OBJECT_DIR)/%.o: %.c
	@mkdir -p $(OBJECT_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJECT_DIR)
	
fclean: clean
	@rm -f $(NAME)
	
re: fclean all

.PHONY: all clean fclean re