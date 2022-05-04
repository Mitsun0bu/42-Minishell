/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_separator.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 10:09:31 by llethuil          #+#    #+#             */
/*   Updated: 2022/05/04 17:59:00 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                               ~~~ DEFINES ~~~                              */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARG_SEPARATOR_H
# define ARG_SEPARATOR_H

/* ************************************************************************** */
/*                                                                            */
/*                              ~~~ PROTOTYPES ~~~                            */
/*                                                                            */
/* ************************************************************************** */

/* arg_separator/arg_separator.c */
int		arg_separator(t_input *input);

/* arg_separator/create_arg_tab.c */
int		create_arg_tab(t_input *input, int i);

/* arg_separator/get_arg_len.c */
int		get_arg_len(char *str, int *i);

/* arg_separator/get_number_of_arg.c */
int		get_number_of_arg(char *str);

#endif