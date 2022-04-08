/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 12:09:40 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/08 18:52:33 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                               ~~~ DEFINES ~~~                              */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTER_H
# define EXECUTER_H

/* ************************************************************************** */
/*                                                                            */
/*                               ~~~ INCLUDES ~~~                             */
/*                                                                            */
/* ************************************************************************** */

# include "main.h"
# include <sys/types.h>

/* ************************************************************************** */
/*                                                                            */
/*                              ~~~ PROTOTYPES ~~~                            */
/*                                                                            */
/* ************************************************************************** */

/* executer/exec_manager.c */
void	exec_first_cmd(t_input *input, t_cmd_lst *cmd);
void	exec_mid_cmd(t_input *input, t_cmd_lst *cmd);
void	exec_last_cmd(t_input *input, t_cmd_lst *cmd);
int		exec_built_in(t_input *input, t_cmd_lst *cmd);
int		exec_program(t_input *input, t_cmd_lst *cmd);

/* executer/executer.c */
void	executer(t_input *input, t_cmd_lst *cmd);

/* executer/file_manager.c */
int		open_files(t_input *input, t_cmd_lst *cmd);
int		open_infiles(t_input *input, t_cmd_lst *cmd);
int		open_outfiles(t_input *input, t_cmd_lst *cmd);
int		open_app_outfiles(t_input *input, t_cmd_lst *cmd);

/* executer/heredoc_manager.c */
int		handle_heredocs(t_input *input, t_cmd_lst *cmd);
char	*get_heredoc_str(t_input *input, t_cmd_lst *cmd);
char 	*build_heredoc_str(t_input *input, char *del, unsigned long del_len);
char	*read_heredoc_line(t_input *input);
char	*append_heredoc_line(t_input *input, char *line, char *heredoc_str);

/* executer/path_manager.c */
void	path_manager(t_input *input, t_cmd_lst *cmd);
int		get_paths_tab(t_input *input);
char	*assign_path(t_input *input, t_cmd_lst *cmd, char *arg);

/* executer/pipe_manager.c */
int		open_all_pipes(t_cmd_lst *cmd);
int		open_single_pipe(int *fd_tab);
void	close_all_pipes(t_cmd_lst *cmd);
void	close_single_pipe(int *fd_tab);

/* executer/pipex.c */
int		pipex(t_input *input, t_cmd_lst *cmd);

/*executer/infile_manager.c */
int		handle_infile(t_input *input, t_cmd_lst *cmd);
int		dup_redir_input(t_cmd_lst *cmd);

/*executer/outfile_manager.c */
int		handle_outfile(t_input *input, t_cmd_lst *cmd);
int		dup_redir_output(t_cmd_lst *cmd);
int		dup_redir_app_output(t_cmd_lst *cmd);

/* executer/utils_executer.c */
int		find_built_in(char *name);
void	check_fork_error(pid_t	process);
int		wait_all_processes(t_input *input);
char	**convert_env_tab(t_input *input);
int		count_env_to_convert(t_input *input);

#endif