/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 12:09:40 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/10 18:27:36 by llethuil         ###   ########lyon.fr   */
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

/* executer/executer.c */
int		executer(char **envp, t_input *input, t_cmd_lst **lst_node);

/* executer/execution_manager.c */
void	exec_first_cmd(t_input *input, t_cmd_lst *lst_node);
void	exec_mid_cmd(t_input *input, t_cmd_lst *lst_node);
void	exec_last_cmd(t_input *input, t_cmd_lst *lst_node);
int		exec_built_in(t_input *input, t_cmd_lst *lst_node);
int		exec_program(t_input *input, t_cmd_lst *lst_node);

/* executer/file_manager.c */
int		open_files(t_cmd_lst **lst_node);
int		open_infiles(t_cmd_lst *lst_node);
int		open_outfiles(t_cmd_lst *lst_node);
int		open_app_outfiles(t_cmd_lst *lst_node);

/* executer/path_manager.c */
void	path_manager(char **envp, t_input *input, t_cmd_lst **lst_node);
void	get_paths_tab(char **envp, t_input	*input);
char	*assign_path(char *arg, t_input *input, t_cmd_lst *lst_node);

/* executer/pipe_manager.c */
void	open_all_pipes(t_cmd_lst **lst_node);
void	open_single_pipe(int *fd_tab);
void	close_all_pipes(t_cmd_lst *lst_node);
void	close_single_pipe(int *fd_tab);

/* executer/pipex.c */
int		pipex(t_input *input, t_cmd_lst **lst_node);

/*executer/redir_manager.c */
int		handle_input_redir(t_cmd_lst *lst_node);
int		handle_output_redir(t_input *input, t_cmd_lst *lst_node);
int		dup_redir_input(t_cmd_lst *lst_node);
int		dup_redir_output(t_cmd_lst *lst_node);
int		dup_redir_app_output(t_cmd_lst *lst_node);

/* executer/utils_executer.c */
int		find_built_in(char *cmd_name);
void	check_fork_error(pid_t	process);
int		wait_all_processes(t_input *input);
char	**convert_env_tab(t_input *input);
int		count_env_to_convert(t_input *input);

#endif