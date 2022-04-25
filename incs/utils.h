/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 11:29:37 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/25 19:26:34 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                               ~~~ DEFINES ~~~                              */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

/* ************************************************************************** */
/*                                                                            */
/*                              ~~~ PROTOTYPES ~~~                            */
/*                                                                            */
/* ************************************************************************** */

/* utils/add_gb_utils.c */
void	add_gb(t_gb_lst **gb, void *ptr);
void	add_gb_front(t_gb_lst **gb, t_gb_lst *new_gb);
t_gb_lst	*create_new_gb(void *ptr);
void	assign_gb_type(t_input *input, char **table, int gb_type);

/* utils/back_skip_quotes.c */
void	back_skip_quotes(char *str, int *i);

/* utils/build_heredoc_str.c */
char	*build_heredoc_str(t_input *input, char *del);

/* utils/check_fork_error.c */
void	check_fork_error(pid_t	process);

/* utils/close_single_pipe.c */
void	close_single_pipe(int *fd_tab);

/* utils/clean_str.c */
char	*clean_str(t_input *input, char *str);
int		get_clean_str_len(char *str);
char	*fill_clean_str(t_input *input, char *str, int len);

/* utils/clear_gb_utils */
void	clear_all_gb(t_gb_lst **gb);
void	clear_one_gb_type(t_gb_lst **gb, int type);

/*utils/copy_filename.c */
void	copy_filename(char *dest, char *cmd, int i_file, char c);

/*utils/count_filename_len.c */
int		count_filename_len(char *cmd, int i_file, char c);
int		count_filename_len(char *cmd, int i_file, char c);

/*utils/count_n_file.c */
int		count_n_file(char *cmd, int type);

/* env_manager/utils_env_var.c */
char	*extract_key_from_str(t_input *input, char *str);
char	*extract_value_from_str(t_input *input, char *str);
char	*get_value_from_key(t_input *input, char *key);
int		find_existing_env_var(t_input *input, char *str);
void	add_to_env_tab(t_input *input, char *str, int type);
void	change_value(t_input *input, char *key, char *value);

/* utils/error_utils.c */
void	print_err(int error, char *who, char *problem, char *err_message);
int		exit_err(t_input *input, int error, char *problem, char *err_message);

/* utils/ft_free.c */
void	ft_free(void **ptr);

/* utils/get_and_set_termios.c */
void	get_and_set_termios(t_input *input, char *get, char *set);
void	set_termios(t_input *input, int mode);

/* utils/get_histroy_path.c */
char	*get_history_path(t_input *input);

/* utils/is_space.c */
int		is_space(char c);

/* utils/open_single_pipe.c */
int	open_single_pipe(int *fd_tab);

/* utils/signal_utils.c */
void	set_signals(int mode);
void	signal_handler_main(int signal);
void	signal_handler_exec(int signal);
void	signal_handler_heredoc(int signal);
void	signal_handler_final_pipe(int signal);

/* utils/skip_quotes.c */
void	skip_quotes(char *str, int *i);

/* utils/skip_space_after_chev.c */
void	skip_space_after_chev(char *cmd, int *i);

#endif