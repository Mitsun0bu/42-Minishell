/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 13:23:23 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/02 19:12:09 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                               ~~~ DEFINES ~~~                              */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

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

/* lexer/lexer.c */
void	lexer(t_input *input);

/* lexer/cmd_separator.c */
int		single_cmd(t_input *input);
int		split_multi_cmd(t_input *input);
int		final_pipe_case(t_input *input);

/*lexer/fill_last_output_redir_tab.c */
int		fill_last_output_redir_type_tab(t_input *input);

/* lexer/fill_redir_tab_app_output.c */
int		fill_redir_tab_app_output(t_input *input);
int		cp_app_output_name(t_input *input, char *cmd, int *i_cmd, int *i_red);

/* lexer/fill_redir_tab_heredoc */
int		fill_redir_tab_heredoc(t_input *input);
int		cp_heredoc_name(t_input *input, char *cmd, int *i_cmd, int *i_red);

/* lexer/fill_redir_tab_input.c */
int		fill_redir_tab_input(t_input *input);
int		cp_input_name(t_input *input, char *cmd, int *i_cmd, int *i_red);

/* lexer/fill_redir_tab_output.c */
int		fill_redir_tab_output(t_input *input);
int		cp_output_name(t_input *input, char *cmd, int *i_cmd, int *i_red);

/* lexer/redir_manager_app_output.c */
int		malloc_app_output_redir_tab(t_input *input);
int		count_app_output_redir(char *cmd);
int		malloc_app_output_name(t_input *input, int *i_cmd);
int		count_app_output_name_len(char *cmd, int *i_red);

/* lexer/redir_manager_heredoc.c */
int		malloc_heredoc_redir_tab(t_input *input);
int		count_heredoc_redir(char *cmd);
int		malloc_heredoc_name(t_input *input, int *i_cmd);
int		count_heredoc_name_len(char *cmd, int *i_red);

/* lexer/redir_manager_input.c */
int		malloc_input_redir_tab(t_input *input);
int		count_input_redir(char *cmd);
int		malloc_input_name(t_input *input, int *i_cmd);
int		count_input_name_len(char *cmd, int *i_red);

/* lexer/redir_manager_output.c */
int		malloc_output_redir_tab(t_input *input);
int		count_output_redir(char *cmd);
int		malloc_output_name(t_input *input, int *i_cmd);
int		count_output_name_len(char *cmd, int *i_red);

/* lexer/redir_tab_memory_manager.c */
int		malloc_redir_tab(t_input *input);
int		malloc_redir_subdiv(t_input *input);
int		malloc_redir_solo(t_input *input);

/* lexer/utils_other_lexer.c */
int		bidim_tab_size(char **table);
int		skip_space(char *cmd, int *i);
int		is_space(char c);

/* lexer/utils_quotes_lexer.c */
int		count_in_quotes(char *cmd, int *i, int *len, char c);
int		cp_in_quotes(char *red, char *cmd, int *i, int *j);
int		count_out_quotes(int *i, int *len);
int		cp_out_quotes(char *red, char *cmd, int	*j, int	*i);

#endif
