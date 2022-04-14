/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_manager.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:21:58 by agirardi          #+#    #+#             */
/*   Updated: 2022/04/14 12:58:44 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                               ~~~ DEFINES ~~~                              */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_MANAGER_H
# define ENV_MANAGER_H

/* ************************************************************************** */
/*                                                                            */
/*                              ~~~ PROTOTYPES ~~~                            */
/*                                                                            */
/* ************************************************************************** */

/* env_manager/env_manager.c */
void	add_to_env(t_input *input, char *str, int type);
void	remove_from_env(t_input *input, char *key);
void	change_value(t_input *input, char *key, char *value);

/* env_manager/env_variable_converter.c */
void	env_variable_converter(t_input *input, char *str);
void	fill_buffer(t_input *input, char *buffer);
void	fill_env(t_input *input, char *str, int *i, int *j);
void	fill_quotes(t_input *input, char *str, int *i, int *j);

/* env_manager/utils_env_counter.c */
int		count_env(t_input *input, char *str, int *i, int red);
int		count_quotes(t_input *input, char *str, int *i);

/* env_manager/utils_env_finder.c */
char	*get_key_from_env_tab(t_input *input, char *str);
char	*get_value_from_env_tab(t_input *input, char *str);

/* env_manager/utils_env.c */
char	*get_value_from_key(t_input *input, char *key);
int		find_key(const char *str, const char *key_to_remove);
int		find_value(t_input *input, char *str);

#endif
