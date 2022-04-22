/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 12:09:40 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/22 10:40:58 by llethuil         ###   ########lyon.fr   */
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

/* executer/close_all_files.c */
int		close_all_files(t_cmd_lst *cmd);

/* executer/close_all_pipes.c */
void	close_all_pipes(t_cmd_lst *cmd);

/* executer/cmd_is_built_in.c */
int		cmd_is_built_in(char *name);

/* executer/exec_cmd.c */
int		exec_built_in(t_input *input, t_cmd_lst *cmd);
void	exec_first_cmd(t_input *input, t_cmd_lst *cmd);
void	exec_mid_cmd(t_input *input, t_cmd_lst *cmd);
void	exec_last_cmd(t_input *input, t_cmd_lst *cmd);

/* executer/executer.c */
void	executer(t_input *input, t_cmd_lst *cmd);

/* executer/handle_heredocs.c */
int		handle_heredocs(t_input *input, t_cmd_lst *cmd);

/* executer/handle_pipe.c */
int		handle_pipe(t_input *input, t_cmd_lst *cmd);
void	set_termios_and_sig_for_exec(t_input *input);
void	finish_exec(t_input *input, t_cmd_lst *cmd);
int		ft_get_pid(int pid);

/* executer/handle_redir_files.c */
int		handle_infile(t_input *input, t_cmd_lst *cmd);
int		handle_outfile(t_input *input, t_cmd_lst *cmd);

/* executer/open_all_files.c */
int		open_all_files(t_input *input, t_cmd_lst *cmd);

/* executer/pipe_manager.c */
int		open_all_pipes(t_cmd_lst *cmd);

/* executer/path_manager.c */
int		path_manager(t_input *input, t_cmd_lst *cmd);
int		cmd_name_is_a_valid_relative_path(t_cmd_lst *cmd);
int		get_paths_tab_from_env_path(t_input *input);
char	*assign_path_to_cmd(t_input *input, char *cmd_name);

/*executer/redir_manager.c */
void	set_stdin(t_input *input, t_cmd_lst *cmd);
void	set_stdout(t_input *input, t_cmd_lst *cmd);

/* executer/utils_executer.c */
void	check_fork_error(pid_t	process);
int		wait_all_processes(t_input *input);
char	**convert_env_tab(t_input *input);
int		count_env_var_to_convert(t_input *input);

#endif