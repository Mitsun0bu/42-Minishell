/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_name_in_redir_tab.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 13:52:08 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/12 18:09:16 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	copy_name_for_each_file(t_input *input, int i_c, int type, int i_f)
{
	int	c;
	int	t;
	int	f;

	c = i_c;
	t = type;
	f = i_f;
	if (t == 0)
		copy_infile(input->redir_tab[c][t][f], input->cmd_tab[c], f);
	if (t == 1)
		copy_outfile(input->redir_tab[c][t][f], input->cmd_tab[c], f);
	if (t == 2)
		copy_delimiter(input->redir_tab[c][t][f], input->cmd_tab[c], f);
	if (t == 3)
		copy_app_outfile(input->redir_tab[c][t][f], input->cmd_tab[c], f);
}

void	copy_infile(char *infile, char *cmd, int i_file)
{
	static int	cursor = -1;
	int			file_cursor;

	if (i_file == 0)
		cursor = -1;
	file_cursor = 0;
	while (cmd[++cursor])
	{
		if (cmd[cursor] == '<'
			&& cmd[cursor + 1] != '<' && cmd[cursor - 1] != '<')
		{
			skip_space(cmd, &cursor);
			while (cmd[cursor] && !ft_strchr(" <>", cmd[cursor]))
			{
				if (cmd[cursor] == '\'' || cmd[cursor] == '"')
					copy_in_quotes(infile, &file_cursor, cmd, &cursor);
				else
					copy_out_quotes(infile, &file_cursor, cmd, &cursor);
			}
			return ;
		}
	}
}

void	copy_outfile(char *outfile, char *cmd, int i_file)
{
	static int	cursor = -1;
	int			file_cursor;

	if (i_file == 0)
		cursor = -1;
	file_cursor = 0;
	while (cmd[++cursor])
	{
		if (cmd[cursor] == '>'
			&& cmd[cursor + 1] != '>' && cmd[cursor - 1] != '>')
		{
			skip_space(cmd, &cursor);
			while (cmd[cursor] && !ft_strchr(" <>", cmd[cursor]))
			{
				if (cmd[cursor] == '\'' || cmd[cursor] == '"')
					copy_in_quotes(outfile, &file_cursor, cmd, &cursor);
				else
					copy_out_quotes(outfile, &file_cursor, cmd, &cursor);
			}
			return ;
		}
	}
}

void	copy_delimiter(char *delimiter, char *cmd, int i_file)
{
	static int	cursor = -1;
	int			file_cursor;

	if (i_file == 0)
		cursor = -1;
	file_cursor = 0;
	while (cmd[++cursor])
	{
		if (cmd[cursor] == '<' && cmd[cursor + 1] == '<')
		{
			skip_space(cmd, &cursor);
			while (cmd[cursor] && !ft_strchr(" <>", cmd[cursor]))
			{
				if (cmd[cursor] == '\'' || cmd[cursor] == '"')
					copy_in_quotes(delimiter, &file_cursor, cmd, &cursor);
				else
					copy_out_quotes(delimiter, &file_cursor, cmd, &cursor);
			}
			return ;
		}
	}
}

void	copy_app_outfile(char *app_outfile, char *cmd, int i_file)
{
	static int	cursor = -1;
	int			file_cursor;

	if (i_file == 0)
		cursor = -1;
	file_cursor = 0;
	while (cmd[++cursor])
	{
		if (cmd[cursor] == '>' && cmd[cursor + 1] == '>')
		{
			skip_space(cmd, &cursor);
			while (cmd[cursor] && !ft_strchr(" <>", cmd[cursor]))
			{
				if (cmd[cursor] == '\'' || cmd[cursor] == '"')
					copy_in_quotes(app_outfile, &file_cursor, cmd, &cursor);
				else
					copy_out_quotes(app_outfile, &file_cursor, cmd, &cursor);
			}
			return ;
		}
	}
}
