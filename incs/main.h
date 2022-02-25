/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 17:07:56 by llethuil          #+#    #+#             */
/*   Updated: 2022/02/25 19:17:05 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                               ~~~ DEFINES ~~~                              */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

/* ************************************************************************** */
/*                                                                            */
/*                              ~~~ TYPEDEFS ~~~                              */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_input
{
	char			*cmd_line;
	struct s_env	*env_tab;
	int				n_env;
	char			**cmd_tab;
	char			****redir_tab;
	char			***cmd_exec_tab;
	char			**paths_tab;
	int				n_cmd;
	int				fd_history;
}	t_input;

typedef struct s_cmd_lst
{
	int					cmd_index;
	char				*cmd_name;
	char				**cmd_args;
	char				*valid_path;
	int					n_args;
	int					n_input_redir;
	int					n_output_redir;
	int					n_app_output_redir;
	int					n_heredoc;
	char				**input_redir;
	char				**output_redir;
	char				**app_output_redir;
	char				**heredoc;
	int					*fd_input;
	int					*fd_output;
	int					*fd_app_output;
	int					pipe_fd_tab[2];
	// pid_t				*process_input;
	// pid_t				*process_output;
	// pid_t				*process_app_output;
	struct s_cmd_lst	*next;
	struct s_cmd_lst	*previous;
}	t_cmd_lst;

typedef struct s_env
{
	char	*key;
	char	*value;
	int		is_global;
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
# include "env_manager.h"
# include "executer.h"
# include "lexer.h"
# include "parser.h"
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

/* main/init_shell.c */
void	init_shell(void);

/* main/main.c */
int	main(int ac, char **av, char **envp);

#endif
