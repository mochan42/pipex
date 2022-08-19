/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 17:47:54 by mochan            #+#    #+#             */
/*   Updated: 2022/08/19 15:09:04 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	open_files(t_prgm *vars)
{
	vars->path_file1 = vars->argv[1];
	vars->path_file2 = vars->argv[4];
	vars->file1 = open(vars->path_file1, O_RDONLY, 0777);
	vars->file2 = open(vars->path_file2, O_WRONLY | O_CREAT, 0777);
}

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
