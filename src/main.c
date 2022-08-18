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

void	path_and_cmd_preprocessing(t_prgm *vars)
{
	char	*str;

	init_path_into_struct(vars);
	init_cmd_into_struct(vars);
	str = find_path_in_envp(*vars);
	split_path(vars, str);
	split_cmd1(vars);
	split_cmd2(vars);
	get_cmd1_path(vars);
	get_cmd2_path(vars);
}

int	main(int argc, char **argv, char **envp)
{
	t_prgm	pipx;
	int		fd[2];
	int		pid1;
	int		pid2;

	open_files(&pipx);
	pipx.argc = argc;
	pipx.argv = argv;
	pipx.envp = envp;
	error_number_of_arguments(&pipx);
	path_and_cmd_preprocessing(&pipx);
	if (pipe(fd) == -1)
		return (2);
	pid1 = fork();
	if (pid1 < 0)
		return (3);
	if (pid1 == 0)
		child_process_cmd1(pipx.file1, fd[1], fd[0], &pipx);
	pid2 = fork();
	if (pid2 < 0)
		return (4);
	if (pid2 == 0)
		child_process_cmd2(pipx.file2, fd[1], fd[0], &pipx);
	else
	{
		free_table(pipx.cmd_options1);
		free_table(pipx.cmd_options2);
		free(pipx.cmd1_path);
		free(pipx.cmd2_path);
		free_table(pipx.env_paths);
		close(fd[0]);
		close(fd[1]);
		close(pipx.file1);
		close(pipx.file2);
		waitpid(pid1, NULL, 0);
		waitpid(pid2, NULL, 0);
	}
	return (0);
}
