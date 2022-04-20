/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 10:09:31 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/20 14:10:32 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                               ~~~ DEFINES ~~~                              */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

/* ************************************************************************** */
/*                                                                            */
/*                              ~~~ PROTOTYPES ~~~                            */
/*                                                                            */
/* ************************************************************************** */

/* parser/parser.c */
int		parser(t_input *input);

/* parser/arg_length.c */
void	count_quote(char *str, int *i, int *count, int red);
int		get_arg_len(char *str, int *i);
void	copy_quote(char *cmd, char *exec_cmd, int *i, int *j);
void	fill_tab(char *cmd, char *exec_cmd, int i);

/* parser/arg_number.c */
void	handle_quote(char *str, int *i, int *count, int *red);
int		get_arg_num(char *str);
int		create_arg_tab(t_input *input, int i);

/* parser/cleaner.c */
int		clean_cmd(t_input *input);

/* parser/utils_parser.c */
void	check_red(int *red, char *cmd, int *i);
int		is_space(char c);
int		check_next_arg(char *str, int i);
int		end_check(char *cmd, int *i, int *red);

#endif