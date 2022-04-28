/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_name_in_redir_tab.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 13:52:08 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/21 16:30:33 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	copy_filenames_in_redir_tab(t_input *input, int i_c, int type, int i_f)
{
	int	c;
	int	t;
	int	f;

	c = i_c;
	t = type;
	f = i_f;
	if (t == INFILE)
		copy_filename(input->redir_tab[c][t][f], input->cmd_tab[c], f, '<');
	if (t == OUTFILE)
		copy_filename(input->redir_tab[c][t][f], input->cmd_tab[c], f, '>');
	if (t == HEREDOC)
		copy_filename(input->redir_tab[c][t][f], input->cmd_tab[c], f, '<');
	if (t == APP_OUTFILE)
		copy_filename(input->redir_tab[c][t][f], input->cmd_tab[c], f, '>');
}