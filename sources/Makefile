NAME	=	pipex
SRC 	=	pipex.c ft_split.c ft_strncmp.c ft_substr.c ft_putstr_fd.c \
			ft_strdup.c ft_strlen.c ft_strjoin.c ft_putendl_fd.c
OBJ		=	${SRC:.c=.o}
FLAGS	=	-Wall -Werror -Wextra 
HEADER	=	pipex.h

all:		$(NAME)

$(NAME):	$(OBJ) $(HEADER)
			gcc $(FLAGS) $(OBJ) -o $(NAME);
clean:
			rm -rf ${OBJ}

fclean: 	clean
			rm -rf ${NAME} 

re: 		fclean all

.PHONY: 	all clean fclean re