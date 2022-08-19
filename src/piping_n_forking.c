/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piping_n_forking.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 12:24:31 by mochan            #+#    #+#             */
/*   Updated: 2022/08/19 12:41:05 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	pipe_and_fork(t_prgm *vars, int *fildes)
{
	int		pid1;
	int		pid2;

	if (pipe(fildes) == -1)
		return (2);
	pid1 = fork();
	if (pid1 < 0)
		return (3);
	if (pid1 == 0)
		child_process_cmd1(vars->file1, fildes, vars);
	pid2 = fork();
	if (pid2 < 0)
		return (4);
	if (pid2 == 0)
		child_process_cmd2(vars->file2, fildes, vars);
	else
		parent_process(*vars, fildes, pid1, pid2);
	return (0);
}
