/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 18:08:12 by mochan            #+#    #+#             */
/*   Updated: 2022/08/16 23:42:36 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char **argv, char **envp)
{
    // char *options[3] = {"ls", "-la", NULL};

    (void)argc;
    (void)argv;
    // execve("/bin/ls", options, envp);
	int i;
	i = 1;
	while (*envp)
	{
		ft_printf("envp %d	:	%s\n", i, *envp);
		envp++;
		i++;
	}
    return (0);
}
