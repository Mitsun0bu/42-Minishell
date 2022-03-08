/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_manager.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:21:58 by agirardi          #+#    #+#             */
/*   Updated: 2022/03/08 12:00:07 by llethuil         ###   ########lyon.fr   */
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
void	add_to_env(t_input *input, char *str, int is_global);
void	remove_from_env(t_input *input, char *key);
void	change_value(t_input *input, char *key, char *value);

/* env_manager/utils_env_counter.c */
int		count_env(char *str, int *i, int red, t_input *input);
int		count_quotes(char *str, int *i, t_input *input);

/* env_manager/utils_env_finder.c */
char	*find_key(char *str);
char	*find_value(char *str);

/* env_manager/utils_env.c */
char	*get_value(char *key, t_input *input);
int		search_key(const char *str, const char *key);
int		check_dubble(char *str, t_input *input);


#endif
