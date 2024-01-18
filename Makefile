# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/18 01:24:03 by jorvarea          #+#    #+#              #
#    Updated: 2024/01/18 01:36:15 by jorvarea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				= get_next_line.a
CC					= gcc
CFLAGS				= -Wall -Werror -Wextra
SOURCE_FILES   		= $(wildcard *.c)
OBJECT_DIR 			= obj
OBJECT_FILES		= $(SOURCE_FILES:%.c=$(OBJECT_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJECT_FILES) get_next_line.h
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