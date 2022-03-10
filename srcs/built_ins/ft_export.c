/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 15:10:44 by agirardi          #+#    #+#             */
/*   Updated: 2022/03/10 11:10:38 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	ft_export(t_input *input, t_cmd_lst *lst_node)
{
	char	*var;
	int		res;
	int		i;

	if (input->n_cmd > 1 && lst_node->n_args > 1)
		return (0);
	i = 0;
	while (input->cmd_exec_tab[lst_node->cmd_index][++i])
	{
		var = del_quotes(input->cmd_exec_tab[lst_node->cmd_index][i]);
		res = parse_var(var, input);
		if (res == 1)
			add_to_env(input, var, ENV);
		else if (res == 2)
			add_to_env(input, var, EXPORT_NULL);
		else if (res == 3)
			add_to_env(input, var, EXPORT_EMPTY);
		ft_free(var);
	}
	if (i == 1)
		print_export(input);
	return (0);
}

int	parse_var(char *str, t_input *input)
{
	int	equal;
	int	i;

	equal = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] == '=')
			equal = 1;
	}
	if (equal == 0)
	{
		if (check_dubble(str, input))
			return (0);
		return (parse_key(str, input, 2));
	}
	return (parse_key(str, input, 1));
}

int	parse_key(char	*str, t_input *input, int type)
{
	char	*key;
	int		i;

	i = -1;
	key = find_key(str);
	while (key[++i])
	{
		if ((!ft_isalnum(key[i]) && key[i] != '_') || ft_isdigit(key[0]))
		{
			ft_free(key);
			return (0);
		}
	}
	if (type == 2)
		return (2);
	if (check_dubble(key, input))
	{
		change_value(input, key, find_value(str));
		ft_free(key);
		return (0);
	}
	ft_free(key);
	if (!str[i + 1])
		return (3);
	return (1);
}

char	*del_quotes(char	*str)
{
	char	*var;
	int		count;
	int		i;
	int		j;

	count = 0;
	i = -1;
	while (str[++i])
		if (!ft_strchr("\'\"", str[i]))
			count++;
	var = ft_calloc(count + 1, sizeof(char));
	i = 0;
	j = 0;
	while (j < count && str[i])
	{
		if (!ft_strchr("\'\"", str[i]))
			var[j++] = str[i];
		i++;
	}
	return (var);
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
			if (input->env_tab[i].value && input->env_tab[i].type != EXPORT_EMPTY)
				printf("declare -x %s=\"%s\"\n", input->env_tab[i].key, input->env_tab[i].value);
			else if (input->env_tab[i].type == EXPORT_EMPTY)
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
