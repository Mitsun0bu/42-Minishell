/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 15:10:44 by agirardi          #+#    #+#             */
/*   Updated: 2022/04/14 13:45:23 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	ft_export(t_input *input, t_cmd_lst *cmd)
{
	char	*var;
	int		res;
	int		i;

	if (input->n_cmd > 1 && cmd->n_args > 1)
		return (0);
	i = 0;
	while (cmd->args[++i])
	{
		var = cmd->args[i];
		res = parse_var(input, var);
		if (res == ENV)
			add_to_env(input, var, ENV);
		else if (res == ENV_NULL)
			add_to_env(input, var, ENV_NULL);
		else if (res == ENV_EMPTY)
			add_to_env(input, var, ENV_EMPTY);
	}
	if (i == 1)
		print_export(input);
	return (0);
}

int	parse_var(t_input *input, char *str)
{
	int	equal_sign;
	int	i;

	equal_sign = NO;
	i = -1;
	while (str[++i])
		if (str[i] == '=')
			equal_sign = YES;
	if (equal_sign == NO)
	{
		if (find_value(input, str) == YES)
			return (0);
		return (parse_key(input, str, ENV_NULL));
	}
	return (parse_key(input, str, ENV));
}

int	parse_key(t_input *input, char	*str, int type)
{
	char	*key;
	int		i;

	i = -1;
	key = get_key_from_env_tab(input, str);
	input->gb->type = GARBAGE;
	while (key[++i])
	{
		if ((!ft_isalnum(key[i]) && key[i] != '_') || ft_isdigit(key[0]))
		{
			print_error("minishelled: export", key, "not a valid identifier");
			return (0);
		}
	}
	if (type == ENV_NULL)
		return (ENV_NULL);
	if (find_value(input, key) == YES)
	{
		change_value(input, key, get_value_from_env_tab(input, str));
		return (0);
	}
	if (!str[i + 1])
		return (ENV_EMPTY);
	return (ENV);
}

void	print_export(t_input *input)
{
	int	check_oldpwd;
	int	i;

	check_oldpwd = 0;
	i = -1;
	while (++i < input->n_env)
	{
		if (ft_strncmp(input->env_tab[i].key, "_",
				ft_strlen(input->env_tab[i].key)) != 0)
		{
			if (input->env_tab[i].value
				&& input->env_tab[i].type != ENV_EMPTY)
				printf("declare -x %s=\"%s\"\n",
					input->env_tab[i].key, input->env_tab[i].value);
			else if (input->env_tab[i].type == ENV_EMPTY)
				printf("declare -x %s=\"\"\n", input->env_tab[i].key);
			else
				printf("declare -x %s\n", input->env_tab[i].key);
		}
		if (ft_strncmp(input->env_tab[i].key, "OLDPWD", 6) == 0)
			check_oldpwd = 1;
	}
	if (check_oldpwd == 0)
		printf("declare -x OLDPWD\n");
}
