/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_separator.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 10:23:10 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/20 15:55:29 by llethuil         ###   ########lyon.fr   */
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

/* cmd_separator/cmd_separator.c */
int		cmd_separator(t_input *input);

/* cmd_separator/check_pipe.c */
int		check_pipe(t_input *input);
void	change_quote_state(int	*quote_state);

/* cmd_separator/check_quotes.c */
int		check_quotes(t_input *input);
int		find_unclosed_quotes(char *str);

/* cmd_seprator/check_redir.c */
int		check_redir(t_input *input);
int		check_redir_validity(t_input *input, char *str, int *i);
void	select_err_mess(t_input *input, int type);
char	*build_err_mess(t_input *input, int type);

/* cmd_separator/split_cmd.c */
int		split_cmd(t_input *input);
int		final_letter_is_pipe(char *str);
int		fill_cmd(t_input *input);
int		fill_cmd_child(t_input *input, char *filled_cmd, int *final_pipe_fd);

#endif