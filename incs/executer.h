/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 12:09:40 by llethuil          #+#    #+#             */
/*   Updated: 2022/02/22 16:03:54 by llethuil         ###   ########lyon.fr   */
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
int		executer(char **av, char **envp, t_input *input, t_cmd_lst **lst_head);
void	exec_cmd(t_input *input, char **av, char **envp);
int		pipex(t_input *input, t_cmd_lst **lst_head);
int		create_pipes(t_input *input, t_pip *pip);


/* executer/file_manager.c */
int		open_files(t_cmd_lst **lst_head);
int		open_infiles(t_cmd_lst *lst_head);
int		open_outfiles(t_cmd_lst *lst_head);
int		open_app_outfiles(t_cmd_lst *lst_head);


/* executer/path_manager.c */
void	path_manager(char **av, char **envp, t_input *input, t_cmd_lst **lst_head);
void	get_paths_tab(char **envp, t_input	*input);
char	*assign_path(char **av, char *arg, t_input *input, t_cmd_lst *lst_head);

#endif