/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_ins.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 11:56:09 by llethuil          #+#    #+#             */
/*   Updated: 2022/02/23 15:24:45 by llethuil         ###   ########lyon.fr   */
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
void	ft_echo(t_cmd_lst *lst_node);
void	print_message(char *message);

/* built_ins/ft_env.c */
int		ft_env(t_input *input);

/* built_ins/ft_exit.c */
void	ft_exit(void);

/* built_ins/ft_pwd.c */
void	ft_pwd(t_cmd_lst *lst_node);

/* built_ins/built_ins.c */
int		ft_env(t_input *input);
int		ft_export(t_input *input);
int		ft_unset(t_input *input);


#endif