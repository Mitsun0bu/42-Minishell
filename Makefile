# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/25 15:43:51 by llethuil          #+#    #+#              #
#    Updated: 2022/04/22 17:41:23 by llethuil         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                                                              #
#                              ~~~ COLOR CODES ~~~                             #
#                                                                              #
# **************************************************************************** #

ERASE	:=	\033[2K\r
BOLD	:=	\033[1m
redir		:=	\033[31m
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

CFLAGS		:= -Wall -Wextra -Werror -ggdb3

RM			:= rm -f

LIBFT_DIR	:= libft

INCS_DIR	:= incs

SRCS_DIR	:= srcs

OBJS_DIR	:= .objs

INCS_LST	:=	header.h			\
				built_ins.h			\
				cmd_line_manager.h	\
				cmd_lst_manager.h	\
				cmd_separator.h		\
				env_var_manager.h	\
				executer.h			\
				gb_collector.h		\
				main.h				\
				arg_separator.h		\
				redir_collector.h	\
				signal_manager.h	\
				shell_initializer.h	\
				utils.h				\

SRCS_LST	:=	1_main/main.c									\
				2_shell_initializer/shell_initializer.c			\
				3_cmd_line_manager/cmd_line_manager.c			\
				4_cmd_separator/cmd_separator.c					\
				4_cmd_separator/check_pipe.c					\
				4_cmd_separator/check_quotes.c					\
				4_cmd_separator/check_redir.c					\
				4_cmd_separator/split_cmd.c						\
				4_cmd_separator/simulate_heredoc.c				\
				5_redir_collector/copy_filenames_in_redir_tab.c	\
				5_redir_collector/get_last_redir_types_tab.c	\
				5_redir_collector/redir_collector.c				\
				6_arg_separator/arg_separator.c					\
				6_arg_separator/create_arg_tab.c				\
				6_arg_separator/get_arg_len.c					\
				6_arg_separator/get_number_of_arg.c				\
				7_cmd_lst_manager/cmd_lst_init.c				\
				7_cmd_lst_manager/cmd_lst_manager.c				\
				7_cmd_lst_manager/utils_cmd_lst_manager.c		\
				8_executer/built_in_utils.c						\
				8_executer/close_all_files.c					\
				8_executer/convert_env_tab.c					\
				8_executer/executer.c							\
				8_executer/get_path.c							\
				8_executer/handle_heredocs.c					\
				8_executer/pipe_exec.c							\
				8_executer/pipe_utils.c							\
				8_executer/open_all_files.c						\
				8_executer/set_data_flux.c						\
				9_built_ins/ft_cd.c								\
				9_built_ins/ft_echo.c							\
				9_built_ins/ft_env.c							\
				9_built_ins/ft_exit.c							\
				9_built_ins/ft_export.c							\
				9_built_ins/ft_pwd.c							\
				9_built_ins/ft_unset.c							\
				env_var_manager/convert_env_var_in_str.c		\
				env_var_manager/env_var_counter.c				\
				env_var_manager/env_var_filler.c				\
				env_var_manager/env_var_manager.c				\
				env_var_manager/utils_env_var_processing.c		\
				env_var_manager/utils_env_var.c					\
				utils/add_gb_utils.c							\
				utils/back_skip_quotes.c						\
				utils/build_heredoc_str.c						\
				utils/check_fork_error.c						\
				utils/clean_str.c								\
				utils/clear_gb_utils.c							\
				utils/close_single_pipe.c						\
				utils/copy_filename.c							\
				utils/count_filename_len.c						\
				utils/count_n_file.c							\
				utils/error_utils.c								\
				utils/ft_free.c									\
				utils/get_and_set_termios.c						\
				utils/get_status.c							\
				utils/get_history_path.c						\
				utils/is_space.c								\
				utils/open_single_pipe.c						\
				utils/signal_utils.c							\
				utils/skip_quotes.c								\
				utils/skip_space_after_chev.c					\

SUBDIRS_LST	:=	1_main				\
				2_shell_initializer	\
				3_cmd_line_manager	\
				4_cmd_separator		\
				5_redir_collector	\
				6_arg_separator		\
				7_cmd_lst_manager	\
				8_executer			\
				9_built_ins			\
				env_var_manager		\
				utils				\

OBJS_LST	:=	$(SRCS_LST:.c=.o)

LIBFT_AR	:=	$(LIBFT_DIR)/libft.a

RL_LIB		:=	-L$(shell brew --prefix readline)/lib

RL_INC		:=	-I$(shell brew --prefix readline)/include

INCS		:=	$(addprefix $(INCS_DIR)/, $(INCS_LST))

SRCS		:=	$(addprefix $(SRCS_DIR)/, $(SRCS_LST))

OBJS		:=	$(addprefix $(OBJS_DIR)/, $(OBJS_LST))

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
	$(CC) $(OBJS) $(LIBFT_AR) $(RL_INC) $(RL_LIB) -lreadline -o $(NAME)
	printf "$(GREEN)> Executable file has been created successfully !$(END)\n"

$(OBJS_DIR):
	mkdir -p $(addprefix $(OBJS_DIR)/, $(SUBDIRS_LST))

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(INCS) Makefile | $(OBJS_DIR)
	printf "$(BLUE)> Compiling :$(END) $<\n"
	$(CC) $(CFLAGS) -I $(INCS_DIR) $(RL_INC) -c $< -o $@

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
