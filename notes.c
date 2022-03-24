/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   notes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 16:27:19 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/24 12:19:41 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "incs/main.h"
# include "/libft/libft.h"

1) Passer input dans tous les safe_malloc

==================== FROM MAIN --> SHELL_INIT ====================

NOEUD 1 :	input->garbage = ft_malloc(input, sizeof(t_garbage_lst), 1);
			input->garbage->type = COLLECTOR_LST;

NOEUD 2 :	init_env(input, envp);
				input->env_tab = ft_malloc(input, sizeof(t_env), i);
				input->garbage->type = ENV_STRUCT;

NOEUD 3 :	init_env(input, envp);
				input->env_tab[j].key = find_key(input, envp[i]);
					key = ft_substr(input, str, 0, i);
						ft_substr = ft_malloc(input, sizeof(char), (ft_strlen(s) + 1));
						ou
						ft_substr = ft_malloc(input, sizeof(char), (len + 1));
					input->garbage->type = ENV_STRUCT;

NOEUD 4 :	init_env(input, envp);
				input->env_tab[j].value = find_value(input, envp[i]);
					value = ft_substr(input, str, key_count + 1, i);
						ft_substr = ft_malloc(input, sizeof(char), (ft_strlen(s) + 1));
						ou
						ft_substr = ft_malloc(input, sizeof(char), (len + 1));
					input->garbage->type = ENV_STRUCT;

NOEUD 5 :	init_shlvl(input);
				value = ft_itoa(input, input->start_shlvl);
					nbr_str = ft_malloc(input, sizeof(char), i + 1);
				change_value(input, "SHLVL", value);
					input->env_tab[i].value = value;
				input->garbage->type = ENV_STRUCT;

NOEUD 6 :	init_history(input);
				path = get_history_path(input);
					path = ft_strjoin(input, get_value("HOME", input), "/.minishelled_history");
						joined = ft_malloc(input, sizeof(char), len + 1);
					input->garbage->type = GARBAGE;

NOEUD 7 :	init_history(input);
				cmd_line_history = ft_get_next_line(input, input->fd_history);
					line = ft_malloc(input, sizeof(char), 1);
					input->garbage->type = GARBAGE;
					line = ft_get_line(input, line, buff, fd);
						line = ft_strjoin_gnl(input, line, buff);
							joined = ft_malloc(input, sizeof(char), ft_strlen(line) + buff_size + 1);
					input->garbage->type = GARBAGE;
			!!!!! Voir quoi faire en cas de read_ret = -1 dans ft_get_line !!!

==================== FROM MAIN --> CMD_LINE_MANAGER ====================

NOEUD 8 :	get_cmd_line(input);
				path = get_history_path(input);
					path = ft_strjoin(input, get_value("HOME", input), "/.minishelled_history");
						joined = ft_malloc(input, sizeof(char), len + 1);
					input->garbage->type = GARBAGE;

NOEUD 9 :	get_cmd_line(input);
				input->cmd_line = ft_strdup(buff);
					str = ft_malloc(input, sizeof(char), ft_strlen(s1) + 1);
				input->garbage->type = INPUT_STRUCT;
				!!!!! Voir quoi faire si input->fd_history < 0 !!!!!

NOEUD 10 :	env_converter(input, input->cmd_line);
				size += count_env(str, &i, 0, input);
					key = ft_calloc(input, sizeof(char), key_len + 1);
					input->garbage->type = GARBAGE;

NOEUD 11 :	env_converter(input, input->cmd_line);
			input->processed_line = ft_calloc(input, sizeof(char), size + 1);
			input->garbage->type = INPUT_STRUCT;

NOEUD 12 :	env_converter(input, input->cmd_line);
				fill_buffer(input, str);
					fill_env(input, str, &i, &j);
					key = ft_substr(input, str, start, *i - start);
						ft_substr = ft_malloc(input, sizeof(char), (ft_strlen(s) + 1));
						ou
						ft_substr = ft_malloc(input, sizeof(char), (len + 1));
					input->garbage->type = GARBAGE;

