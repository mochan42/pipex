/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_processes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 17:11:35 by mochan            #+#    #+#             */
/*   Updated: 2022/08/18 18:10:43 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	child_process_cmd1(int infile, int pipe_w, int pipe_r, t_prgm *vars)
{
	dup2(infile, STDIN_FILENO);
	dup2(pipe_w, STDOUT_FILENO);
	close(pipe_r);
	close(pipe_w);
	execve(vars->cmd1_path, vars->cmd_options1, vars->envp);
}

void	child_process_cmd2(int outfile, int pipe_w, int pipe_r, t_prgm *vars)
{
	dup2(pipe_r, STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(pipe_w);
	close(pipe_r);
	execve(vars->cmd2_path, vars->cmd_options2, vars->envp);
}
