/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 17:47:54 by mochan            #+#    #+#             */
/*   Updated: 2022/08/18 20:30:33 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	open_files(t_prgm *vars)
{
	vars->file1 = open("file1", O_RDONLY, 0777);
	vars->file2 = open("file2", O_WRONLY, 0777);
}

void	free_table(char **table)
{
	int	i;

	i = 0;
	if (!table)
		exit (1);
	while(table[i] != NULL)
	{
		free(table[i]);
		i++;
	}
	free(table);
}