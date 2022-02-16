/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caeduard <caeduard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 20:29:28 by caeduard          #+#    #+#             */
/*   Updated: 2022/02/16 13:17:50 by caeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error(char *name, char *err)
{
	ft_putstr_fd("pipex: ", 2);
	ft_putstr_fd(name, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(err, 2);
}

int		ft_scroll_envp(char **envp, int i)
{
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH", 4) == 0)
			break ;
		i++;
	}
	return (i);
}

char	*path_find(char *arguments, char **envp)
{
	char	**paths;
	char	*path;
	int		i;
	char	*part_path;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		part_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(part_path, arguments);
		free(part_path);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	i = -1;
	while (paths[++i])
		free(paths[i]);
	free(paths);
	return (0);
}

void	child_process(char **argv, char **envp, int *pipefd)
{
	pid_t	pid;
	char	**arguments;
	char	*path;
	int		fd;

	pid = fork();
	if (pid == -1)
		exit (EXIT_FAILURE);
	if (pid == 0)
	{
		arguments = ft_split(argv[2], ' ');
		path = path_find(arguments[0], envp);
		close(pipefd[0]);
		dup2(pipefd[1], 1);
		close(pipefd[1]);
		fd = open(argv[1], 0);
		dup2(fd, 0);
		execve(path, arguments, envp);
	}
	waitpid(pid, NULL, 0);
}

int		main(int argc, char **argv, char **envp)
{
	int		pipefd[2];
	char	*path;
	char	**arguments;
	int		fd;

	if (argc < 5 || argc > 5)
		ft_putstr_fd("Invalid arguments.\n", 2);
	if (pipe(pipefd) == -1)
		error(argv[1], strerror((*__errno_location ())));
	child_process(argv, envp, pipefd);
	arguments = ft_split(argv[3], ' ');
	path = path_find(arguments[0], envp);
	fd = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 777);
	close(pipefd[1]);
	dup2(pipefd[0], 0);
	close(pipefd[0]);
	dup2(fd, 1);
	execve(path, arguments, envp);
	return (0);
}