NOEUD 13 :	input->cmd_line = ft_strdup(input, input->processed_line);
				str = ft_malloc(input, sizeof(char), ft_strlen(s1) + 1);
			input->garbage->type = INPUT_STRUCT;

==================== FROM MAIN --> CMD_LINE_SEPARATOR ====================

NOEUD 13 :	single_cmd(input);
			input->cmd_tab = ft_malloc (input, sizeof(char *), 2);
			input->garbage->type = INPUT_STRUCT;

NOEUD 14 :	single_cmd(input);
				input->cmd_tab[0] = ft_strtrim(input, input->cmd_line, " \t\n\v\f\r");
					trimmed = ft_malloc (input, sizeof(char), end - start + 1);
			input->garbage->type = INPUT_STRUCT;

NOEUD 15 :	split_multi_cmd(input);
				fill_last_pipe(input);
					filled_cmd = ft_strjoin(input, input->cmd_line, line);
						joined = ft_malloc(input, sizeof(char), len + 1);
					input->garbage->type = GARBAGE;

NOEUD 16 :	split_multi_cmd(input);
				fill_last_pipe(input);
					env_converter (filled_cmd, input);
					input->processed_line = ft_calloc(input, sizeof(char), size + 1);
					input->garbage->type = INPUT_STRUCT;

NOEUD 17 :	split_multi_cmd(input);
				fill_last_pipe(input);
					env_converter(input, input->cmd_line);
						fill_buffer(input, str);
							fill_env(input, str, &i, &j);
							key = ft_substr(input, str, start, *i - start);
								ft_substr = ft_malloc(input, sizeof(char), (ft_strlen(s) + 1));
								ou
								ft_substr = ft_malloc(input, sizeof(char), (len + 1));
							input->garbage->type = GARBAGE;

NOEUD 18 :	split_multi_cmd(input);
				fill_last_pipe(input);
					input->cmd_line = ft_strdup(input, input->processed_line);
						str = ft_malloc(input, sizeof(char), ft_strlen(s1) + 1);
					input->garbage->type = INPUT_STRUCT;

NOEUD 19 :	split_multi_cmd(input);
				input->cmd_tab = ft_split(input, input->cmd_line, '|');
					table = ft_calloc(input, sizeof(char *), words + 1);
					ft_calloc_strs(input, s, c, table);
						table[i_table] = ft_calloc(input, sizeof(char), j_table + 1);
						input->garbage->type = INPUT_STRUCT;
				input->garbage->type = INPUT_STRUCT;

NOEUD 20 :	split_multi_cmd(input);
				input->cmd_tab[i] = ft_strtrim(input, input->cmd_tab[i], " \t\n\v\f\r");
					trimmed = ft_malloc (input, sizeof(char), end - start + 1);
				input->garbage->type = INPUT_STRUCT;

!!!!! VOIR SI ON A TOUJOURS BESOIN DE FREE ALL DANS CMD_SEPARATOR !!!!!

==================== FROM MAIN --> REDIR_COLLECTOR ====================

NOEUD 21 :	get_last_redir_type_tab(input);
				input->last_input_type_tab = ft_calloc(input, sizeof(int), input->n_cmd);
				input->garbage->type = INPUT_STRUCT;

NOEUD 22 :	get_last_redir_type_tab(input);
				input->last_output_type_tab = ft_calloc(input, sizeof(int), input->n_cmd);
				input->garbage->type = INPUT_STRUCT;

NOEUD 23 :	malloc_cmd_dimension(input);
				input->redir_tab = ft_malloc(input, sizeof(char ***), input->n_cmd + 1);
				input->garbage->type = INPUT_STRUCT;

