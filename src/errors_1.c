/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 16:57:05 by mochan            #+#    #+#             */
/*   Updated: 2022/08/18 17:04:29 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	check_path_file1(t_prgm *vars)
{
	if (access(vars->path_file1, F_OK | X_OK) != 0)
		vars->b_path_file1_nok = 1;
	else
		vars->b_path_file1_nok = 0;
}

char	*extract_path_file2_wo_cmd(t_prgm *vars)
{
	int		char_before_cmd2;
	char	*path_file2_wo_cmd2;
	int		i;

	char_before_cmd2 = 0;
	if (ft_strchr(vars->path_file2, '/'))
	{
		while (vars->path_file2[char_before_cmd2] != '\0')
			char_before_cmd2++;
		while (vars->path_file2[char_before_cmd2] != '/')
			char_before_cmd2--;
		char_before_cmd2++;
		path_file2_wo_cmd2 = malloc(sizeof(char) * (char_before_cmd2 + 1));
		if (!path_file2_wo_cmd2)
		{
			ft_printf("Failed to malloc: path_file2_wo_cmd2.\n");
			exit (0);
		}
		path_file2_wo_cmd2[char_before_cmd2] = '\0';
		i = 0;
		while (i < char_before_cmd2)
		{
			path_file2_wo_cmd2[i] = vars->path_file2[i];
			i++;
		}
		vars->path_file2_without_cmd2 = path_file2_wo_cmd2;
		free(path_file2_wo_cmd2);
		return (vars->path_file2_without_cmd2);
	}
	else
		return (NULL);
}

void	check_path_file2(t_prgm *vars)
{
	char	*str;

	if (ft_strchr(vars->path_file2, '/'))
	{
		str = extract_path_file2_wo_cmd(vars);
		if (access(vars->path_file2_without_cmd2, F_OK | X_OK) != 0)
			vars->b_path_file2_nok = 1;
		else
			vars->b_path_file2_nok = 0;
	}
}

void	check_both_paths(t_prgm *vars)
{
	check_path_file1(vars);
	check_path_file2(vars);
	if (vars->b_path_file2_nok == 1 && vars->b_path_file1_nok == 1)
	{
		ft_printf("No such file or directory: %s\n", vars->path_file1);
		ft_printf("No such file or directory: %s\n", vars->path_file2_without_cmd2);
		exit (1);
	}
	else if (vars->b_path_file2_nok == 0 && vars->b_path_file1_nok == 1)
	{
		ft_printf("No such file or directory: %s\n", vars->path_file1);
		exit (1);
	}
	else if (vars->b_path_file2_nok == 1 && vars->b_path_file1_nok == 0)
	{
		ft_printf("No such file or directory: %s\n", vars->path_file2_without_cmd2);
		exit (1);
	}
}
