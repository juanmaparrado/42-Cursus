/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaparra <juaparra@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 12:06:34 by juaparra          #+#    #+#             */
/*   Updated: 2024/05/18 12:06:34 by juaparra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	exec(char *cmd, char **env){
	char    **s_cmd;
	char    *path;
	
	s_cmd = ft_split(cmd, ' ');
	path = get_path(s_cmd[0], env);
	if (execve(path, s_cmd, env) == -1)
	{
		ft_printf("Command not found");
		ft_printf(s_cmd[0]);
		ft_free(s_cmd);
		exit(EXIT_FAILURE);
	}
}

void    child(char **argv, int *p_fd, char **env){
    int fd;

    fd = open_file(argv[1], 0);
    if (fd == -1) {
        perror("Failed to open outfile");
        exit(EXIT_FAILURE);
    }
    dup2(fd, 0);
    dup2(p_fd[1], 1);
    close(p_fd[0]);
    exec(argv[2], env);
}

void    parent(char **argv, int *p_fd, char **env){
    int fd;

    fd = open_file(argv[4],1);
    if (fd == -1) {
        perror("Failed to open outfile");
        exit(EXIT_FAILURE);
    }
    dup2(fd,1);
    dup2(p_fd[0],0);
    close(p_fd[1]);
    exec(argv[3], env);
}

int main(int argc, char **argv, char **env){
    int p_fd[2];  //posicion 0 de lectura y posicion 1 de escritura
    pid_t   pid;    //identificador de procesos hijos

    if (argc != 5)
    {
        pusherror();
        return(EXIT_FAILURE);
    }
    if(pipe(p_fd) == -1)
    {
        perror("Pipe failed");
        return(EXIT_FAILURE);
    }
    pid = fork();
    if (pid == -1)
        return(EXIT_FAILURE);
    if (!pid)
        child(argv, p_fd, env);
    parent(argv, p_fd, env);
}