NOEUD 24 :	malloc_types_dimension_for_each_cmd(input);
				input->redir_tab[i_cmd] = ft_malloc(input, sizeof(char **), 5);
				input->garbage->type = INPUT_STRUCT;

NOEUD 25 :	malloc_n_file_dimension_for_each_type(input, i_cmd, type);
				input->redir_tab[i_cmd][type] = ft_malloc(input, sizeof(char *), 1);
				input->garbage->type = INPUT_STRUCT;

NOEUD 26 :	malloc_name_for_each_file(input, i_cmd, type, i_file);
				input->redir_tab[i_cmd][type][i_file] = ft_malloc(input, sizeof(char), len);
				input->garbage->type = INPUT_STRUCT;

==================== FROM MAIN --> PARSER ====================

!!!!!!!!!! VOIR COMMENT GERER LE RETURN SI CLEAN_CMD FAIL !!!!!!!!!!!

NOEUD 27 :	clean_cmd(input)
				input->cmd_exec_tab = ft_calloc(input, sizeof(char **), input->n_cmd + 1);
				input->garbage->type = INPUT_STRUCT;

NOEUD 28 :	clean_cmd(input)
				input->cmd_exec_tab[i] = ft_calloc(input, sizeof(char *), len);
				input->garbage->type = INPUT_STRUCT;

NOEUD 29 :	clean_cmd(input)
				create_arg_tab(input, i)
					input->cmd_exec_tab[i][j] = ft_calloc(input, sizeof(char), len);
					input->garbage->type = INPUT_STRUCT;

==================== FROM MAIN --> CMD_LST_INIT ====================

NOEUD 30 :	cmd_lst_init(&input, &cmd);
				add_cmd_back(cmd, create_new_cmd(input, &i));
					create_new_cmd(input, &i);
						new_cmd = ft_malloc(input, sizeof(t_cmd_lst), 1);
						input->garbage->type = CMD_LST;

NOEUD 31 :	cmd_lst_init(&input, &cmd);
				add_cmd_back(cmd, create_new_cmd(input, &i));
					create_new_cmd(input, &i)
						new_cmd->name = ft_strdup(input, input->cmd_exec_tab[*i][0]);
						input->garbage->type = CMD_LST;

NOEUD 32 :	cmd_lst_init(&input, &cmd);
				add_cmd_back(cmd, create_new_cmd(input, &i));
					create_new_cmd(input, &i)
						cmd_args_manager(input, i, new_cmd);
								new_cmd->args = ft_malloc(input, sizeof(char *), i_arg + 1);
								input->garbage->type = CMD_LST;

NOEUD 33 :	cmd_lst_init(&input, &cmd);
				add_cmd_back(cmd, create_new_cmd(input, &i));
					create_new_cmd(input, &i)
						cmd_args_manager(input, i, new_cmd);
								new_cmd->args = ft_malloc(input, sizeof(char *), i_arg + 1);
								input->garbage->type = CMD_LST;

NOEUD 34 :	cmd_lst_init(&input, &cmd);
				add_cmd_back(cmd, create_new_cmd(input, &i));
					create_new_cmd(input, &i)
						cmd_args_manager(input, i, new_cmd);
								new_cmd->args[i_arg] = ft_strdup(input, input->cmd_exec_tab[*i][i_arg]);
								input->garbage->type = CMD_LST;

NOEUD 35 :	cmd_lst_init(&input, &cmd);
				add_cmd_back(cmd, create_new_cmd(input, &i));
					create_new_cmd(input, &i)
						cmd_input_redir_manager(input, i, new_cmd);
							new_cmd->input_redir = ft_malloc(input, sizeof(char *), i_r + 1);
							input->garbage->type = CMD_LST;

NOEUD 36 :	cmd_lst_init(&input, &cmd);
				add_cmd_back(cmd, create_new_cmd(input, &i));
					create_new_cmd(input, &i)
						cmd_input_redir_manager(input, i, new_cmd);
							new_cmd->input_redir[i_r] = ft_strdup(input, input->redir_tab[*i][0][i_r]);
							input->garbage->type = CMD_LST;

