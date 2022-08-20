/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 17:47:54 by mochan            #+#    #+#             */
/*   Updated: 2022/08/20 19:57:10 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	free_table(char **table)
{
	int	i;

	i = 0;
	if (!table)
		exit (1);
	while (table[i] != NULL)
	{
		free(table[i]);
		i++;
	}
	free(table);
}

void	free_stuff(t_prgm *vars)
{
	free_table(vars->cmd_options1);
	free_table(vars->cmd_options2);
	free(vars->cmd1_path);
	free(vars->cmd2_path);
	free_table(vars->env_paths);
}

void	copy_path_to_struct(t_prgm *vars, int n)
{
	char	*path_file2_wo_cmd2;
	int		i;

	path_file2_wo_cmd2 = malloc(sizeof(char) * (n + 1));
	exit_if_failed_malloc_path_file2_short(path_file2_wo_cmd2);
	path_file2_wo_cmd2[n] = '\0';
	i = 0;
	while (i < n)
	{
		path_file2_wo_cmd2[i] = vars->path_file2[i];
		i++;
	}
	vars->path_file2_short = path_file2_wo_cmd2;
	free(path_file2_wo_cmd2);
}
