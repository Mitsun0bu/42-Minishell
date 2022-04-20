/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 13:18:59 by agirardi          #+#    #+#             */
/*   Updated: 2022/04/20 16:41:35 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	check_redir(t_input *input)
{
	int	i;

	i = -1;
	while (input->cmd_line[++i])
	{
		while (is_space(input->cmd_line[i]))
			i ++;
		if (ft_strchr("\"\'", input->cmd_line[i]))
			skip_quotes(input->cmd_line, &i);
		if (ft_strchr("<>", input->cmd_line[i]))
			if (check_redir_validity(input, input->cmd_line, &i) == FAILED)
				return (FAILED);
	}
	return (SUCCESS);
}

int	check_redir_validity(t_input *input, char *str, int *i)
{
	char	c;
	char	c_double;

	c = str[*i];
	(*i) ++;
	if (ft_strchr("<>", str[*i]))
	{
		c_double = str[*i];
		(*i) ++;
	}
	if (!str[(*i)])
	{
		if (c == '>' && c_double == '<')
			select_err_mess(input, INFILE);
		select_err_mess(input, NEW_LINE);
		return (FAILED);
	}
	// if (ft_strchr("\"\'", str[*i]))
	// 	skip_quotes(str, &i);
	// while (is_space(str[*i]))
	// 	(*i) ++;
	// if (ft_strchr("<>", str[*i]))
	// {
	// 	if (str[*i] = '>' && str[(*i) + 1] = '>')




	// }
	return (SUCCESS);
}

// int	check_redir_validity(t_input *input, char *str, int *i)
// {
// 	(*i) ++;
// 	if (!str[(*i)])
// 	{
// 		select_err_mess(input, NEW_LINE);
// 		return (FAILED);
// 	}
// 	else if (ft_strchr("<>", str[*i]) && !str[(*i) + 1])
// 	{
// 		if (str[*i] == '<' && str[(*i) - 1] == '>')
// 			select_err_mess(input, INFILE);
// 		else
// 			select_err_mess(input, NEW_LINE);
// 		return (FAILED);
// 	}
// 	else if (ft_strchr("<>", str[*i]))
// 	{
// 		(*i) ++;
// 		while (is_space(str[*i]) == YES)
// 			(*i) ++;
// 		if (str[*i] == '<' && str[*i + 1] != '<')
// 			select_err_mess(input, INFILE);
// 		else if (str[*i] == '>' && str[*i + 1] != '>')
// 			select_err_mess(input, OUTFILE);
// 		else if (str[*i] == '<' && str[*i + 1] == '<')
// 			select_err_mess(input, HEREDOC);
// 		else if (str[*i] == '>' && str[*i + 1] == '>')
// 			select_err_mess(input, APP_OUTFILE);
// 		return (FAILED);
// 	}
// 	else
// 		return (SUCCESS);
// }

void	select_err_mess(t_input *input, int type)
{
	char	*err_message;

	err_message = build_err_mess(input, type);
	print_err(258, NULL, NULL, err_message);
}

char *build_err_mess(t_input *input, int type)
{
	char	*pre_message;
	char	*final_message;

	pre_message = "syntax error near unexpected token ";
	final_message = NULL;
	if (type == NEW_LINE)
		final_message = ft_strjoin(input, pre_message, "`newline'");
	else if(type == INFILE)
		final_message = ft_strjoin(input, pre_message, "`<'");
	else if (type == OUTFILE)
		final_message = ft_strjoin(input, pre_message, "`>'");
	else if (type == HEREDOC)
		final_message = ft_strjoin(input, pre_message, "`>>'");
	else if (type == APP_OUTFILE)
		final_message = ft_strjoin(input, pre_message, "`<<'");
	input->gb->type = GARBAGE;
	return (final_message);
}