NOEUD 37 :	cmd_lst_init(&input, &cmd);
				add_cmd_back(cmd, create_new_cmd(input, &i));
					create_new_cmd(input, &i)
						cmd_output_redir_manager(input, i, new_cmd);
							new_cmd->output_redir = ft_malloc(input, sizeof(char *), i_r + 1);
							input->garbage->type = CMD_LST;

NOEUD 38 :	cmd_lst_init(&input, &cmd);
				add_cmd_back(cmd, create_new_cmd(input, &i));
					create_new_cmd(input, &i)
						cmd_output_redir_manager(input, i, new_cmd);
							new_cmd->output_redir[i_r] = ft_strdup(input->redir_tab[*i][1][i_r]);
							input->garbage->type = CMD_LST;

NOEUD 39 :	cmd_lst_init(&input, &cmd);
				add_cmd_back(cmd, create_new_cmd(input, &i));
					create_new_cmd(input, &i)
						cmd_heredoc_manager(input, i, new_cmd);
							new_cmd->del = ft_malloc(input, sizeof(char *), i_r + 1);
							input->garbage->type = CMD_LST;

NOEUD 40 :	cmd_lst_init(&input, &cmd);
				add_cmd_back(cmd, create_new_cmd(input, &i));
					create_new_cmd(input, &i)
						cmd_heredoc_manager(input, i, new_cmd);
							new_cmd->del[i_r] = ft_strdup(input, input->redir_tab[*i][2][i_r]);
							input->garbage->type = CMD_LST;

NOEUD 41 :	cmd_lst_init(&input, &cmd);
				add_cmd_back(cmd, create_new_cmd(input, &i));
					create_new_cmd(input, &i)
						cmd_app_output_redir_manager(input, i, new_cmd);
							new_cmd->app_output_redir = ft_malloc(input, sizeof(char *), i_r + 1);
							input->garbage->type = CMD_LST;

NOEUD 42 :	cmd_lst_init(&input, &cmd);
				add_cmd_back(cmd, create_new_cmd(input, &i));
					create_new_cmd(input, &i)
						cmd_app_output_redir_manager(input, i, new_cmd);
							new_cmd->app_output_redir[i_r] = ft_strdup(input, input->redir_tab[*i][3][i_r]);
							input->garbage->type = CMD_LST;

==================== FROM MAIN --> EXECUTER ====================

NOEUD 43 :	path_manager(envp, input, cmd);
				get_paths_tab(envp, input);
					paths_line = ft_substr(input, *envp, 5, ft_strlen(*envp));
					input->garbage->type = GARBAGE;

NOEUD 44 :	path_manager(envp, input, cmd);
				get_paths_tab(envp, input);
						input->paths_tab = ft_split(input, paths_line, ':');
						input->garbage->type = GARBAGE;

NOEUD 45 :	path_manager(envp, input, cmd);
				get_paths_tab(envp, input);
						input->paths_tab[i] = ft_strjoin(input, input->paths_tab[i], "/");
						input->garbage->type = CMD_LST;

NOEUD 46 :	path_manager(envp, input, cmd);
				assign_path(input, *cmd, input->cmd_exec_tab[(*cmd)->index][0]);
						path = ft_strjoin(input, input->paths_tab[i], cmd->name);
						input->garbage->type = GARBAGE;

!!!!!!!!!! VOIR QUELLE FONCTION APPLER POUR EXIT/RETURN PROPREMENT !!!!!!!!!!

