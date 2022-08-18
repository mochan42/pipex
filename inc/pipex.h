/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 18:08:17 by mochan            #+#    #+#             */
/*   Updated: 2022/08/18 13:59:13 by mochan           ###   ########.fr       */
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
# include <fcntl.h>
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
	char	*path_in_envp;
	char	**env_paths;
	char	*cmd1;
	char	*cmd2;
	char	*path_file1;
	char	*path_file2;
	char	*cmd1_path;
	char	*cmd2_path;
	char	**cmd_options1;
	char	**cmd_options2;
}				t_prgm;


/* ########################################################################## */
/* CONSTANTS */


/* ########################################################################## */
/* FUNCTIONS */

/* get_paths.c */
char	*find_path_in_envp(t_prgm vars);
char	*get_cmd1_path(t_prgm *vars);
char	*get_cmd2_path(t_prgm *vars);
void	init_path_into_struct(t_prgm *vars);
void	split_path(t_prgm *vars, char *s);

/* get_commands.c */
void	init_cmd_into_struct(t_prgm *vars);
void	split_cmd1(t_prgm *vars);
void	split_cmd2(t_prgm *vars);

#endif