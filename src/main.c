/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 18:08:12 by mochan            #+#    #+#             */
/*   Updated: 2022/08/18 17:05:10 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	init_struct(t_prgm *vars)
{
	vars->file1 = 0;
	vars->file2 = 0;
	vars->path_in_envp = NULL;
	vars->env_paths = NULL;
	vars->cmd1 = NULL;
	vars->cmd2 = NULL;
	vars->path_file1 = NULL;
	vars->path_file2 = NULL;
	vars->path_file2_short = NULL;
	vars->cmd1_path = NULL;
	vars->cmd2_path = NULL;
	vars->cmd_options1 = NULL;
	vars->cmd_options2 = NULL;
	vars->b_path_file1_nok = 0;
	vars->b_path_file2_nok = 0;
	vars->b_cmd1_nok = 0;
	vars->b_cmd2_nok = 0;
	vars->b_opening_file1_nok = 0;
	vars->b_opening_file2_nok = 0;
	vars->b_accessing_file1_nok = 0;
	vars->b_accessing_file2_nok = 0;
}

void	error_check_and_preprocessing(t_prgm *vars)
{
	char	*str;

	error_number_of_arguments(vars);
	check_both_paths(vars);
	str = find_path_in_envp(*vars);
	split_path(vars, str);
	init_argv_2_3_into_struct(vars);
	init_cmd_into_struct(vars);
	split_cmd2(vars);
	check_both_cmds(vars);
}

int	main(int argc, char **argv, char **envp)
{
	t_prgm	pipx;
	int		fd[2];

	pipx.argc = argc;
	pipx.argv = argv;
	pipx.envp = envp;
	init_struct(&pipx);
	check_existence_permissions_both_files(&pipx);
	open_both_files(&pipx);
	error_check_and_preprocessing(&pipx);
	pipe_and_fork(&pipx, fd);
	return (0);
}
