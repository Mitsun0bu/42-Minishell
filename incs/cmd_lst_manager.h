/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_lst_manager.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:32:59 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/12 17:48:33 by llethuil         ###   ########lyon.fr   */
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
/*                              ~~~ PROTOTYPES ~~~                            */
/*                                                                            */
/* ************************************************************************** */

/* cmd_lst_manager/cmd_lst_init.c */
void		cmd_lst_init(t_input *input, t_cmd_lst **cmd);
t_cmd_lst	*create_new_cmd(t_input *input, int *i);

/* cmd_lst_manager/cmd_manager.c */
void		cmd_args_manager(t_input *input, int *i, t_cmd_lst *new_cmd);
void		cmd_infile_manager(t_input *input, int *i, t_cmd_lst *new_cmd);
void		cmd_outfile_manager(t_input *input, int *i, t_cmd_lst *new_cmd);
void		cmd_app_outfile_manager(t_input *input, int *i, t_cmd_lst *new_cmd);
void		cmd_heredoc_manager(t_input *input, int *i, t_cmd_lst *new_cmd);

/* cmd_lst_manager/utils_cmd_lst_manager.c */
void		add_cmd_back(t_cmd_lst *cmd, t_cmd_lst *new_cmd);
t_cmd_lst	*find_last_cmd(t_cmd_lst *cmd);

#endif