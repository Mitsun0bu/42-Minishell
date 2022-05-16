/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 13:18:59 by agirardi          #+#    #+#             */
/*   Updated: 2022/05/16 14:44:03 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int	red_is_valid(t_input *input, int *i);
static int	check_sgl_chev_red(t_input *input, char *str, int *i);
static int	check_dbl_chev_red(t_input *input, char *str, int *i);
static void	select_err_mess(t_input *input, int type);

int	check_redir(t_input *input)
{
	int	i;

	i = 0;
	while (input->cmd_line[i])
	{
		while (is_space(input->cmd_line[i]))
			i ++;
		if (!input->cmd_line[i])
			break ;
		if (ft_strchr("\"\'", input->cmd_line[i]))
			skip_quotes(input->cmd_line, &i);
		if (input->cmd_line[i] && ft_strchr("<>", input->cmd_line[i]))
		{
			if (red_is_valid(input, &i) == NO)
				return (FAILED);
		}
		else if (input->cmd_line[i])
			i ++;
	}
	return (SUCCESS);
}

static int	red_is_valid(t_input *input, int *i)
{
	input->i_syntax_err = *i;
	if (!ft_strchr("<>", input->cmd_line[*i + 1]) || !input->cmd_line[*i + 1])
	{
		if (check_sgl_chev_red(input, input->cmd_line, i) == FAILED)
			return (NO);
	}
	else if (ft_strchr("<>", input->cmd_line[*i + 1]))
	{
		if (check_dbl_chev_red(input, input->cmd_line, i) == FAILED)
			return (NO);
	}
	return (YES);
}

static int	check_sgl_chev_red(t_input *input, char *str, int *i)
{
	(*i)++;
	while (is_space(str[*i]))
		(*i)++;
	if (!str[(*i)])
	{
		select_err_mess(input, NEW_LINE);
		return (FAILED);
	}
	else if (ft_strchr("<>", str[(*i)]))
	{
		if (str[*i] == '<' && (!str[(*i) + 1] || str[(*i) + 1] == ' '))
			select_err_mess(input, INFILE);
		else if (str[*i] == '>' && (!str[(*i) + 1] || str[(*i) + 1] == ' '))
			select_err_mess(input, OUTFILE);
		else if (str[*i] == '<' && str[(*i) + 1] == '<')
			select_err_mess(input, HEREDOC);
		else if (str[*i] == '>' && str[(*i) + 1] == '>')
			select_err_mess(input, APP_OUTFILE);
		return (FAILED);
	}
	return (SUCCESS);
}

static int	check_dbl_chev_red(t_input *input, char *str, int *i)
{
	char	double_c[3];

	double_c[2] = '\0';
	double_c[0] = str[*i];
	(*i)++;
	double_c[1] = str[*i];
	if (!str[(*i) + 1])
	{
		if (double_c[0] == '>' && double_c[1] == '<')
			select_err_mess(input, INFILE);
		else
			select_err_mess(input, NEW_LINE);
		return (FAILED);
	}
	else if (str[*i + 1] == '<' || str[*i + 1] == '>' )
	{
		if (double_c[0] == '<')
			select_err_mess(input, INFILE);
		else if (double_c[0] == '>')
			select_err_mess(input, OUTFILE);
		return (FAILED);
	}
	return (0);
}

static void	select_err_mess(t_input *input, int type)
{
	char	*pre_message;
	char	*final_message;

	pre_message = "syntax error near unexpected token ";
	final_message = NULL;
	if (type == NEW_LINE)
		final_message = ft_strjoin(input, pre_message, "`newline'");
	else if (type == INFILE)
		final_message = ft_strjoin(input, pre_message, "`<'");
	else if (type == OUTFILE)
		final_message = ft_strjoin(input, pre_message, "`>'");
	else if (type == HEREDOC)
		final_message = ft_strjoin(input, pre_message, "`<<'");
	else if (type == APP_OUTFILE)
		final_message = ft_strjoin(input, pre_message, "`>>'");
	input->gb->type = GARBAGE;
	print_err(258, NULL, NULL, final_message);
}
