/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 17:07:56 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/18 14:20:43 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                               ~~~ DEFINES ~~~                              */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# define TRUNC_OUTPUT 42
# define APP_OUTPUT 43
# define BUILT_IN 44
# define PROGRAM 45
# define ENV 46
# define EXPORT_EMPTY 47
# define EXPORT_NULL 48

/* ************************************************************************** */
/*                                                                            */
/*                              ~~~ TYPEDEFS ~~~                              */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_input
{
	int				start_shlvl;
	char			*cmd_line;
	char			*processed_line;
	struct s_env	*env_tab;
	int				n_env;
	char			**cmd_tab;
	int				*last_output_redir_tab;
	char			****redir_tab;
	char			***cmd_exec_tab;
	char			**paths_tab;
	int				n_cmd;
	int				fd_history;
	int				*process;
	int				free_all;
}	t_input;

typedef struct s_cmd_lst
{
	int					index;
	char				*name;
	char				**args;
	char				*valid_path;
	int					n_args;
	int					n_input_redir;
	int					n_output_redir;
	int					n_app_output_redir;
	int					n_heredoc;
	char				**input_redir;
	char				**output_redir;
	char				**app_output_redir;
	char				**del;
	int					last_output_redir;
	int					*fd_input;
	int					*fd_output;
	int					*fd_app_output;
	int					cmd_pipe[2];
	int					heredoc_pipe[2];
	char				*heredoc_str;
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
# include "built_ins.h"
# include "cmd_line_manager.h"
# include "cmd_lst_init.h"
# include "cmd_separator.h"
# include "env_manager.h"
# include "executer.h"
# include "redir_collector.h"
# include "parser.h"
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

#endif
