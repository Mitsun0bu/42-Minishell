/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var_manager.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:21:58 by agirardi          #+#    #+#             */
/*   Updated: 2022/04/19 16:29:53 by llethuil         ###   ########lyon.fr   */
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
void	replace_existing_env_var(t_input *input, char *str);
void	remove_from_env_tab(t_input *input, char *key);
void	change_value(t_input *input, char *key, char *value);

/* env_manager/env_var_converter.c */
void	env_var_converter(t_input *input, char *str);
void	fill_buffer(t_input *input, char *buffer);
void	fill_env_var(t_input *input, char *str, int *i, int *j);
void	fill_quotes(t_input *input, char *str, int *i, int *j);

/* env_manager/utils_env_var_counter.c */
int		count_env_var(t_input *input, char *str, int *i, int red);
int		count_quotes(t_input *input, char *str, int *i);

/* env_manager/utils_env_var.c */
char	*extract_key_from_str(t_input *input, char *str);
char	*extract_value_from_str(t_input *input, char *str);
char	*get_value_from_key(t_input *input, char *key);
int		env_tab_contains_key(const char *str, const char *key);
int		find_existing_env_var(t_input *input, char *str);

#endif
