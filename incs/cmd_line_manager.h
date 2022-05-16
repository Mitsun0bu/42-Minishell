/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_line_manager.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 16:36:06 by llethuil          #+#    #+#             */
/*   Updated: 2022/05/16 14:30:50 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                               ~~~ DEFINES ~~~                              */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_LINE_MANAGER_H
# define CMD_LINE_MANAGER_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

/* ************************************************************************** */
/*                                                                            */
/*                              ~~~ PROTOTYPES ~~~                            */
/*                                                                            */
/* ************************************************************************** */

/* cmd_line_manager/cmd_line_manager.c */
int		cmd_line_manager(t_input *input);
char	*convert_tilde_in_str(t_input *input, char *str);

/*cmd_line_manager/check_is_space.c */
int		check_is_space(t_input *input);

/* cmd_seprator/check_redir.c */
int		check_redir(t_input *input);

/* cmd_separator/check_quotes.c */
int		check_quotes(t_input *input);

/* cmd_separator/check_pipe.c */
int		check_pipe(t_input *input);

#endif