/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 18:08:17 by mochan            #+#    #+#             */
/*   Updated: 2022/08/18 18:32:13 by mochan           ###   ########.fr       */
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
	int		file1;
	int		file2;
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

/* error_arguments.c */
void	error_number_of_arguments(t_prgm *vars);

/* child_processes.c */
void	child_process_cmd1(int infile, int pipe_w, int pipe_r, t_prgm *vars);
void	child_process_cmd2(int outfile, int pipe_w, int pipe_r, t_prgm *vars);

/* utils.c */
void	open_files(t_prgm *vars);
void	free_table(char **table);

/* get_paths.c */
char	*find_path_in_envp(t_prgm vars);
void	init_path_into_struct(t_prgm *vars);
void	split_path(t_prgm *vars, char *s);

/* get_commands.c */
void	init_cmd_into_struct(t_prgm *vars);
char	*get_cmd1_path(t_prgm *vars);
char	*get_cmd2_path(t_prgm *vars);
void	split_cmd1(t_prgm *vars);
void	split_cmd2(t_prgm *vars);

#endif