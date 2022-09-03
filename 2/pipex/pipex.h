/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 01:06:05 by yje               #+#    #+#             */
/*   Updated: 2022/09/04 01:06:08 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/wait.h>

# define FALSE		0
# define TRUE		1
# define FAIL		0
# define SUCCESS	1
# define ERROR		2

typedef struct	s_cmd
{
	char	**cmd;
	char	*path;
	int		slash;
}				t_cmd;

typedef struct		s_env
{
	char			**envp;
	int				infile_fd;
	int				outfile_fd;
	int				pipe_fd[2];
	int				result;
	char			**path;
	pid_t			pid;
	struct s_cmd	*cmd;
}				t_env;

#endif