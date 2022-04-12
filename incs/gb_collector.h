/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gb_collector.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 10:02:50 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/12 15:38:18 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                               ~~~ DEFINES ~~~                              */
/*                                                                            */
/* ************************************************************************** */

#ifndef GB_COLLECTOR_H
# define GB_COLLECTOR_H

/* ************************************************************************** */
/*                                                                            */
/*                              ~~~ PROTOTYPES ~~~                            */
/*                                                                            */
/* ************************************************************************** */

/* gb collector/add_gb.c */
void		add_gb(t_gb_lst **gb, void *ptr);
void		add_gb_front(t_gb_lst **gb, t_gb_lst *new_gb);
t_gb_lst	*create_new_gb(void *ptr);

/* gb collector/assign_gb_type.c */
void		assign_gb_type(t_input *input, char **table, int gb_type);

/* gb collector/clear_gb.c */
void		clear_all_gb(t_gb_lst **gb);
void		clear_one_gb_type(t_gb_lst **gb, int type);
int			count_gb_type(t_gb_lst **gb, int type);

#endif