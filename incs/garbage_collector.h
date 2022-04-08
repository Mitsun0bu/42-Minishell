/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 10:02:50 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/08 14:52:53 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                               ~~~ DEFINES ~~~                              */
/*                                                                            */
/* ************************************************************************** */

#ifndef GARBAGE_COLLECTOR_H
# define GARBAGE_COLLECTOR_H

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

/* garbage collector/add_garbage.c */
void			add_garbage(t_garbage_lst **garbage, void *ptr);
void			add_garbage_front(t_garbage_lst **garbage, t_garbage_lst *new_garbage);
t_garbage_lst	*create_new_garbage(void *ptr);

/* garbage collector/assign_garbage_type.c */
void			assign_garbage_type(t_input *input, char **table, int garbage_type);

/* garbage collector/clear_garbage.c */
void			clear_all_garbage(t_garbage_lst **garbage);
void			clear_one_garbage_type(t_garbage_lst **garbage, int type);
int				count_garbage_type(t_garbage_lst **garbage, int type);

#endif