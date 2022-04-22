/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 11:40:20 by agirardi          #+#    #+#             */
/*   Updated: 2022/04/22 17:53:34 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int	parse_arg(char *str);
static void	remove_from_env_tab(t_input *input, char *key_to_remove);
static int	env_tab_contains_key(const char *str, const char *key);

int	ft_unset(t_input *input, t_cmd_lst *cmd)
{
	char	*key;
	int		i;

	if (input->n_cmd > 1)
		return (0);
	i = 0;
	while (cmd->args[++i])
	{
		key = cmd->args[i];
		if (parse_arg(key) == SUCCESS
			&& find_existing_env_var(input, key) == YES)
			remove_from_env_tab(input, key);
	}
	return (0);
}

static int	parse_arg(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if ((!ft_isalnum(str[i]) && str[i] != '_') || ft_isdigit(str[0]))
		{
			print_err(1, "minishelled: unset", str, "not a valid identifier");
			return (FAILED);
		}
	}
	return (SUCCESS);
}

static void	remove_from_env_tab(t_input *input, char *key_to_remove)
{
	t_env	*new_env_tab;
	int		i;
	int		j;

	input->n_env --;
	new_env_tab = ft_malloc(input, sizeof(t_env), input->n_env);
	input->gb->type = ENV_STRUCT;
	i = -1;
	j = 0;
	while (++i < input->n_env + 1)
	{
		if (env_tab_contains_key(input->env_tab[i].key, key_to_remove) == NO)
		{
			new_env_tab[j].key = input->env_tab[i].key;
			new_env_tab[j].value = input->env_tab[i].value;
			new_env_tab[j].type = input->env_tab[i].type;
			j++;
		}
	}
	input->env_tab = new_env_tab;
}

static int	env_tab_contains_key(const char *str, const char *key)
{
	int	i;

	if (ft_strlen(str) != ft_strlen(key))
		return (0);
	i = -1;
	while (key[++i])
	{
		if (key[i] != str[i])
			return (NO);
	}
	return (YES);
}