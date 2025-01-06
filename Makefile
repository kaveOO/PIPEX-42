NAME	=	pipex

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror -g $(INCLUDE)
INCLUDE	=	-I includes -I libft
RM		=	rm -f

LIB		= 	libft
LIBFT	=	$(LIB)/libft.a

SRC		=	src/core/pipex.c				\
			src/utils/pipex_utils.c			\

BSRC	= 	src/core/pipex_bonus.c			\
			src/utils/pipex_bonus_utils.c	\

OBJ 		= $(SRC:.c=.o)
BOBJ		= $(BSRC:.c=.o)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)

$(LIBFT): $(LIB)
		$(MAKE) -C $(LIB)

all: $(NAME)

bonus: $(BONUS) $(LIBFT) $(BOBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(BOBJ) $(LIBFT)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)
	$(RM) $(BOBJ)
	$(MAKE) clean -C $(LIB)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(LIBFT)

re: fclean all

.PHONY:		all clean fclean re bonus
