/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 18:08:17 by mochan            #+#    #+#             */
/*   Updated: 2022/08/20 16:45:42 by mochan           ###   ########.fr       */
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
	char	*path_file2_without_cmd2;
	char	*cmd1_path;
	char	*cmd2_path;
	char	**cmd_options1;
	char	**cmd_options2;
	int		b_path_file1_nok;
	int		b_path_file2_nok;
	int		b_cmd1_nok;
	int		b_cmd2_nok;
	int		b_permission_file1_nok;
	int		b_permission_file2_nok;
}				t_prgm;

/* ########################################################################## */
/* CONSTANTS */

/* ########################################################################## */
/* FUNCTIONS */

/* errors_1.c */
void	check_path_file1(t_prgm *vars);
char	*extract_path_file2_wo_cmd(t_prgm *vars);
void	check_path_file2(t_prgm *vars);
void	check_both_paths(t_prgm *vars);

/* errors_2.c */
void	error_number_of_arguments(t_prgm *vars);
void	check_both_cmds(t_prgm *vars);

/* child_processes.c */
void	child_process_cmd1(int infile, int *fildes, t_prgm *vars);
void	child_process_cmd2(int outfile, int *fildes, t_prgm *vars);

/* piping_n_forking.c */
int		error_msg_failed_pipe(int n);
int		error_msg_fork_child1_failed(int n);
int		error_msg_fork_child2_failed(int n);
int		pipe_and_fork(t_prgm *vars, int *fildes);

/* get_paths.c */
char	*find_path_in_envp(t_prgm vars);
void	split_path(t_prgm *vars, char *s);

/* get_commands_1.c */
void	init_cmd_into_struct(t_prgm *vars);
char	*get_cmd1_path(t_prgm *vars);
char	*get_cmd2_path(t_prgm *vars);
void	split_cmd1(t_prgm *vars);
void	split_cmd2(t_prgm *vars);

/* parent_process.c */
int		parent_process(t_prgm vars, int *fildes, int chi1, int chi2);

/* utils.c */
void	open_file1(t_prgm *vars);
void	open_file2(t_prgm *vars);
void	open_both_files(t_prgm *vars);
void	free_table(char **table);
void	free_stuff(t_prgm *vars);

#endif