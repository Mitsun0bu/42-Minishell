/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 15:10:44 by agirardi          #+#    #+#             */
/*   Updated: 2022/04/19 18:53:02 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	ft_export(t_input *input, t_cmd_lst *cmd)
{
	int		env_var_type;
	int		i;

	if (input->n_cmd > 1 && cmd->n_args > 1)
		return (0);
	i = 0;
	while (cmd->args[++i])
	{
		if (find_existing_env_var(input, cmd->args[i]) == YES)
			replace_existing_env_var(input, cmd->args[i]);
		else
		{
			env_var_type = parse_env_var(input, cmd->args[i]);
			if (env_var_type == ENV)
				add_to_env_tab(input, cmd->args[i], ENV);
			else if (env_var_type == ENV_NULL)
				add_to_env_tab(input, cmd->args[i], ENV_NULL);
			else if (env_var_type == ENV_EMPTY)
				add_to_env_tab(input, cmd->args[i], ENV_EMPTY);
		}
	}
	if (i == 1)
		print_export(input);
	return (0);
}

int	parse_env_var(t_input *input, char *env_var)
{
	int	equal_sign;
	int	i;

	equal_sign = NO;
	i = -1;
	while (env_var[++i])
		if (env_var[i] == '=')
			equal_sign = YES;
	if (equal_sign == NO)
	{
		if (find_existing_env_var(input, env_var) == YES)
			return (0);
		return (parse_key(input, env_var, ENV_NULL));
	}
	return (parse_key(input, env_var, ENV));
}

int	parse_key(t_input *input, char	*str, int type)
{
	char	*key;
	int		i;

	i = -1;
	key = extract_key_from_str(input, str);
	input->gb->type = GARBAGE;
	while (key[++i])
	{
		if ((!ft_isalnum(key[i]) && key[i] != '_') || ft_isdigit(key[0]))
		{
			print_err(1, "minishelled: export", key, "not a valid identifier");
			return (0);
		}
	}
	if (type == ENV_NULL)
		return (ENV_NULL);
	if (find_existing_env_var(input, key) == YES)
	{
		change_value(input, key, extract_value_from_str(input, str));
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
