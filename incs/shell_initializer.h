/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_initializer.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 10:25:43 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/20 10:02:09 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                               ~~~ DEFINES ~~~                              */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_INITIALIZER_H
# define SHELL_INITIALIZER_H

/* ************************************************************************** */
/*                                                                            */
/*                              ~~~ PROTOTYPES ~~~                            */
/*                                                                            */
/* ************************************************************************** */

/* shell_initializer/init_shell.c */
void	shell_init(int ac, char **av, char **envp, t_input *input);
void	init_message(void);
void	init_env(t_input *input, char **envp);
void	init_shlvl(t_input *input);
void	init_history(t_input *input);

#endif
