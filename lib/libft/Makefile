# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: loamar <loamar@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/30 19:29:10 by loamar            #+#    #+#              #
#    Updated: 2020/03/03 18:40:47 by loamar           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= libft.a

CC=gcc

SRC=ft_putnbr.c \
	ft_islower.c \
	ft_isupper.c \
	ft_abs.c \
	ft_putchar.c \
	ft_putstr.c \
	ft_atoi.c \
	ft_bzero.c \
	ft_calloc.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_itoa.c \
	ft_memccpy.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memset.c \
	ft_putchar_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_putstr_fd.c \
	ft_split.c \
	ft_strdup.c \
	ft_strjoin.c \
	ft_strlcat.c \
	ft_strlcpy.c \
	ft_strlen.c \
	ft_strmapi.c \
	ft_strncmp.c \
	ft_strnstr.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strtrim.c \
	ft_substr.c \
	ft_tolower.c \
	ft_toupper.c \
	ft_stohex.c \
	ft_strtoupper.c \
	ft_putzero.c \
	ft_putspace.c \
	ft_unsigned.c \
	ft_ltohex.c \
	ft_atoi_base.c \
	ft_isprecision.c \
	ft_ltohex_spe.c \
	ft_strdel.c \
	ft_strcpy.c \
	ft_newstr.c \
	ft_min.c \
	ft_max.c \
	ft_memdel.c


OBJ= $(SRC:.c=.o)

OBJ_BON= $(BONUS:.c=.o)

BONUS=ft_lstadd_front_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c ft_lstlast_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c

FLAGS=-Wall -Wextra -Werror

INC=./INCLUDES


all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $^
	@ranlib $(NAME)

.o: .c
	@$(CC) $(FLAGS) -I$(INC) -o $@ -c $<

bonus: $(OBJ) $(OBJ_BON)
	@ar rc $(NAME) $^
	@ranlib $(NAME)

clean:
	@rm -f $(OBJ)

clean_b:
	@rm -f $(OBJ_BON)

fclean: clean clean_b
	@rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean clean_b fclean re

.SILENT: $(OBJ)
