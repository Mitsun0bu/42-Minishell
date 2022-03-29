# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/05 14:36:18 by llethuil          #+#    #+#              #
#    Updated: 2022/03/29 10:24:15 by llethuil         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                                                              #
#                              ~~~ COLOR CODES ~~~                             #
#                                                                              #
# **************************************************************************** #

ERASE	:=	\033[2K\r
BOLD	:=	\033[1m
RED		:=	\033[31m
GREEN	:=	\033[32m
BLUE	:=	\033[34m
PINK	:=	\033[35m
BOLD	:=	\033[1m
END		=	\033[0m

# **************************************************************************** #
#                                                                              #
#                              ~~~ VARIABLES ~~~                               #
#                                                                              #
# **************************************************************************** #

NAME	:= libft.a

CC		:= gcc

CFLAGS	:= -Wall -Wextra -Werror

RM = rm -f

INCS = libft.h

SRCS =	ft_atoi.c			\
		ft_bzero.c			\
		ft_calloc.c			\
		ft_get_next_line.c	\
		ft_isalnum.c		\
		ft_isalpha.c		\
		ft_isdigit.c		\
		ft_itoa.c			\
		ft_malloc.c			\
		ft_memset.c			\
		ft_putstr_fd.c		\
		ft_split.c			\
		ft_strchr.c			\
		ft_strdup.c			\
		ft_strjoin.c		\
		ft_strlcpy.c		\
		ft_strlen.c			\
		ft_strncmp.c		\
		ft_strnstr.c		\
		ft_strtrim.c		\
		ft_substr.c			\

OBJS = ${SRCS:.c=.o}

# **************************************************************************** #
#                                                                              #
#                              ~~~ RULES & COMMANDS ~~~                        #
#                                                                              #
# **************************************************************************** #

all: ${NAME}

.SILENT:

%.o: %.c libft.h Makefile
	${CC} ${CFLAGS} -I $(INCS) -c $< -o $@
	printf "$(BLUE)> Compiling :$(END) libft/$<\n"

${NAME}: ${OBJS}
	printf "$(GREEN)> All the libft .c files have been compiled successfully !$(END)\n"
	printf "$(BLUE)> Creating the libft archive file :$(END) $@\n"
	ar rcs $@ ${OBJS}
	printf "$(GREEN)> Libft archive has been compiled successfully !$(END)\n"

bonus: all

clean:
	${RM} ${OBJS}
	printf "$(PINK)> Removing libft .o files ...$(END)\n"

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all bonus clean fclean re