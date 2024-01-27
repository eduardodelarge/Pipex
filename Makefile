# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: caeduard <caeduard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/16 19:50:15 by coder             #+#    #+#              #
#    Updated: 2022/02/17 11:54:33 by caeduard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Wextra -Werror
NAME = pipex
SRC_DIR = utils/
INC_DIR = includes/
SRC_FILES = $(wildcard $(SRC_DIR)*.c)
OBJ_FILES = $(SRC_FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_FILES)
    $(CC) $(FLAGS) -I $(INC_DIR) $^ -o $@

%.o: %.c
    $(CC) $(FLAGS) -I $(INC_DIR) -c $< -o $@

clean:
    rm -f $(OBJ_FILES)

fclean: clean
    rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re