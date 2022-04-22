/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var_manager.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:21:58 by agirardi          #+#    #+#             */
/*   Updated: 2022/04/22 18:04:53 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                               ~~~ DEFINES ~~~                              */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_VAR_MANAGER_H
# define ENV_VAR_MANAGER_H

/* ************************************************************************** */
/*                                                                            */
/*                              ~~~ PROTOTYPES ~~~                            */
/*                                                                            */
/* ************************************************************************** */

/* env_manager/env_var_manager.c */
void	add_to_env_tab(t_input *input, char *str, int type);
void	change_value(t_input *input, char *key, char *value);

/* env_manager/convert_env_var_in_str.c */
void	convert_env_var_in_str(t_input *input, char *str);

/* env_manager/env_var_counter.c */
int		count_processed_line(t_input *input, char *str);
int		count_env_var(t_input *input, char *str, int *i, int redir);
int		count_quotes(t_input *input, char *str, int *i, int redir);
int		count_basic(char *str, int *redir, int *i);

/* env_manager/env_var_filler.c */
void	fill_processed_line(t_input *input, char *str);
void	fill_basic(t_input *input, char *str, int index[], int *redir);
void	fill_env_var(t_input *input, char *str, int index[], int redir);
void	fill_quotes(t_input *input, char *str, int index[], int redir);

/* env_manager/utils_env_var_processing.c */
void	fill_value(t_input *input, char *value, int *i);
char	*find_exit_status(t_input *input, char *str, int i, int redir);
int		check_heredoc(char *str, int i);
char	*get_key_to_process(t_input *input, char *str, int *i);
int		is_first_command(char *str, int limit);

/* env_manager/utils_env_var.c */
char	*extract_key_from_str(t_input *input, char *str);
char	*extract_value_from_str(t_input *input, char *str);
char	*get_value_from_key(t_input *input, char *key);
int		find_existing_env_var(t_input *input, char *str);

#endif
