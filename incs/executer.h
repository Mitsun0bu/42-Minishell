/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 12:09:40 by llethuil          #+#    #+#             */
/*   Updated: 2022/02/24 20:11:54 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                               ~~~ DEFINES ~~~                              */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTER_H
# define EXECUTER_H

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

/* executer/executer.c */
int		executer(char **envp, t_input *input, t_cmd_lst **lst_node);
void	exec_single_cmd(char **envp, t_input *input, t_cmd_lst **lst_node);
int		exec_multi_cmd(char **envp, t_input *input, t_cmd_lst **lst_node);
int		pipex(char **envp, t_input *input, t_cmd_lst *lst_node);
void	exec_current_cmd(char **envp, t_cmd_lst *lst_node);


/* executer/file_manager.c */
int		open_files(t_cmd_lst **lst_node);
int		open_infiles(t_cmd_lst *lst_node);
int		open_outfiles(t_cmd_lst *lst_node);
int		open_app_outfiles(t_cmd_lst *lst_node);


/* executer/path_manager.c */
void	path_manager(char **envp, t_input *input, t_cmd_lst **lst_node);
void	get_paths_tab(char **envp, t_input	*input);
char	*assign_path(char *arg, t_input *input, t_cmd_lst *lst_node);

#endif