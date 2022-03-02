# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/25 15:43:51 by llethuil          #+#    #+#              #
#    Updated: 2022/03/02 19:12:04 by llethuil         ###   ########lyon.fr    #
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

CFLAGS		:= -Wall -Wextra -Werror #-g

RM			:= rm -f

LIBFT_DIR	:= libft

INCS_DIR	:= incs

SRCS_DIR	:= srcs

OBJS_DIR	:= .objs

INCS_LST	:=	built_ins.h							\
				cmd_line_manager.h					\
				cmd_lst_init.h						\
				env_manager.h						\
				executer.h							\
				lexer.h								\
				main.h								\
				parser.h							\
				utils.h								\

SRCS_LST	:=	built_ins/built_ins.c				\
				built_ins/ft_cd.c					\
				built_ins/ft_echo.c					\
				built_ins/ft_env.c					\
				built_ins/ft_exit.c					\
				built_ins/ft_pwd.c					\
				cmd_line_manager/get_cmd_line.c		\
				cmd_line_manager/cmd_line_manager.c	\
				cmd_lst_init/cmd_lst_init.c			\
				cmd_lst_init/node_manager.c			\
				cmd_lst_init/utils_linked_lst.c		\
				env_manager/env_utils.c				\
				env_manager/env.c					\
				executer/executer.c					\
				executer/file_manager.c				\
				executer/path_manager.c				\
				executer/pipe_manager.c				\
				executer/pipex.c					\
				executer/redir_manager.c			\
				executer/utils_pipex.c				\
				lexer/cmd_separator.c				\
				lexer/fill_last_output_redir_tab.c	\
				lexer/fill_redir_tab_input.c		\
				lexer/fill_redir_tab_output.c		\
				lexer/fill_redir_tab_heredoc.c		\
				lexer/fill_redir_tab_app_output.c	\
				lexer/lexer.c						\
				lexer/redir_manager_app_output.c	\
				lexer/redir_manager_heredoc.c		\
				lexer/redir_manager_input.c			\
				lexer/redir_manager_output.c		\
				lexer/redir_tab_memory_manager.c	\
				lexer/utils_other_lexer.c			\
				lexer/utils_quotes_lexer.c			\
				main/init_shell.c					\
				main/main.c							\
				parser/arg_length.c					\
				parser/arg_number.c					\
				parser/checker.c					\
				parser/cleaner.c					\
				parser/parser.c						\
				parser/utils_parser.c				\
				utils/utils_error_manager.c			\
				utils/utils_free_lst.c				\
				utils/utils_free.c					\
				utils/utils_history.c				\
				utils/utils.c						\

SUBDIRS_LST	:=	built_ins							\
				cmd_line_manager					\
				cmd_lst_init						\
				env_manager							\
				executer							\
				lexer								\
				main								\
				parser								\
				utils								\

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

$(NAME): $(OBJS) $(LIBFT_AR)
	test -z '$(filter %.o,$?)' || printf "$(GREEN)> All the .c files from minishell have been compiled successfully !$(END)\n"
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
