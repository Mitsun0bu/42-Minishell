/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 11:29:37 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/16 17:39:52 by llethuil         ###   ########lyon.fr   */
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
/*                               ~~~ INCLUDES ~~~                             */
/*                                                                            */
/* ************************************************************************** */

# include "main.h"
# include <stdlib.h>

/* ************************************************************************** */
/*                                                                            */
/*                              ~~~ PROTOTYPES ~~~                            */
/*                                                                            */
/* ************************************************************************** */

/* utils/utils_free_lst */
void	free_lst(t_cmd_lst	**cmd);
void	free_cmd(t_cmd_lst *cmd);

/* utils/utils_free.c */
void	free_input_struct(t_input *input);
void	free_env_struct(t_input *input);

/* utils/utils_free.c */
void	ft_free(void **ptr);
void	free_double(char **array);
void	free_quad(char ****array);
void	free_triple(char ***array);

/* utils/utils_history.c */
char	*get_next_line(int fd);
char	*ft_get_line(char *line, char *buff, int fd);
int		position_nl(char *str);
char	*strjoin_gnl(char *line, char *buff);
char	*get_history_path(t_input *input);

/* utils.c */
int		is_isspace(char c);
void	skip_quotes(char *str, int *i);
void	*safe_malloc(size_t size, size_t count);

#endif