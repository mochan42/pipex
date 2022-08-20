/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 17:47:54 by mochan            #+#    #+#             */
/*   Updated: 2022/08/20 17:41:27 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	open_file1(t_prgm *vars)
{
	vars->path_file1 = vars->argv[1];
	vars->file1 = open(vars->path_file1, O_RDONLY, 0777);
	if (vars->file1 == -1)
	{
		vars->b_opening_file1_nok = 1;
	}
	else
		vars->b_opening_file1_nok = 0;
}

void	open_file2(t_prgm *vars)
{
	vars->path_file2 = vars->argv[4];
	vars->file2 = open(vars->path_file2, O_WRONLY | O_CREAT, 0777);
	if (vars->file2 == -1)
	{
		vars->b_opening_file2_nok = 1;
	}
	else
		vars->b_opening_file2_nok = 0;
}

void	open_both_files(t_prgm *vars)
{
	open_file1(vars);
	open_file2(vars);
	if (vars->b_opening_file2_nok == 1 && vars->b_opening_file1_nok == 1)
	{
		ft_printf("Could not open file1: %s\n", vars->path_file1);
		ft_printf("Could not open file2: %s\n", vars->path_file2);
		close(vars->file1);
		close(vars->file2);
		exit (0);
	}
	if (vars->b_opening_file2_nok == 0 && vars->b_opening_file1_nok == 1)
	{
		ft_printf("Could not open file1: %s\n", vars->path_file1);
		close(vars->file1);
		exit (0);
	}
	if (vars->b_opening_file2_nok == 1 && vars->b_opening_file1_nok == 0)
	{
		ft_printf("Could not open file2: %s\n", vars->path_file2);
		close(vars->file2);
		exit (0);
	}
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
