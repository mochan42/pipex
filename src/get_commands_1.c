/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_commands_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 11:31:21 by mochan            #+#    #+#             */
/*   Updated: 2022/08/21 12:41:44 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_cmd_into_struct(t_prgm *vars)
{
	vars->cmd1 = vars->argv[2];
	vars->cmd2 = vars->argv[3];
	if (ft_strchr(vars->cmd1, '/'))
	{
		if (access(vars->cmd1, F_OK | X_OK) == 0)
		{
			vars->cmd1_path = vars->cmd1;
			split_cmd1_method2(vars);
			vars->b_cmd1_nok = 0;
		}
		vars->b_cmd1_nok = 1;
	}
	else
		split_cmd1(vars);
}

void	split_cmd1_method2(t_prgm *vars)
{
	char	**temp;
	char	*cmd_path_full;

	temp = ft_split(vars->cmd1_path, ' ');
	cmd_path_full = temp[0];
	temp[0] = copy_cmd_name_only(cmd_path_full);
	vars->cmd_options1 = temp;
	free(cmd_path_full);
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
}

char	*get_cmd1_path(t_prgm *vars)
{
	int	i;

	i = 0;
	vars->cmd1_path = NULL;
	while (vars->env_paths[i] != NULL)
	{
		vars->cmd1_path = ft_strjoin(vars->env_paths[i], vars->cmd_options1[0]);
		if (access(vars->cmd1_path, F_OK | X_OK) == 0)
		{
			vars->b_cmd1_nok = 0;
			return (vars->cmd1_path);
			break ;
		}
		free(vars->cmd1_path);
		i++;
	}
	vars->b_cmd1_nok = 1;
	return (NULL);
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
