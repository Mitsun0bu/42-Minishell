/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 17:07:56 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/28 10:37:20 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                               ~~~ DEFINES ~~~                              */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# define INPUT 42
# define TRUNC_OUTPUT 43
# define HEREDOC 44
# define APP_OUTPUT 45
# define BUILT_IN 46
# define PROGRAM 47
# define ENV 48
# define EXPORT_EMPTY 49
# define EXPORT_NULL 50
# define INPUT_STRUCT 51
# define CMD_LINE 52
# define CMD_TAB 53
# define ENV_STRUCT 54
# define CMD_LST 55
# define GARBAGE 56
# define COLLECTOR_LST 57

/* ************************************************************************** */
/*                                                                            */
/*                              ~~~ TYPEDEFS ~~~                              */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_input
{
	struct s_garbage_lst	*garbage;
	struct s_env			*env_tab;
	int						start_shlvl;
	char					*cmd_line;
	char					*processed_line;
	int						n_env;
	char					**cmd_tab;
	int						n_cmd;
	int						*last_input_type_tab;
	int						*last_output_type_tab;
	char					****redir_tab;
	char					***cmd_exec_tab;
	char					**paths_tab;
	int						fd_history;
	int						free_all;
	int						*process;
	int						status;
}	t_input;

typedef struct s_cmd_lst
{
	int					index;
	char				*name;
	int					n_args;
	char				**args;
	int					n_input_redir;
	int					n_output_redir;
	int					n_heredoc;
	int					n_app_output_redir;
	char				**input_redir;
	char				**output_redir;
	char				**del;
	char				**app_output_redir;
	char				*valid_path; // pas mis a NULL dans cmd_list_init.c --> new_cmd
	int					*fd_input;
	int					*fd_output;
	int					*fd_app_output;
	char				*heredoc_str; // mis a NULL dans cmd_list_init.c --> new_cmd
	int					heredoc_pipe[2];
	int					cmd_pipe[2];
	struct s_cmd_lst	*next;
	struct s_cmd_lst	*previous;
}	t_cmd_lst;

typedef struct s_env
{
	char	*key;
	char	*value;
	int		type;
}	t_env;

/* ************************************************************************** */
/*                                                                            */
/*                               ~~~ INCLUDES ~~~                             */
/*                                                                            */
/* ************************************************************************** */

/* our headers */
# include "../libft/libft.h"
# include "built_ins.h"
# include "cmd_line_manager.h"
# include "cmd_lst_manager.h"
# include "cmd_separator.h"
# include "env_manager.h"
# include "executer.h"
# include "parser.h"
# include "redir_collector.h"
# include "shell_initializer.h"
# include "utils.h"

/* opendir, readdir, closedir */
# include <dirent.h>

/* perror */
# include <errno.h>

/* open */
# include <fcntl.h>

/* libft */
# include "../libft/libft.h"

/* get_next_line */
# include <limits.h>

/* add_history, readline, rl_clear_history,			*/
/* rl_on_new_line, rl_replace_line, rl_redisplay	*/
# include <readline/readline.h>
# include <readline/history.h>

/* signal, kill */
# include <signal.h>

/* printf */
# include <stdio.h>

/* malloc, free, getenv, exit */
# include <stdlib.h>

/* strerror */
# include <string.h>

/* ioctl */
# include <sys/ioctl.h>

/* stat */
# include <sys/stat.h>

/* wait, waitpid, wait3, wait4 */
# include <sys/resource.h>
# include <sys/time.h>
# include <sys/types.h>
# include <sys/wait.h>

/* tcsetattr, tcgetattr */
# include <termios.h>

/* access, chdir, close, dup, dup2, execve, fork, getcwd,	*/
/* isatty, pipe, read, ttyname, ttyslot, unlink, write		*/
# include <unistd.h>

/* tgetent, tgetflag, tgetnum, tgetstr, tgoto, tputs */
# include <curses.h>
# include <term.h>


/* ************************************************************************** */
/*                                                                            */
/*                              ~~~ PROTOTYPES ~~~                            */
/*                                                                            */
/* ************************************************************************** */

/* main/main.c */
int	main(int ac, char **av, char **envp);
int	stderror_print_return(int error, char *problem, char *err_message);
int	stderror_print_exit(t_input *input, char *problem, char *err_message);

#endif
