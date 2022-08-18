/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 11:31:21 by mochan            #+#    #+#             */
/*   Updated: 2022/08/18 13:47:53 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_cmd_into_struct(t_prgm *vars)
{
	vars->cmd1 = vars->argv[2];
	vars->cmd2 = vars->argv[3];
	// ft_printf("cmd1 is : %s\n", vars->cmd1);
	// ft_printf("cmd2 is : %s\n", vars->cmd2);
}

void	split_cmd1(t_prgm *vars)
{
	char	**tab;

	tab = ft_split(vars->cmd1, ' ');
	vars->cmd_options1 = tab;
}

void	split_cmd2(t_prgm *vars)
{
	char	**tab;

	tab = ft_split(vars->cmd2, ' ');
	vars->cmd_options2 = tab;
	// int j;
	// j = 0;
	// while (vars->cmd_options2[j] != NULL)
	// {
	// 	ft_printf("vars->cmd_options2[%d] = %s\n", j, vars->cmd_options2[j]);
	// 	j++;
	// }
}