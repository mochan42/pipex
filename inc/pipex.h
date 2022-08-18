/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 18:08:17 by mochan            #+#    #+#             */
/*   Updated: 2022/08/17 21:28:50 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

/* ########################################################################## */
/* INCLUDES */

# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <stdio.h>
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include "../get_next_line/get_next_line.h"

/* ########################################################################## */
/* STRUCTURES */

typedef struct s_prgm
{
	int		argc;
	char	**argv;
	char	**envp;
	char	**env_paths;
	char	*cmd1;
	char	*cmd2;
	char	*path_file1;
	char	*path_file2;
	char	*cmd1_path;
	char	*cmd2_path;
}				t_prgm;

/* ########################################################################## */
/* CONSTANTS */


/* ########################################################################## */
/* FUNCTIONS */



#endif