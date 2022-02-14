/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caeduard <caeduard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 13:41:23 by caeduard          #+#    #+#             */
/*   Updated: 2022/02/14 00:55:48 by caeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <malloc.h>
#include <fcntl.h>
#include "pipex.h"

char    *find_path(char *arg, char **envp)
{
  char    **in_path;
  char    *out_path;
  char    tmp;
  int     i;

  i = 0;
  while (envp[i] && strncmp(envp[i], "PATH", 4))
    i++;
  in_path = ft_split(envp[i] + 5, ':');
  i = 0;
  while (in_path[i])
  {
    tmp = ft_strjoin(in_path[i], "/");
    out_path = ft_strjoin(tmp, arg);
    if (access(out_path, F_OK) == 0)
      return(out_path);
    i++;
  }
  return (0);
}

int     exec_cmd(char *arg, char **envp)
{
  	char	**cmd;
	int		i;

	i = 0;
	if (*arg)
	{
		cmd = ft_split(arg, ' ');
		execve(find_path(envp, cmd[0]), cmd, envp);
		perror("\033[31mError");
	}
	else
	{
		perror("\033[31mError");
	}
	exit(127);
}

void	main_process(char **argv, char **envp, int *fd)
{
  int		fileout;

	fileout = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fileout == -1)
		perror("\033[31mError");
	  exit(EXIT_FAILURE);
	dup2(fd[0], STDIN_FILENO);
	dup2(fileout, STDOUT_FILENO);
	close(fd[1]);
	exec_cmd(argv[3], envp);
}

void	spawn_process(char **argv, char **envp, int *fd)
{
  int		filein;

	filein = open(argv[1], O_RDONLY, 0777);
	if (filein == -1)
		perror("\033[31mError");
	  exit(EXIT_FAILURE);
	dup2(fd[1], STDOUT_FILENO);
	dup2(filein, STDIN_FILENO);
	close(fd[0]);
	exec_cmd(argv[2], envp);
}

int		main(int argc, char **argv, char **envp)
{
  	int		fd[2];
	pid_t	pid1;

	if (argc == 5)
	{
		if (pipe(fd) == -1)
			perror("\033[31mError");
	    exit(EXIT_FAILURE);
		pid1 = fork();
		if (pid1 == -1)
			perror("\033[31mError");
	    exit(EXIT_FAILURE);
		if (pid1 == 0)
			spawn_process(argv, envp, fd);
		waitpid(pid1, NULL, 0);
		main_process(argv, envp, fd);
	}
	else
	{
		ft_putstr_fd("\033[31mError: Bad arguments\n\e[0m", 2);
		ft_putstr_fd("Ex: ./pipex <file1> <cmd1> <cmd2> <file2>\n", 1);
	}
	return (0);
}
