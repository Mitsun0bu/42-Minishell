/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_filenames_in_redir_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 13:52:08 by llethuil          #+#    #+#             */
/*   Updated: 2022/05/16 10:22:33 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	cp_single_red(char *dest, char *cmd, int i_file, char c);
static void	cp_double_red(char *dest, char *cmd, int i_file, char c);

void	copy_filenames_in_redir_tab(t_input *input, int i_c, int type, int i_f)
{
	int	c;
	int	t;
	int	f;

	c = i_c;
	t = type;
	f = i_f;
	if (t == INFILE)
		cp_single_red(input->redir_tab[c][t][f], input->cmd_tab[c], f, '<');
	if (t == OUTFILE)
		cp_single_red(input->redir_tab[c][t][f], input->cmd_tab[c], f, '>');
	if (t == HEREDOC)
		cp_double_red(input->redir_tab[c][t][f], input->cmd_tab[c], f, '<');
	if (t == APP_OUTFILE)
		cp_double_red(input->redir_tab[c][t][f], input->cmd_tab[c], f, '>');
}

static void	cp_single_red(char *dest, char *cmd, int i_file, char c)
{
	static int	i = 0;
	int			i_dest;

	if (i_file == 0)
		i = -1;
	i_dest = 0;
	while (cmd[++i])
	{
		if (cmd[i] == '\'' || cmd[i] == '"')
			skip_quotes(cmd, &i);
		if ((i == 0 && cmd[i] == c && cmd[i + 1] != c)
			|| (cmd[i] == c && cmd[i + 1] != c && cmd[i - 1] != c))
		{
			i ++;
			return (get_name(dest, &i_dest, cmd, &i));
		}
		else if (cmd[i] == c && cmd[i + 1] == c)
		{
			i += 2;
			skip_other_redir(cmd, &i);
		}
	}
}

static void	cp_double_red(char *dest, char *cmd, int i_file, char c)
{
	static int	i = 0;
	int			i_dest;

	if (i_file == 0)
		i = -1;
	i_dest = 0;
	while (cmd[++i])
	{
		if (cmd[i] == '\'' || cmd[i] == '"')
			skip_quotes(cmd, &i);
		if (cmd[i] == c && cmd[i + 1] == c)
		{
			i += 2;
			return (get_name(dest, &i_dest, cmd, &i));
		}
		else if ((i == 0 && cmd[i] == c && cmd[i + 1] != c)
			|| (cmd[i] == c && cmd[i + 1] != c && cmd[i - 1] != c))
		{
			i ++;
			skip_other_redir(cmd, &i);
		}
	}
}
