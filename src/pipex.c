/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 18:08:12 by mochan            #+#    #+#             */
/*   Updated: 2022/08/18 14:32:48 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"



int main(int argc, char **argv, char **envp)
{
    t_prgm	pipx;
	char *str;

	if (argc != 5)
	{
		ft_printf("Number of arguments is incorrect (need 4 arguments).\n");
		return (1);
	}
	pipx.argv = argv;
	pipx.envp = envp;
	init_path_into_struct(&pipx);
	init_cmd_into_struct(&pipx);
	str = find_path_in_envp(pipx);
	split_path(&pipx, str);
	split_cmd1(&pipx);
	split_cmd2(&pipx);
	get_cmd1_path(&pipx);
	// ft_printf("cmd1 with path is : %s\n", pipx.cmd1_path);
	get_cmd2_path(&pipx);
	// ft_printf("cmd2 with path is : %s\n", pipx.cmd2_path);
	// execve(pipx.cmd1_path, pipx.cmd_options1, pipx.envp);
	// execve(pipx.cmd2_path, pipx.cmd_options2, pipx.envp);
	
	int	fd[2];
	if (pipe(fd) == -1)
	{
		return 1;
	}
	
	int pid1 = fork();
	if (pid1 < 0)
	{
		return 2;
	}
	
	if (pid1 == 0)
	{
		// Child process for cmd1
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		execve(pipx.cmd1_path, pipx.cmd_options1, pipx.envp);

	}
	
	int pid2 = fork();
	if (pid2 < 0)
	{
		return 3;
	}
	
	if (pid2 == 0)
	{
		// Child process for cmd2
		dup2(fd[0], STDIN_FILENO);
		close(fd[1]);
		close(fd[0]);
		execve(pipx.cmd2_path, pipx.cmd_options2, pipx.envp);
	}
	
	close(fd[0]);
	close(fd[1]);
	
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}
