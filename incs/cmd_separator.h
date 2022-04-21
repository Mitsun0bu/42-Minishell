/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_separator.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 10:23:10 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/21 15:24:26 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                               ~~~ DEFINES ~~~                              */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_SEPARATOR_H
# define CMD_SEPARATOR_H

/* ************************************************************************** */
/*                                                                            */
/*                              ~~~ PROTOTYPES ~~~                            */
/*                                                                            */
/* ************************************************************************** */

/* cmd_separator/check_pipe.c */
int		check_pipe(t_input *input);

/* cmd_separator/check_quotes.c */
int		check_quotes(t_input *input);

/* cmd_seprator/check_redir.c */
int		check_redir(t_input *input);

/* cmd_separator/cmd_separator.c */
int		cmd_separator(t_input *input);

/* cmd_separator/simulate_heredoc.c */
void	simulate_heredoc(t_input *input);

/* cmd_separator/split_cmd.c */
int		split_cmd(t_input *input);

#endif