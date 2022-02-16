/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caeduard <caeduard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 20:29:28 by caeduard          #+#    #+#             */
/*   Updated: 2022/02/15 21:02:54 by caeduard         ###   ########.fr       */
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
	char	*en_var;
	char	**path;
	char	*to_free;
	int		i;
	int		j;

	i = 0;
	i = ft_scroll_envp(envp, i);
	en_var = ft_substr(envp[i], 5, 166);
	path = ft_split(en_var, ':');
	free(en_var);
	i = 0;
	while (path[i] != NULL)
	{
		to_free = ft_strjoin(path[i], "/");
		free(path[i]);
		path[i] = ft_strjoin(to_free, arguments);
		free(to_free);
		if ((access(path[i], X_OK)) == 0)
		{
			for (int j = 0; path[j] != NULL; j++) {
				if (j != i)
					free(path[j]);
			}
			free(path);
			return (path[i]);
		}
		i++;
	}
	for (int j = 0; path[j] != NULL; j++) {
		free(path[j]);
	}
	free(path);
	return (NULL);
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
