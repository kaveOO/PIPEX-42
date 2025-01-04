NAME	=	pipex

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror -g $(INCLUDE)
INCLUDE	=	-I includes -I libft
RM		=	rm -f

LIB		= 	libft
LIBFT	=	$(LIB)/libft.a

SRC		=	src/core/main.c			\
			src/parsing/parsing.c	\
			src/handling/handling.c	\
			src/utils/array_utils.c	\
			src/exec/exec_child.c	\
			src/exec/exec_files.c	\
			src/exec/exec_pipe.c	\
			src/exec/gls_free_tbl.c	\

OBJ 		= $(SRC:.c=.o)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)

$(LIBFT): $(LIB)
		$(MAKE) -C $(LIB)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)
	$(MAKE) clean -C $(LIB)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(LIBFT)

re: fclean all

.PHONY:		all clean fclean re
