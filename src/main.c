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

void	error_check_and_preprocessing(t_prgm *vars)
{
	char	*str;

	error_number_of_arguments(vars);
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

	open_files(&pipx);
	pipx.argc = argc;
	pipx.argv = argv;
	pipx.envp = envp;
	error_check_and_preprocessing(&pipx);
	pipe_and_fork(&pipx, fd);
	return (0);
}
