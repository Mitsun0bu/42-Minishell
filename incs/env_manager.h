/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_manager.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:21:58 by agirardi          #+#    #+#             */
/*   Updated: 2022/03/23 16:09:53 by llethuil         ###   ########lyon.fr   */
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
/*                               ~~~ INCLUDES ~~~                             */
/*                                                                            */
/* ************************************************************************** */

# include "main.h"

/* ************************************************************************** */
/*                                                                            */
/*                              ~~~ PROTOTYPES ~~~                            */
/*                                                                            */
/* ************************************************************************** */

/* env_manager/env_manager.c */
void	add_to_env(t_input *input, char *str, int type);
void	remove_from_env(t_input *input, char *key);
void	change_value(t_input *input, char *key, char *value);

/* env_manager/env_converter.c */
void	env_converter(t_input *input, char *str);
void	fill_buffer(t_input *input, char *buffer);
void	fill_env(t_input *input, char *str, int *i, int *j);
void	fill_quotes(t_input *input, char *str, int *i, int *j);

/* env_manager/utils_env_counter.c */
int		count_env(t_input *input, char *str, int *i, int red);
int		count_quotes(t_input *input, char *str, int *i);

/* env_manager/utils_env_finder.c */
char	*find_key(t_input *input, char *str);
char	*find_value(t_input *input, char *str);

/* env_manager/utils_env.c */
char	*get_value(t_input *input, char *key);
int		search_key(const char *str, const char *key);
int		check_dubble(t_input *input, char *str);


#endif
