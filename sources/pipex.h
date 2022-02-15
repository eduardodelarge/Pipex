#ifndef PIPEX_H
# define PIPEX_H

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <malloc.h>
#include <fcntl.h>


void    ft_putchar_fd(char c, int fd);
void    ft_putstr_fd(char c, int fd);
void    error(char *name, char *err);
void    ft_putendl_fd(char *s, int fd);
char    *find_path(char **arg, char **envp);
int     exec_cmd(char *arg, char **envp);
void    main_process(char **argv, char **envp, int *fd);
void    spawn_process(char **argv, char **envp, int *fd);
int     main(int argc, char **argv, char **envp);
int     ft_strncmp(const char *str1, const char *str2, size_t n);
char    *ft_strjoin(char const *s1, char const *s2);
char    **ft_split(char const *s, char c);

#endif
