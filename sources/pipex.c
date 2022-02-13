/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caeduard <caeduard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 13:41:23 by caeduard          #+#    #+#             */
/*   Updated: 2022/02/13 00:06:46 by caeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <malloc.h>

// create a func that returns and execute a command
// int find_n_exec(const char *path, char *const argv[], char *envp[])
// {
//     int     i;
//     char    *path;
//     char    **curr_path;
    
//     curr_path = envp;
//     i = 0;
//     while (envp[i] && strsep(envp, " ") != NULL)
//         i++;
//     path = strsep(curr_path, " ");
//     if (access(path, F_OK) == 0)
//         return(path);
//     return(0);
     
// }

// static void pipex(int fd1, int fd2, char **argv, char **envp)
// {
    
// }

void    arg_count(char* command)
{
    int i;
    int arg_count;
    
    i = 0;
    arg_count = 0;
    
    while (command[i] == ' ')
    {
        i++;
    }
    command = command + i;
    
    i = 0;
    while (command[i] != '\0')
    {
        if (command[i] == ' ')
             arg_count++;
        i++;
    }
}

void    execute_command(char* command)
{
    int     i;
    char    **argv;
    char    *argument;
    
    char **argv = ft_calloc(arg_count + 2, sizeof(char*));
    char *argument = NULL;
    i = 0;        
    while ((argument = ft_strsep(&command, " ")) != NULL) {
       if (strlen(argument) != 0) {
           argv[i] = ft_calloc(strlen(argument) + 1, sizeof(char));
           strncpy(argv[i], argument, strlen(argument));
       }
       i++; 
    }
    argv[i] = NULL;     
    if (execvp(argv[0], argv) != 0)
    {
        fprintf(stderr, "Error creating pipe. %s",         strerror(errno));
    }
}

int main(int argc, char **argv[])
{

}
