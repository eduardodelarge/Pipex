/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caeduard <caeduard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 19:24:11 by coder             #+#    #+#             */
/*   Updated: 2022/02/17 11:28:43 by caeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <errno.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>

char	*ft_strdup(const char *str);
char	*ft_strtrim(const char *s1, const char *set);
void	reverse(char **matrix);
char	*convert(char *string, char spc, char ascii);
void	free_matrix(char **matrix);
void	ft_putendl_fd(char *s, int fd);
void	ft_putstr_fd(char *s, int fd);
void	error_msg(char *name, char *err);
void	exec_cmd(char *arg, char **envp);
void	pipex(int fd1, int fd2, char **argv, char **envp);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
void	path_find(char **envp, char **arg);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif