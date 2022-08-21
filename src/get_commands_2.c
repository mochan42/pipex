/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_commands_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 12:44:15 by mochan            #+#    #+#             */
/*   Updated: 2022/08/21 12:45:30 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	split_cmd2(t_prgm *vars)
{
	char	**tab;

	tab = ft_split(vars->cmd2, ' ');
	vars->cmd_options2 = tab;
}

char	*get_cmd2_path(t_prgm *vars)
{
	int	i;

	i = 0;
	vars->cmd2_path = NULL;
	while (vars->env_paths[i] != NULL)
	{
		vars->cmd2_path = ft_strjoin(vars->env_paths[i], vars->cmd_options2[0]);
		if (access(vars->cmd2_path, F_OK | X_OK) == 0)
		{
			vars->b_cmd2_nok = 0;
			return (vars->cmd2_path);
			break ;
		}
		free(vars->cmd2_path);
		i++;
	}
	vars->b_cmd2_nok = 1;
	return (NULL);
}
