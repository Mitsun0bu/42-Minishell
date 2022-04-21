/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 11:29:37 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/21 16:44:01 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                               ~~~ DEFINES ~~~                              */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

/* ************************************************************************** */
/*                                                                            */
/*                              ~~~ PROTOTYPES ~~~                            */
/*                                                                            */
/* ************************************************************************** */

/* utils.c/back_skip_quotes.c */
void	back_skip_quotes(char *str, int *i);

/* utils.c/clean_str.c */
char	*clean_str(t_input *input, char *str);
int		get_clean_str_len(char *str);
char	*fill_clean_str(t_input *input, char *str, int len);

/*utils.c/copy_filename.c */
void	copy_filename(char *dest, char *cmd, int i_file, char c);

/*utils.c/count_filename_len.c */
int		count_filename_len(char *cmd, int i_file, char c);
int		count_filename_len(char *cmd, int i_file, char c);

/*utils.c/count_n_file.c */
int		count_n_file(char *cmd, int type);

/* utils.c/ft_free.c */
void	ft_free(void **ptr);

/* utils.c/get_g_status.c */
char	*get_g_status(t_input *input);

/* utils.c/get_histroy_path.c */
char	*get_history_path(t_input *input);

/* utils.c/is_space.c */
int		is_space(char c);

/* utils.c/skip_quotes.c */
void	skip_quotes(char *str, int *i);

/* utils.c/skip_space_after_chev.c */
void	skip_space_after_chev(char *cmd, int *i);

#endif