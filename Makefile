# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/25 15:43:51 by llethuil          #+#    #+#              #
#    Updated: 2022/02/10 18:18:53 by llethuil         ###   ########lyon.fr    #
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

NAME		:= minishell

CC			:= gcc

CFLAGS		:= -Wall -Wextra -Werror

RM			:= rm -f

LIBFT_DIR	:= libft

INCS_DIR	:= incs

SRCS_DIR	:= srcs

OBJS_DIR	:= .objs

INCS_LST	:=	minishell.h							\
				lexer.h								\
				parser.h							\

SRCS_LST	:=	built_ins/built_ins.c						\
				cmd_line_handler/get_cmd_line.c				\
				cmd_line_handler/get_next_line.c			\
				cmd_line_handler/main_cmd_line_handler.c	\
				lexer/cmd_separator.c						\
				lexer/fill_redir_tab_input.c				\
				lexer/fill_redir_tab_output.c				\
				lexer/fill_redir_tab_heredoc.c				\
				lexer/fill_redir_tab_app_output.c			\
				lexer/main_lexer.c							\
				lexer/redir_manager_app_output.c			\
				lexer/redir_manager_heredoc.c				\
				lexer/redir_manager_input.c					\
				lexer/redir_manager_output.c				\
				lexer/redir_tab_memory_manager.c			\
				lexer/utils_other_lexer.c					\
				lexer/utils_quotes_lexer.c					\
				parser/arg_length.c							\
				parser/arg_number.c							\
				parser/checker.c							\
				parser/cleaner.c							\
				parser/main_parser.c						\
				parser/utils_parser.c						\
				main.c										\
				error_manager.c								\
				ft_exec_single_cmd.c						\
				init_shell.c								\
				utils_free.c								\
				utils.c										\

SUBDIRS_LST	:=	built_ins							\
				lexer								\
				parser								\

OBJS_LST	:=	$(SRCS_LST:.c=.o)

LIBFT_AR	:= $(LIBFT_DIR)/libft.a

INCS		:= $(addprefix $(INCS_DIR)/, $(INCS_LST))

SRCS		:= $(addprefix $(SRCS_DIR)/, $(SRCS_LST))

OBJS		:= $(addprefix $(OBJS_DIR)/, $(OBJS_LST))

# ************************************************************************** #
#                                                                            #
#                              ~~~ RULES & COMMANDS ~~~                      #
#                                                                            #
# ************************************************************************** #

all: libft $(NAME)

.SILENT:

libft:
	make -C $(LIBFT_DIR)
	printf "$(GREEN)> Libft archive has been compiled successfully !$(END)\n"

$(NAME): $(LIBFT_AR) $(OBJS)
	printf "$(GREEN)> All the .c files have been compiled successfully !$(END)\n"
	printf "$(BLUE)> Creating the executable file :$(END) $@\n"
	$(CC) $(OBJS) $(LIBFT_AR) -lreadline -o $(NAME)
	printf "$(GREEN)> Executable file has been created successfully !$(END)\n"

$(OBJS_DIR):
	mkdir -p $(addprefix $(OBJS_DIR)/, $(SUBDIRS_LST))

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(INCS) Makefile | $(OBJS_DIR)
	$(CC) $(CFLAGS) -I $(INCS_DIR) -c $< -o $@
	printf "$(BLUE)> Compiling :$(END) $<\n"

clean:
	$(RM) $(OBJS)
	printf "$(PINK)> Removing .o files ...$(END)\n"
	make clean -C $(LIBFT_DIR)
	printf "$(GREEN)> All the .o files have been removed successfully !$(END)\n"

fclean: clean
	$(RM) $(LIBFT_AR)
	printf "$(PINK)> Removing libft archive file ...$(END)\n"
	$(RM) $(NAME)
	printf "$(PINK)> Removing executable file ...$(END)\n"
	printf "$(GREEN)> libft archive and executable file have been removed successfully !$(END)\n"

re: fclean all

.PHONY: all clean fclean libft re
