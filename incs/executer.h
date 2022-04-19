/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 12:09:40 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/19 11:58:47 by llethuil         ###   ########lyon.fr   */
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

/* executer/exec_manager.c */
void	exec_first_cmd(t_input *input, t_cmd_lst *cmd);
void	exec_mid_cmd(t_input *input, t_cmd_lst *cmd);
void	exec_last_cmd(t_input *input, t_cmd_lst *cmd);
int		exec_built_in(t_input *input, t_cmd_lst *cmd);

/* executer/executer.c */
void	executer(t_input *input, t_cmd_lst *cmd);

/* executer/file_manager.c */
int		open_all_files(t_input *input, t_cmd_lst *cmd);
int		open_infiles(t_input *input, t_cmd_lst *cmd);
int		open_outfiles(t_input *input, t_cmd_lst *cmd);
int		open_app_outfiles(t_input *input, t_cmd_lst *cmd);
int		close_all_files(t_cmd_lst *cmd);
int		close_infiles(t_cmd_lst *cmd);
int		close_outfiles(t_cmd_lst *cmd);
int		close_app_outfiles(t_cmd_lst *cmd);

/* executer/heredoc_manager.c */
int		handle_heredocs(t_input *input, t_cmd_lst *cmd);
int		get_heredoc_str(t_input *input, t_cmd_lst *cmd);
char	*build_heredoc_str(t_input *input, char *del);
char	*read_heredoc_line(t_input *input);
char	*append_heredoc_line(t_input *input, char *line, char *heredoc_str);
int		get_heredoc_child(t_input *input, t_cmd_lst *cmd, char *heredoc_str);

/* executer/path_manager.c */
int		path_manager(t_input *input, t_cmd_lst *cmd);
int		cmd_name_is_a_valid_relative_path(t_cmd_lst *cmd);
int		get_paths_tab_from_env_path(t_input *input);
char	*assign_path_to_cmd(t_input *input, char *cmd_name);

/* executer/pipe_manager.c */
int		open_all_pipes(t_cmd_lst *cmd);
int		open_single_pipe(int *fd_tab);
void	close_all_pipes(t_cmd_lst *cmd);
void	close_single_pipe(int *fd_tab);

/* executer/pipex.c */
int		pipex(t_input *input, t_cmd_lst *cmd);

/*executer/redir_manager.c */
void	set_stdin(t_input *input, t_cmd_lst *cmd);
void	set_stdout(t_input *input, t_cmd_lst *cmd);
int		handle_infile(t_input *input, t_cmd_lst *cmd);
int		handle_outfile(t_input *input, t_cmd_lst *cmd);
int		dup_loop(int n_file, int *fd_file, int where);

/* executer/utils_executer.c */
int		is_built_in(char *name);
void	check_fork_error(pid_t	process);
int		wait_all_processes(t_input *input);
char	**convert_env_tab(t_input *input);
int		count_env_to_convert(t_input *input);

#endif