NOEUD 47 :	path_manager(envp, input, cmd);
				(*cmd)->valid_path = ft_strdup(input, "export");
				ou
				(*cmd)->valid_path = ft_strdup(input, "unset");
				ou
				(*cmd)->valid_path = assign_path(input->cmd_exec_tab[(*cmd)->index][0], input, *cmd);
					path = ft_strdup(input, arg);
					ou
					path = ft_strjoin(input, input->paths_tab[i], cmd->name);
				input->garbage->type = CMD_LST;

NOEUD 48 :	open_files(input, cmd);
				open_infiles(input, *cmd);
					cmd->fd_input = ft_malloc(input, sizeof(int), cmd->n_input_redir);
					input->garbage->type = CMD_LST;

NOEUD 49 :	open_files(input, cmd);
				open_outfiles(input, *cmd);
					cmd->fd_output = ft_malloc(input, sizeof(int), cmd->n_output_redir);
					input->garbage->type = CMD_LST;

NOEUD 50 :	open_files(input, cmd);
				open_app_outfiles(input, *cmd);
					cmd->fd_app_output = ft_malloc(input, sizeof(int), cmd->n_app_output_redir);
					input->garbage->type = CMD_LST;

!!!!!!!!!! VOIR QUELLE FONCTION APPLER POUR EXIT/RETURN PROPREMENT EN CAS DE PROBLEME AVEC UN FD !!!!!!!!!!

NOEUD 51 :	handle_heredocs_pipes(input, cmd);
				(*cmd)->heredoc_str = read_cmd_heredocs(input, *cmd);
					line = read_heredoc_line(line);
						buffer = ft_strdup(input, new_line);
						input->garbage->type = GARBAGE;

NOEUD 52 :	handle_heredocs_pipes(input, cmd);
				(*cmd)->heredoc_str = read_cmd_heredocs(input, *cmd);
					line = read_heredoc_line(line);
						new_line = ft_strjoin(input, buffer, "\n");
						input->garbage->type = GARBAGE;

NOEUD 53 :	pipex(input, cmd);
				input->process = ft_malloc(input, sizeof(pid_t), input->n_cmd);

NOEUD 54 :	pipex(input, cmd);
				exec_first_cmd(input, *cmd);
					exec_program(input, cmd);


OU

NOEUD 55 :	pipex(input, cmd);
				exec_first_cmd(input, *cmd);
					execve(cmd->valid_path, cmd->args, convert_env_tab(input));
						convert_env_tab(input)
							env_list = ft_malloc(input, sizeof(char *), i_list + 1);
							input->garbage->type = GARBAGE;

NOEUD 56 :	pipex(input, cmd);
				exec_first_cmd(input, *cmd);
					execve(cmd->valid_path, cmd->args, convert_env_tab(input));
						convert_env_tab(input)
							env_str = ft_strjoin(input, input->env_tab[i].key, "=");
							input->garbage->type = GARBAGE;

NOEUD 57 :	pipex(input, cmd);
				exec_first_cmd(input, *cmd);
					execve(cmd->valid_path, cmd->args, convert_env_tab(input));
						convert_env_tab(input)
							env_str = ft_strjoin(input, env_str, input->env_tab[i].value);
							input->garbage->type = GARBAGE;

NOEUD 58 :	pipex(input, cmd);
				exec_first_cmd(input, *cmd);
					execve(cmd->valid_path, cmd->args, convert_env_tab(input));
						convert_env_tab(input)
							env_list[i] = ft_strdup(input, env_str);
							input->garbage->type = GARBAGE;



Fonctions de la libft réellement utilisées :
	ft_strlen
	ft_substr	(modifiée pour ft_malloc)
	ft_atoi
	ft_itoa		(modifiée pour ft_malloc)
	ft_strjoin	(modifiée pour ft_malloc)
	ft_strdup	(modifiée pour ft_malloc)
	ft_calloc	(modifiée pour ft_malloc)
	ft_strtrim	(modifiée pour ft_malloc)
	ft_split	(modifiée pour ft_malloc)


2) modifier error_exit

3) voir tous les cas de return / exit (meme dans la libft !)