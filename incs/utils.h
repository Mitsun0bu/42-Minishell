/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 11:29:37 by llethuil          #+#    #+#             */
/*   Updated: 2022/05/18 10:22:28 by llethuil         ###   ########lyon.fr   */
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

/*	utils/utils_build_heredoc_str.c	*/
char		*build_heredoc_str(t_input *input, char *del);

/*	utils/utils_change_quotes_state.c	*/
void		change_quote_state(int	*quote_state, char quote);

/*	utils/utils_check_fork_error.c	*/
void		check_fork_error(pid_t	process);

/*	utils/utils_clean_str.c	*/
char		*clean_str(t_input *input, char *str);
int			get_clean_str_len(char *str);
char		*fill_clean_str(t_input *input, char *str, int len);

/*	utils/utils_copy_filename.c	*/
void		get_name(char *dest, int *i_dest, char *cmd, int *i);
void		skip_other_redir(char *cmd, int *i);

/*	utils/utils_count_filename_len.c	*/
int			count_filename_len(char *cmd, int i_file, char c, int t);

/*	utils/count_n_file.c	*/
int			count_n_file(char *cmd, int type);

/*	utils/utils_env_var_manip.c	*/
void		add_to_env_tab(t_input *input, char *str, int type);
void		change_value(t_input *input, char *key, char *value);

/*	utils/utils_env_var_research.c	*/
char		*extract_key_from_str(t_input *input, char *str);
char		*extract_value_from_str(t_input *input, char *str);
char		*get_value_from_key(t_input *input, char *key);
int			find_existing_env_var(t_input *input, char *str);

/*	utils/utils_error.c	*/
void		print_err(int err_no, char *who, char *problem, char *err_mess);
int			exit_err(t_input *input, int err_no, char *problem, char *err_mess);

/*	utils/utils_ft_free.c	*/
void		ft_free(void **ptr);

/*	utils/utils_ft_strcmp.c	*/
int			ft_strcmp(char *s1, char *s2);

/*	utils/utils_gb_add.c	*/
void		add_gb(t_gb_lst **gb, void *ptr);
void		add_gb_front(t_gb_lst **gb, t_gb_lst *new_gb);
t_gb_lst	*create_new_gb(void *ptr);
void		assign_gb_type(t_input *input, char **table, int gb_type);

/*	utils/utils_gb_clear	*/
void		clear_all_gb(t_gb_lst **gb);
void		clear_one_gb_type(t_gb_lst **gb, int type);

/*	utils/utils_get_histroy_path.c	*/
char		*get_history_path(t_input *input);

/*	utils/is_space.c	*/
int			is_space(char c);

/*	utils/utils_pipe.c	*/
int			open_single_pipe(int *fd_tab);
void		close_single_pipe(int *fd_tab);

/*	utils/utils_set_termios.c	*/
void		set_termios(t_input *input, int mode);

/* utils/utils_signal.c */
void		set_signals(int mode);
void		signal_handler_main(int signal);
void		signal_handler_exec(int signal);
void		signal_handler_heredoc(int signal);
void		signal_handler_final_pipe(int signal);

/* utils/utils_skip.c */
void		skip_quotes(char *str, int *i);
void		back_skip_quotes(char *str, int *i);
void		skip_space_after_chev(char *cmd, int *i);

#endif