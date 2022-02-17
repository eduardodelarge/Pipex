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

NAME	=	pipex
SRC 	=	pipex.c ft_split.c ft_strncmp.c  ft_putstr_fd.c convert.c \
			ft_strlen.c ft_strjoin.c ft_putendl_fd.c free_matrix.c ft_strtrim.c
OBJ		=	${SRC:.c=.o}
FLAGS	=	-Wall -Wextra -Werror
HEADER	=	pipex.h

CC		=	gcc

.c.o:
	$(CC) $(FLAGS) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJ) $(HEADER)
			gcc $(FLAGS) $(OBJ) -o $(NAME);
			@echo "\n\033[32m Compilation Done! ⌐(ಠ۾ಠ)¬" 
clean:
			rm -rf ${OBJ}

fclean: 	clean
			rm -rf ${NAME} 
			@echo "\n\033[34m Goodbye files ⌐(ಠ۾ಠ)¬" 

re: 		fclean all

.PHONY: 	all clean fclean re