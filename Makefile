NAME	=	minishell

CC		=	gcc

RM		=	rm -f

CFLAGS	=	-I. -fsanitize=address

LIBFT	=	./lib/libft/libft.a

SRCS	=	./srcs/minishell.c \
			./srcs/builtins/handler_built_ins.c \
			./srcs/check/data_check.c \
			./srcs/cmd/exec_cmd.c \
			./srcs/cmd/handler_cmd.c \
			./srcs/data/handler_data.c \
			./srcs/env/create_list_env.c \
			./srcs/env/handler_env.c \
			./srcs/list/create_list.c \
			./srcs/list/handler_list.c \
			./srcs/list/set_token_list.c \
			./srcs/init/init_struct.c \
			./srcs/init/init_shell.c \
			./srcs/error/free_error.c \
			./srcs/error/handler_error.c \
			./srcs/data/split_data/split_data.c \
			./srcs/data/split_data/split_data_utils.c \
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

f:			re
			./minishell

.PHONY:		all clean fclean re f
