NAME	=	minishell

CC		=	gcc

RM		=	rm -f

CFLAGS	=	-I.

LIBFT	=	./lib/libft/libft.a

SRCS	=	./srcs/minishell.c \
			./srcs/tree.c \
			./srcs/init.c \
			./srcs/data/sort_data.c \
			./lib/get_next_line/get_next_line.c \
			./lib/get_next_line/get_next_line_utils.c

OBJS	=	$(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			make -C lib/libft
			${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LIBFT}

clean:
			$(RM) $(OBJS)
			make clean -C lib/libft

fclean:		clean
			$(RM) $(NAME) $(LIBFT)

re:			fclean $(NAME)

.PHONY:		all clean fclean re
