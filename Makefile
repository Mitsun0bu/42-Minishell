# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/25 15:43:51 by llethuil          #+#    #+#              #
#    Updated: 2022/03/14 16:45:42 by llethuil         ###   ########lyon.fr    #
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

SRCS_LST	:=	built_ins/ft_cd.c					\
				built_ins/ft_echo.c					\
				built_ins/ft_env.c					\
				built_ins/ft_exit.c					\
				built_ins/ft_export.c				\
				built_ins/ft_pwd.c					\
				built_ins/ft_unset.c				\
				cmd_line_manager/get_cmd_line.c		\
				cmd_line_manager/cmd_line_manager.c	\
				cmd_lst_init/cmd_lst_init.c			\
				cmd_lst_init/node_manager.c			\
				cmd_lst_init/utils_linked_lst.c		\
				env_manager/env_manager.c			\
				env_manager/utils_env_counter.c		\
				env_manager/utils_env_finder.c		\
				env_manager/utils_env.c				\
				env_parser/env_parser.c				\
				executer/dup_manager.c				\
				executer/exec_manager.c				\
				executer/executer.c					\
				executer/file_manager.c				\
				executer/heredoc_manager.c			\
				executer/path_manager.c				\
				executer/pipe_manager.c				\
				executer/pipex.c					\
				executer/redir_manager.c			\
				executer/utils_executer.c			\
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
				main/main.c							\
				parser/arg_length.c					\
				parser/arg_number.c					\
				parser/checker.c					\
				parser/cleaner.c					\
				parser/parser.c						\
				parser/utils_parser.c				\
				shell_initializer/shell_init.c		\
				utils/utils_error_manager.c			\
				utils/utils_free_lst.c				\
				utils/utils_free_struct.c			\
				utils/utils_free.c					\
				utils/utils_history.c				\
				utils/utils.c						\

SUBDIRS_LST	:=	built_ins							\
				cmd_line_manager					\
				cmd_lst_init						\
				env_manager							\
				env_parser							\
				executer							\
				lexer								\
				main								\
				parser								\
				shell_initializer					\
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
	$(CC) $(OBJS) $(LIBFT_AR) -lreadline -g3 -o $(NAME)
	printf "$(GREEN)> Executable file has been created successfully !$(END)\n"

$(OBJS_DIR):
	mkdir -p $(addprefix $(OBJS_DIR)/, $(SUBDIRS_LST))

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(INCS) Makefile | $(OBJS_DIR)
	printf "$(BLUE)> Compiling :$(END) $<\n"
	$(CC) $(CFLAGS) -I $(INCS_DIR) -c $< -o $@

clean:
	make clean -C $(LIBFT_DIR)
	printf "$(PINK)> Removing minishell .o files ...$(END)\n"
	$(RM) $(OBJS)
	printf "$(PINK)> Removing .objs directory ...$(END)\n"
	rm -rf $(OBJS_DIR)
	printf "$(GREEN)> All the .o files have been removed successfully !$(END)\n"

fclean: clean
	printf "$(PINK)> Removing libft archive file ...$(END)\n"
	$(RM) $(LIBFT_AR)
	printf "$(PINK)> Removing minishell executable file ...$(END)\n"
	$(RM) $(NAME)
	printf "$(GREEN)> Libft archive and minishell executable files have been removed successfully !$(END)\n"

re: fclean all

.PHONY: all clean fclean libft re
