/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 11:29:37 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/12 17:49:41 by llethuil         ###   ########lyon.fr   */
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

/* utils.c/clean_str.c */
char	*clean_str(t_input *input, char *str);
int		get_clean_str_len(char *str);
char	*fill_clean_str(t_input *input, char *str, int len);

/* utils.c/ft_free.c */
void	ft_free(void **ptr);

/* utils.c/get_histroy_path.c */
char	*get_history_path(t_input *input);

/* utils.c/is_space.c */
int		is_space(char c);

/* utils.c/skip_quotes.c */
void	skip_quotes(char *str, int *i);

#endif