/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_tilde.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 14:29:04 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/29 17:01:22 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

// static char	*copy_other_char(t_input *input, char *str, int *i, int *red);

// char	*convert_tilde(t_input *input, char *str)
// {
// 	char	*line;
// 	int		i;
// 	int		red;

// 	red = NO;
// 	i = 0;
// 	line = ft_strdup(input, "");
// 	input->gb->type = GARBAGE;
// 	while (str[i])
// 	{
// 		if (str[i] == '~')
// 		{
// 			if (red == NO)
// 			{
// 				if (i == 0 && is_space(str[i + 1]) == YES)
// 				{


// 				}
// 				else if (is_space(str[i - 1]) == YES && is_space(str[i - 1]) == YES)
// 				{


// 				}
// 			}
// 			if (red == YES)
// 			{

// 			}
// 			if (red == HEREDOC)
// 			{



// 			}
// 		}
// 		else if (str[i] && str[i] != '~')
// 		{
// 			line = ft_strjoin(input, line, copy_other_char(input, str, &i, &red));
// 			input->gb->type = GARBAGE;
// 		}
// 	}
// 	return (line);
// }

// static char	*copy_other_char(t_input *input, char *str, int *i, int *red)
// {
// 	char	*new_line;
// 	int		start;

// 	start = *i;
// 	while (str[*i] && !ft_strchr("~", str[*i]))
// 		(*i)++;
// 	new_line = ft_substr(input, str, start, (*i) - start);
// 	printf("new_line = %s\n", new_line);
// 	red = identify_last_redir(new_line);
// 	printf("red = %d\n", red);
// 	return (new_line);
// }

// static int	identify_last_redir(char *new_line)
// {
// 	int	i;
// 	int	red;

// 	i = ft_strlen(new_line);
// 	while (i > 0)
// 	{
// 		if (ft_strchr("<>", new_line[i]))
// 		{
// 			if (new_line[i] == '<' && new_line[i - 1] == '<')
// 				red = HEREDOC;
// 			else
// 				red = YES;
// 		}
// 		i --;
// 	}
// }