/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 17:07:56 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/19 19:19:26 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                               ~~~ DEFINES ~~~                              */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

/* ************************************************************************** */
/*                                                                            */
/*                               ~~~ INCLUDES ~~~                             */
/*                                                                            */
/* ************************************************************************** */

# include "header.h"
# include "built_ins.h"
# include "cmd_line_manager.h"
# include "cmd_lst_manager.h"
# include "cmd_separator.h"
# include "env_var_manager.h"
# include "error_manager.h"
# include "executer.h"
# include "gb_collector.h"
# include "parser.h"
# include "redir_collector.h"
# include "shell_initializer.h"
# include "signal_manager.h"
# include "utils.h"
# include "../libft/libft.h"

/* ************************************************************************** */
/*                                                                            */
/*                              ~~~ PROTOTYPES ~~~                            */
/*                                                                            */
/* ************************************************************************** */

extern int g_status;

/* main/main.c */
int	main(int ac, char **av, char **envp);

#endif
