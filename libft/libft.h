/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 15:21:56 by llethuil          #+#    #+#             */
/*   Updated: 2022/05/12 09:31:54 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                  DEFINES                                   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

/* ************************************************************************** */
/*                                                                            */
/*                                  INCLUDES                                  */
/*                                                                            */
/* ************************************************************************** */

# include <fcntl.h>
# include <limits.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "../incs/main.h"

/* ************************************************************************** */
/*                                                                            */
/*                                  TYPEDEFS                                  */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/* ************************************************************************** */
/*                                                                            */
/*                                  PROTOTYPES                                */
/*                                                                            */
/* ************************************************************************** */

long long	ft_atoi(char *str);
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(t_input *input, size_t size, size_t count);
char		*ft_get_next_line(t_input *input, int fd);
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isdigit(int c);
char		*ft_itoa(t_input *input, int n);
void		*ft_malloc(t_input *input, size_t size, size_t count);
void		*ft_memset(void *b, int c, size_t len);
void		ft_putstr_fd(char *s, int fd);
char		**ft_mini_split(t_input *input, char *s);
char		**ft_split(t_input *input, char *s, char c);
char		*ft_strchr(char *s, int c);
char		*ft_strdup(t_input *input, char *s1);
char		*ft_strjoin(t_input *input, char *s1, char *s2);
size_t		ft_strlcpy(char *dst, char *src, size_t dstsize);
size_t		ft_strlen(char *str);
int			ft_strncmp(char *s1, char *s2, size_t n);
char		*ft_strnstr(char *haystack, char *needle, size_t len);
char		*ft_strtrim(t_input *input, char *s1, char *set);
char		*ft_substr(t_input *input, char *s, unsigned int start, size_t len);

#endif
