/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 12:09:40 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/22 16:07:47 by llethuil         ###   ########lyon.fr   */
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
/*                              ~~~ PROTOTYPES ~~~                            */
/*                                                                            */
/* ************************************************************************** */

/* executer/built_ins_utils.c */
int		cmd_is_built_in(char *name);
int		exec_built_in(t_input *input, t_cmd_lst *cmd);

/* executer/close_all_files.c */
int		close_all_files(t_cmd_lst *cmd);

/* executer/convert_env_tab.c */
char	**convert_env_tab(t_input *input);

/* executer/executer.c */
void	executer(t_input *input, t_cmd_lst *cmd);

/* executer/handle_heredocs.c */
int		handle_heredocs(t_input *input, t_cmd_lst *cmd);

/* executer/pipe_exec.c */
int		pipe_exec(t_input *input, t_cmd_lst *cmd);

/* executer/pipes_utils.c */
int		open_all_pipes(t_cmd_lst *cmd);
void	close_all_pipes(t_cmd_lst *cmd);

/* executer/open_all_files.c */
int		open_all_files(t_input *input, t_cmd_lst *cmd);

/* executer/get_path.c */
int		get_path(t_input *input, t_cmd_lst *cmd);

/*executer/set_data_flux.c */
void	set_stdin(t_input *input, t_cmd_lst *cmd);
void	set_stdout(t_input *input, t_cmd_lst *cmd);

#endif