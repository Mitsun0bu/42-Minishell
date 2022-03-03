/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_ins.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 11:56:09 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/03 16:27:55 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                               ~~~ DEFINES ~~~                              */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILT_INS_H
# define BUILT_INS_H

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

/* built_ins/ft_cd.c */
int		ft_cd(t_cmd_lst *lst_node);

/* built_ins/ft_echo.c */
int		ft_echo(t_cmd_lst *lst_node);
void	print_message(char *message);

/* built_ins/ft_env.c */
int		ft_env(t_input *input);

/* built_ins/ft_exit.c */
int		ft_exit(void);

/* built_ins/ft_pwd.c */
int		ft_pwd(t_cmd_lst *lst_node);

/* built_ins/ft_export.c */
int		ft_export(t_input *input);
int		parse_var(char *str, t_input *input);
int		parse_key(char	*str, t_input *input, int type);
char	*del_quotes(char	*str);
void	print_export(t_input *input);

/*built_ins/ft_unset.c */
int		ft_unset(t_input *input);
int		parse_arg(char *str);


#endif