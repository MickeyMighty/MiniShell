NAME	=	minishell

CC		=	gcc

RM		=	rm -f

CFLAGS	=	-g -I. -Wall -Wextra -Werror -fsanitize=address

LIBFT	=	./lib/libft/libft.a

SRCS	=	./srcs/main/minishell.c \
			./srcs/main/handler_signal.c \
			./srcs/builtins/handler_builtins.c \
			./srcs/builtins/my_cd.c \
			./srcs/builtins/my_env.c \
			./srcs/builtins/my_pwd.c \
			./srcs/builtins/export/my_export.c \
			./srcs/builtins/export/export_check.c \
			./srcs/builtins/export/print_export.c \
			./srcs/builtins/my_exit.c \
			./srcs/builtins/my_echo.c \
			./srcs/builtins/my_unset.c \
			./srcs/cmd/exec_cmd.c \
			./srcs/cmd/handler_exec_cmd.c   \
			./srcs/cmd/handler_cmd.c \
			./srcs/cmd/pipe_cmd.c \
			./srcs/cmd/redir_cmd.c \
			./srcs/cmd/redir_file_cmd.c \
			./srcs/cmd/check/check_block_cmd.c \
			./srcs/cmd/check/return_check.c \
			./srcs/cmd/check/fill_second_step.c \
			./srcs/cmd/check/check_quoteanddollar.c \
			./srcs/cmd/check/special_case_cmd.c \
			./srcs/env/create_list_env.c \
			./srcs/env/handler_env.c \
			./srcs/env/path_env.c \
			./srcs/list/create_list.c \
			./srcs/list/handler_list.c \
			./srcs/list/set_token_list.c \
			./srcs/list/create_tab_args.c \
			./srcs/init/init_struct.c \
			./srcs/init/init_shell.c \
			./srcs/error_and_free/free_error.c \
			./srcs/error_and_free/error_msg.c \
			./srcs/error_and_free/handler_error.c \
			./srcs/data/handler_data.c \
			./srcs/data/split_data/split_data.c \
			./srcs/data/split_data/split_data_utils.c \
			./srcs/data/split_data/get_len_split_data.c \
			./lib/get_next_line/get_next_line.c

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
