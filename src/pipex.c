/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 18:08:12 by mochan            #+#    #+#             */
/*   Updated: 2022/08/17 21:00:18 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


char *find_path_in_envp(t_prgm vars)
{
	char	*path_name;
	char	*path_env;
	char	*test;
	int		len_path_env;

	path_name = "PATH=";
	path_env = NULL;
	test = NULL;
	len_path_env = 0;
	while (*(vars.envp))
	{
		test = ft_strnstr(*(vars.envp), path_name, 5);
		if (test)
		{
			path_env = *(vars.envp);
			len_path_env = ft_strlen(path_env);
			break ;
		}
		else
			(*(vars.envp))++;
	}
	path_env = ft_substr(path_env, 5, len_path_env);
	// ft_printf("%s\n", path_env);
	// ft_printf("\n");
	return (path_env);
}


void	split_path(t_prgm *vars, char *s)
{
	char	**tab;
	char	*temp;
	
	tab = ft_split(s, ':');
	int i;
	i = 0;
	while(tab[i] != NULL)
	{
		temp = tab[i];
		temp = ft_strjoin(temp, "/");
		tab[i] = temp; 
		i++;
	}
	vars->env_paths = tab;
}

void	init_argv_into_struc(t_prgm *vars)
{
	vars->path_file1 = vars->argv[1];
	vars->cmd1 = vars->argv[2];
	vars->cmd2 = vars->argv[3];
	vars->path_file2 = vars->argv[4];
	// ft_printf("path_file1 is : %s\n", vars->path_file1);
	// ft_printf("cmd1 is : %s\n", vars->cmd1);
	// ft_printf("cmd2 is : %s\n", vars->cmd2);
	// ft_printf("path_file2 is : %s\n", vars->path_file2);
}

char	*get_cmd1_path(t_prgm *vars)
{
	int i;

	i = 0;
	vars->cmd1_path = NULL;
	while(vars->env_paths[i] != NULL)
	{
		vars->cmd1_path = ft_strjoin(vars->env_paths[i], vars->cmd1);
		if (access(vars->cmd1_path, F_OK | X_OK) == 0)
		{
			ft_printf("cmd1 with path is : %s\n", vars->cmd1_path);
			return (vars->cmd1_path);
			break;
		}
		free(vars->cmd1_path);
		i++;
	}
	ft_printf("cmd1 not found.\n");
	return (NULL);
}

char	*get_cmd2_path(t_prgm *vars)
{
	int i;

	i = 0;
	vars->cmd2_path = NULL;
	while(vars->env_paths[i] != NULL)
	{
		vars->cmd2_path = ft_strjoin(vars->env_paths[i], vars->cmd2);
		if (access(vars->cmd2_path, F_OK | X_OK) == 0)
		{
			ft_printf("cmd2 with path is : %s\n", vars->cmd2_path);
			return (vars->cmd2_path);
			break;
		}
		free(vars->cmd2_path);
		i++;
	}
	ft_printf("cmd2 not found.\n");
	return (NULL);
}

int main(int argc, char **argv, char **envp)
{
    t_prgm	pipx;
	char *str;
	char *options[3] = {"ls", "-la", NULL};
	// int i;

	if (argc != 5)
	{
		ft_printf("Number of arguments is incorrect (need 4 arguments).\n");
		return (1);
	}
	pipx.argv = argv;
	pipx.envp = envp;
	init_argv_into_struc(&pipx);
	str = find_path_in_envp(pipx);
	split_path(&pipx, str);
	// i = 0;
	// while(pipx.env_paths[i] != NULL)
	// {
	// 	ft_printf("%s\n", pipx.env_paths[i]);
	// 	i++;
	// }
	get_cmd1_path(&pipx);
	get_cmd2_path(&pipx);
	execve(get_cmd1_path(&pipx), options, envp);
	return (0);
}
