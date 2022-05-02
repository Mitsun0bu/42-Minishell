/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 15:10:44 by agirardi          #+#    #+#             */
/*   Updated: 2022/05/02 16:04:26 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	replace_existing_env_var(t_input *input, char *str);
static int	parse_env_var(t_input *input, char *env_var);
static int	parse_key(t_input *input, char	*str, int type);
static void	print_export(t_input *input);

int	ft_export(t_input *input, t_cmd_lst *cmd)
{
	int		env_var_type;
	int		i;

	if (input->n_cmd > 1 && cmd->n_args > 1)
		return (0);
	if (cmd->n_args == 1)
		print_export(input);
	i = 0;
	while (cmd->args[++i])
	{
		if (find_existing_env_var(input, cmd->args[i]) == YES)
			replace_existing_env_var(input, cmd->args[i]);
		else
		{
			env_var_type = parse_env_var(input, cmd->args[i]);
			if (env_var_type)
				add_to_env_tab(input, cmd->args[i], env_var_type);
		}
	}
	return (g_status);
}

static void	replace_existing_env_var(t_input *input, char *str)
{
	char	*key;
	char	*value;

	key = extract_key_from_str(input, str);
	value = extract_value_from_str(input, str);
	if (value || ft_strchr(str, '='))
		change_value(input, key, value);
}

static int	parse_env_var(t_input *input, char *env_var)
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

static int	parse_key(t_input *input, char	*str, int type)
{
	char	*key;
	int		i;

	i = -1;
	key = extract_key_from_str(input, str);
	while (key[++i])
	{
		if ((!ft_isalnum(key[i]) && key[i] != '_')
			|| ft_isdigit(key[0]) || key[0] == '=')
		{
			print_err(1, "minishelled: export", str, "not a valid identifier");
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

static void	print_export(t_input *input)
{
	int	check_oldpwd;
	int	i;

	check_oldpwd = 0;
	i = -1;
	while (++i < input->n_env)
	{
		if (ft_strcmp(input->env_tab[i].key, "_") == FAILED)
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
		if (ft_strcmp(input->env_tab[i].key, "OLDPWD") == SUCCESS)
			check_oldpwd = 1;
	}
	if (check_oldpwd == 0)
		printf("declare -x OLDPWD\n");
}
