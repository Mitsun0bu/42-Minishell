/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_lst_manager.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:32:59 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/24 11:01:37 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                               ~~~ DEFINES ~~~                              */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_LST_MANAGER_H
# define CMD_LST_MANAGER_H

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

/* cmd_lst_manager/cmd_lst_init.c */
int			cmd_lst_init(t_input *input, t_cmd_lst **cmd);
t_cmd_lst	*create_new_cmd(t_input *input, int *i);

/* cmd_lst_manager/cmd_manager.c */
int			cmd_args_manager(t_input *input, int *i, t_cmd_lst *new_cmd);
int			cmd_input_redir_manager(t_input *input, int *i, t_cmd_lst *new_cmd);
int			cmd_output_redir_manager(t_input *input, int *i, t_cmd_lst *new_cmd);
int			cmd_app_output_redir_manager(t_input *input, int *i, t_cmd_lst *new_cmd);
int			cmd_heredoc_manager(t_input *input, int *i, t_cmd_lst *new_cmd);

/* cmd_lst_manager/utils_linked_lst.c */
void		add_cmd_back(t_cmd_lst **cmd, t_cmd_lst *new_cmd);
t_cmd_lst	*find_last_cmd(t_cmd_lst *cmd);

#endif