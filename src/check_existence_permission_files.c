/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_existence_permission_files.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 17:44:45 by mochan            #+#    #+#             */
/*   Updated: 2022/08/20 18:35:51 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	check_existence_file1(t_prgm *vars)
{
	return (access(vars->argv[1], F_OK));
}

int	check_r_right_file1(t_prgm *vars)
{
	return (access(vars->argv[1], R_OK));
}

int	check_w_right_file2(t_prgm *vars)
{
	return (access(vars->argv[4], W_OK));
}

void	check_existence_permissions_both_files(t_prgm *vars)
{
	if (check_existence_file1(vars) == -1)
	{
		ft_printf("no such file or directory: %s\n", vars->argv[1]);
		exit (0);
	}
	if (check_r_right_file1(vars) == -1 && check_w_right_file2(vars) == -1)
	{
		ft_printf("permission denied: %s\n", vars->argv[1]);
		ft_printf("permission denied: %s\n", vars->argv[4]);
		exit (0);
	}
	if (check_r_right_file1(vars) == -1)
	{
		ft_printf("permission denied: %s\n", vars->argv[1]);
		exit (0);
	}
	if (check_w_right_file2(vars) == -1)
	{
		ft_printf("permission denied: %s\n", vars->argv[4]);
		exit (0);
	}
}
