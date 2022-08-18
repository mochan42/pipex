/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 16:57:05 by mochan            #+#    #+#             */
/*   Updated: 2022/08/18 17:04:29 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	error_number_of_arguments(t_prgm *vars)
{
	if (vars->argc > 5)
	{
		ft_printf("Too many arguments (pipex requires 4 arguments).\n");
		exit (1);
	}
	else if (vars->argc < 5)
	{
		ft_printf("Too few arguments (pipex requires 4 arguments).\n");
		exit (2);
	}
}
