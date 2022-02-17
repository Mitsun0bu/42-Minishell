/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_lst_init.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:32:59 by llethuil          #+#    #+#             */
/*   Updated: 2022/02/17 18:04:38 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                               ~~~ DEFINES ~~~                              */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_LST_INIT_H
# define CMD_LST_INIT_H

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

/* cmd_lst_init/cmd_lst_init.c */
int			cmd_lst_init(t_input *input, t_cmd_lst **lst_head);

/* cmd_lst_init/node_manager.c */
int			node_args_manager(int *i, t_cmd_lst *new_node, t_input *input);
int			node_input_redir_manager(int *i, t_cmd_lst *new_node, t_input *input);
int			node_output_redir_manager(int *i, t_cmd_lst *new_node, t_input *input);
int			node_app_output_redir_manager(int *i, t_cmd_lst *new_node, t_input *input);
int			node_heredoc_manager(int *i, t_cmd_lst *new_node, t_input *input);

/* cmd_lst_init/utils_linked_lst.c */
void		add_node_back(t_cmd_lst **lst_head, t_cmd_lst *new_node);
t_cmd_lst	*is_last_node(t_cmd_lst *lst_head);
t_cmd_lst	*create_new_node(int *i, t_input *input);

#endif