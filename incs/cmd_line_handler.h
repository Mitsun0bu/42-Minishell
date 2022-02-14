/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_line_handler.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 16:36:06 by llethuil          #+#    #+#             */
/*   Updated: 2022/02/14 11:54:27 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                               ~~~ DEFINES ~~~                              */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_LINE_HANDLER_H
# define CMD_LINE_HANDLER_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

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

/* cmd_line_handler/cmd_line_handler.c */
void	cmd_line_handler(t_input *input);

/* cmd_line_handler/get_cmd_line.c */
int	get_cmd_line(t_input *input, int fd);
int	open_history_file(void);
int	get_history(int	fd);
int	ft_strlen_gnl(char *str);

/* cmd_line_handler/get_next_line.c */
char	*get_next_line(int fd);
char	*ft_get_line(char *line, char *buff, int fd);
int		position_nl(char *str);
char	*strjoin_gnl(char *line, char *buff);



#endif