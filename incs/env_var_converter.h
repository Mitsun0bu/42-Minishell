/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var_converter.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:21:58 by agirardi          #+#    #+#             */
/*   Updated: 2022/04/26 15:35:05 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                               ~~~ DEFINES ~~~                              */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_VAR_MANAGER_H
# define ENV_VAR_MANAGER_H

/* ************************************************************************** */
/*                                                                            */
/*                              ~~~ PROTOTYPES ~~~                            */
/*                                                                            */
/* ************************************************************************** */

/* env_manager/convert_env_var_in_str.c */
char	*convert_env_var_in_str(t_input *input, char *str);

/* env_manager/convert_env_var.c */
char	*convert_env_var(t_input *input, char *str, int *i, int red);

/* env_manager/copy_in_quote.c */
char	*copy_env_var_in_quote(t_input *input, char *str, int *i, int red);

/* env_manager/copy_basic_char.c */
char	*copy_basic_char(t_input *input, char *str, int *i, int *red);

#endif
