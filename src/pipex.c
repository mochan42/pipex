/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 18:08:12 by mochan            #+#    #+#             */
/*   Updated: 2022/08/17 12:28:36 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char **argv, char **envp)
{
    t_prgm	pipx;
	
	(void)argc;
    (void)argv;
	char	*path_name;
	char	*path_env;
	char	*test;
	pipx.envp = envp;

	path_name = "PATH=";
	path_env = NULL;
	test = NULL;
	while (*(pipx.envp))
	{
		test = ft_strnstr(*(pipx.envp), path_name, 5);
		if (test)
		{
			path_env = *(pipx.envp);
			break ;
		}
		else
			(*(pipx.envp))++;
	}
	ft_printf("%s\n", path_env);
	return (0);
}
