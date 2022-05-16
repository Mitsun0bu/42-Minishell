/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_collector.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 11:15:36 by llethuil          #+#    #+#             */
/*   Updated: 2022/05/16 15:43:19 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                               ~~~ DEFINES ~~~                              */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIR_COLLECTOR_H
# define REDIR_COLLECTOR_H

/* ************************************************************************** */
/*                                                                            */
/*                              ~~~ PROTOTYPES ~~~                            */
/*                                                                            */
/* ************************************************************************** */

/* redir_collector/copy_filename_in_redir_tab.c */
void	copy_filenames_in_redir_tab(t_input *input, int i_c, int type, int i_f);

/* redir_collector/get_last_redir_types_tab.c */
void	get_last_redir_types_tab(t_input *input);

/* redir_collector/redir_collector.c */
void	redir_collector(t_input *input);

#endif
