/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caeduard <caeduard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 19:22:17 by coder             #+#    #+#             */
/*   Updated: 2022/02/17 00:38:06 by caeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	error_msg(char *name, char *err)
{
	ft_putstr_fd("pipex: ", 2);
	ft_putstr_fd(name, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(err, 2);
}

void	path_find(char **envp, char **arg)
{
	char	**paths;
	char	*path;
	int		i;
	char	*tmp;

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH", 4))
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		tmp = ft_strjoin(paths[i], "/");
		path = ft_strjoin(tmp, arg[0]);
		free(tmp);
		if (access(path, F_OK) == 0)
			execve(path, arg, envp);
		free(path);
		i++;
	}
	free_matrix(paths);
}

void	exec_cmd(char *arg, char **envp)
{
	char	**cmd;
	char	*tmp;

	if (*arg)
	{
		tmp = convert(arg, ' ', 1);
		cmd = ft_split(tmp, ' ');
		free(tmp);
		reverse(cmd);
		path_find(envp, cmd);
		error_msg(cmd[0], "command not found");
		free_matrix(cmd);
	}
	else
	{
		error_msg("", "command not found");
	}
	exit(127);
}

void	pipex(int fd1, int fd2, char **argv, char **envp)
{
	int		fd[2];
	int		id;

	id = 1;
	pipe(fd);
	if (fd1 != -1)
		id = fork();
	if (id == 0)
	{
		dup2(fd1, 0);
		close(fd[0]);
		dup2(fd[1], 1);
		exec_cmd(argv[2], envp);
	}
	else
	{
		dup2(fd2, 1);
		close(fd[1]);
		dup2(fd[0], 0);
		wait(NULL);
		exec_cmd(argv[3], envp);
	}
}

int	main(int argc, char **argv, char *envp[])
{
	int	file1;
	int	file2;

	if (argc == 5)
	{
		file1 = open(argv[1], O_CREAT | O_RDONLY, 00664);
		if (file1 == -1)
			error_msg(argv[1], strerror(errno));
		file2 = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 00664);
		if (file2 == -1)
		{
			error_msg(argv[4], strerror(errno));
			return (1);
		}
		pipex(file1, file2, argv, envp);
	}
	ft_putstr_fd("Invalid arguments.\n", 2);
	return (1);
}
