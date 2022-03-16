/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_collector.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 13:23:23 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/16 10:23:49 by llethuil         ###   ########lyon.fr   */
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

/*redir_collector/fill_last_output_redir_tab.c */
int		fill_last_output_redir_type_tab(t_input *input);
void	back_skip_quotes(char *str, int *i);

/* redir_collector/redir_collector.c */
void	redir_collector(t_input *input);

/* redir_collector/redir_tab_memory_manager.c */
int		malloc_all_cmd_in_redir_tab(t_input *input);
int		malloc_redir_types_in_redir_tab(t_input *input);
int		malloc_any_redir_in_redir_tab(t_input *input, int type);
int		malloc_any_filename_in_redir_tab(t_input *input, int type);

/* redir_collector/utils_counter_redir_collector.c */
int		count_any_redir(char *cmd, int type);
int		count_input_name_len(char *cmd, int	*i_red);
int		count_output_name_len(char *cmd, int *i_red);
int		count_delimiter_len(char *cmd, int *i_red);
int		count_app_output_name_len(char *cmd, int *i_red);

/* redir_collector/utils_other_redir_collector.c */
int		bidim_tab_size(char **table);
int		skip_space(char *cmd, int *i);
int		is_space(char c);

/* redir_collector/utils_quotes_redir_collector.c */
int		count_in_quotes(char *cmd, int *i, int *len, char c);
int		cp_in_quotes(char *red, char *cmd, int *i, int *j);
int		count_out_quotes(int *i, int *len);
int		cp_out_quotes(char *red, char *cmd, int	*j, int	*i);

/* redir_collector/write_any_redir_in_redir_tab.c */
int		write_any_redir_in_redir_tab(t_input *input, int type);
void	cp_input_name(t_input *input, char *cmd, int *i_cmd, int *i_red);
void	cp_output_name(t_input *input, char *cmd, int *i_cmd, int *i_red);
void	cp_delimiter_name(t_input *input, char *cmd, int *i_cmd, int *i_red);
void	cp_app_output_name(t_input *input, char *cmd, int *i_cmd, int *i_red);

#endif
