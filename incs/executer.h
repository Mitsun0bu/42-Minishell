/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 12:09:40 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/01 17:44:04 by llethuil         ###   ########lyon.fr   */
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
void	exec_single_cmd(char **envp, t_input *input, t_cmd_lst **lst_node);
int		exec_all_cmd(char **envp, t_input *input, t_cmd_lst **lst_node);
void	exec_first_cmd(char **envp, t_cmd_lst *lst_node);
void	exec_mid_cmd(char **envp, t_cmd_lst *lst_node);
void	exec_last_cmd(char **envp, t_cmd_lst *lst_node);

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
void	close_all_pipes(t_cmd_lst *lst_node);

/* executer/pipex.c */
int		pipex(char **envp, t_input *input, t_cmd_lst **lst_node);

/* executer/utils_pipex.c */
void	check_fork_error(pid_t	process);
int		wait_all_processes(t_input *input);




#endif