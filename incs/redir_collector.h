/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_collector.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 11:15:36 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/21 13:05:45 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                               ~~~ DEFINES ~~~                              */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIR_COLLECOR_H
# define REDIR_COLLECOR_H

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

/* redir_collector/copy_filename_in_redir_tab.c */
int		copy_name_for_each_file(t_input *input, int i_cmd, int type, int i_file);
int		copy_infile(char *infile, char *cmd, int i_file);
int		copy_outfile(char *outfile, char *cmd, int i_file);
int		copy_delimiter(char *delimiter, char *cmd, int i_file);
int		copy_app_outfile(char *app_outfile, char *cmd, int i_file);

/* redir_collector/get_last_redir_type_tab.c */
void	get_last_redir_type_tab(t_input *input);
void	get_last_types(t_input *input, char *cmd, int i_cmd, int *i_start);
void	back_skip_quotes(char *str, int *i);

/* redir_collector/redir_collector_utils_counter.c */
int		count_n_file(char *cmd, int type);
int		count_infile_name_len(char *cmd, int i_file);
int		count_output_name_len(char *cmd, int i_file);
int		count_delimiter_len(char *cmd, int i_file);
int		count_app_output_name_len(char *cmd, int i_file);

/* redir_collector/redir_collector_utils_other.c */
int		bidim_tab_size(char **table);
int		skip_space(char *cmd, int *i);
int		is_space(char c);

/* redir_collector/utils_quotes_redir_collector.c */
int		count_in_quotes(char *cmd, int *i, int *len, char c);
int		count_out_quotes(int *i, int *len);
int		copy_in_quotes(char *file, int *file_cursor, char *cmd, int *cursor);
int		copy_out_quotes(char *file, int *file_cursor, char *cmd, int *cursor);

/* redir_collector/redir_collector.c */
void	redir_collector(t_input *input);

/* redir_collector/redir_tab_memory_manager.c */
int		malloc_cmd_dimension(t_input *input);
int		malloc_types_dimension_for_each_cmd(t_input *input);
int		malloc_n_file_dimension_for_each_type(t_input *input, int i_cmd, int type);
int		malloc_name_for_each_file(t_input *input, int i_cmd, int type, int i_file);

#endif