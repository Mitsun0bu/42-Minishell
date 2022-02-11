/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 13:23:23 by llethuil          #+#    #+#             */
/*   Updated: 2022/02/10 18:17:33 by llethuil         ###   ########lyon.fr   */
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

# include "minishell.h"

/* ************************************************************************** */
/*                                                                            */
/*                              ~~~ PROTOTYPES ~~~                            */
/*                                                                            */
/* ************************************************************************** */

/* cmd_separator.c */
int		single_cmd(t_input *input);
int		split_multi_cmd(t_input *input);
int		final_pipe_case(t_input *input);

/* fill_redir_tab_app_output.c */
int		fill_redir_tab_app_output(t_input *input);
int		cp_app_output_name(t_input *input, char *cmd, int *i_cmd, int *i_red);

/* fill_redir_tab_heredoc */
int		fill_redir_tab_heredoc(t_input *input);
int		cp_heredoc_name(t_input *input, char *cmd, int *i_cmd, int *i_red);

/* fill_redir_tab_input.c */
int		fill_redir_tab_input(t_input *input);
int		cp_input_name(t_input *input, char *cmd, int *i_cmd, int *i_red);

/* fill_redir_tab_output.c */
int		fill_redir_tab_output(t_input *input);
int		cp_output_name(t_input *input, char *cmd, int *i_cmd, int *i_red);

/* main_lexer.c */
void	main_lexer(t_input *input);

/* redir_manager_app_output.c */
int		malloc_app_output_redir_tab(t_input *input);
int		count_app_output_redir(char *cmd);
int		malloc_app_output_name(t_input *input, int *i_cmd);
int		count_app_output_name_len(char *cmd, int *i_red);

/* redir_manager_heredoc.c */
int		malloc_heredoc_redir_tab(t_input *input);
int		count_heredoc_redir(char *cmd);
int		malloc_heredoc_name(t_input *input, int *i_cmd);
int		count_heredoc_name_len(char *cmd, int *i_red);

/* redir_manager_input.c */
int		malloc_input_redir_tab(t_input *input);
int		count_input_redir(char *cmd);
int		malloc_input_name(t_input *input, int *i_cmd);
int		count_input_name_len(char *cmd, int *i_red);

/* redir_manager_output.c */
int		malloc_output_redir_tab(t_input *input);
int		count_output_redir(char *cmd);
int		malloc_output_name(t_input *input, int *i_cmd);
int		count_output_name_len(char *cmd, int *i_red);

/* redir_tab_memory_manager.c */
int		malloc_redir_tab(t_input *input);
int		malloc_redir_subdiv(t_input *input);
int		malloc_redir_solo(t_input *input);

/* utils_other_lexer.c */
int		bidim_tab_size(char **table);
int		skip_space(char *cmd, int *i);
int		is_space(char c);

/* utils_quotes_lexer.c */
int		count_in_quotes(char *cmd, int *i, int *len, char c);
int		cp_in_quotes(char *red, char *cmd, int *i, int *j);
int		count_out_quotes(int *i, int *len);
int		cp_out_quotes(char *red, char *cmd, int	*j, int	*i);

#endif
