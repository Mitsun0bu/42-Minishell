/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:37:10 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/14 11:05:15 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                               ~~~ DEFINES ~~~                              */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# define SUCCESS 0
# define FAILED -1
# define YES 1
# define NO 0
# define IN 1
# define OUT 0
# define CHILD 0
# define INFILE 2
# define OUTFILE 3
# define HEREDOC 4
# define APP_OUTFILE 5
# define ENV 7
# define ENV_EMPTY 8
# define ENV_NULL 9
# define INPUT_STRUCT 10
# define CMD_LINE 11
# define CMD_TAB 12
# define ENV_STRUCT 13
# define CMD_LST 14
# define GARBAGE 15
# define COLLECTOR_LST 16

/* ************************************************************************** */
/*                                                                            */
/*                               ~~~ INCLUDES ~~~                             */
/*                                                                            */
/* ************************************************************************** */

# include <curses.h>
# include <dirent.h>
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/ioctl.h>
# include <sys/resource.h>
# include <sys/stat.h>
# include <sys/time.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <term.h>
# include <termios.h>
# include <unistd.h>

/* ************************************************************************** */
/*                                                                            */
/*                              ~~~ TYPEDEFS ~~~                              */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_input
{
	struct termios			old_term;
	struct termios			new_term;
	struct s_gb_lst			*gb;
	struct s_env			*env_tab;
	int						start_shlvl;
	char					*cmd_line;
	char					*processed_line;
	int						n_env;
	char					**cmd_tab;
	int						n_cmd;
	int						*last_infile_type;
	int						*last_outfile_type;
	char					****redir_tab;
	char					***cmd_exec_tab;
	char					**paths_tab;
	int						fd_history;
	int						*process;
	int						status;
}	t_input;

typedef struct s_gb_lst
{
	int						index;
	void					**ptr;
	int						type;
	struct s_gb_lst			*next;
	struct s_gb_lst			*previous;
}	t_gb_lst;

typedef struct s_env
{
	char	*key;
	char	*value;
	int		type;
}	t_env;

typedef struct s_cmd_lst
{
	int					i;
	char				*name;
	int					n_args;
	char				**args;
	int					n_infile;
	int					n_outfile;
	int					n_heredoc;
	int					n_app_outfile;
	char				**infile;
	char				**outfile;
	char				**del;
	char				**app_outfile;
	char				*valid_path;
	int					*fd_infile;
	int					*fd_outfile;
	int					*fd_app_outfile;
	int					heredoc_process;
	int					heredoc_pipe[2];
	int					cmd_pipe[2];
	struct s_cmd_lst	*next;
	struct s_cmd_lst	*previous;
}	t_cmd_lst;

#endif