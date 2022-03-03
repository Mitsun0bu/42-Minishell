/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_manager.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:21:58 by agirardi          #+#    #+#             */
/*   Updated: 2022/03/03 17:15:53 by llethuil         ###   ########lyon.fr   */
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

/* env_manager/env_parser.c */
void	parse_env(t_input *input);
int	count_quotes(char *str, int *i, t_input *input);
void	fill_buffer(char *buffer, t_input *input);
void	fill_env(char *buffer, int *i, int *j, t_input *input);

/* env_manager/env_utils.c */
void	free_env(t_input *input);
char	*find_key(char *str);
char	*find_value(char *str);
int		count_env(char *str, int *i, int red, t_input *input);
char	*get_value(char *str, t_input *input);
int		search_key(const char *str, const char *key);
int		check_dubble(char *str, t_input *input);

/* env_manager/env.c */
void	add_to_env(t_input *input, char *str, int is_global);
void	init_env(t_input *input, char **envp);
void	remove_from_env(t_input *input, char *key);
void	change_value(t_input *input, char *key, char *value);


#endif
