/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_ins.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 11:56:09 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/19 15:40:32 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                               ~~~ DEFINES ~~~                              */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILT_INS_H
# define BUILT_INS_H

/* ************************************************************************** */
/*                                                                            */
/*                              ~~~ PROTOTYPES ~~~                            */
/*                                                                            */
/* ************************************************************************** */

/* built_ins/ft_cd.c */
int		ft_cd(t_input *input, t_cmd_lst *cmd);
void	update_oldpwd(t_input *input, char *destination);

/* built_ins/ft_echo.c */
int		ft_echo(t_input *input, t_cmd_lst *cmd);
char	*join_message(t_input *input, t_cmd_lst *cmd);
void	add_first_word_to_message(t_input *input, t_cmd_lst *cmd, int *i);
void	add_next_words_to_message(t_input *input, t_cmd_lst *cmd, int *i);
void	print_message(char *message);

/* built_ins/ft_env.c */
int		ft_env(t_input *input);

/* built_ins/ft_exit.c */
int		ft_exit(t_input *input, t_cmd_lst *cmd);

/* built_ins/ft_pwd.c */
int		ft_pwd(void);

/* built_ins/ft_export.c */
int		ft_export(t_input *input, t_cmd_lst *cmd);
int		parse_env_var(t_input *input, char *var);
int		parse_key(t_input *input, char	*str, int type);
void	print_export(t_input *input);

/*built_ins/ft_unset.c */
int		ft_unset(t_input *input, t_cmd_lst *cmd);
int		parse_arg(char *str);

#endif