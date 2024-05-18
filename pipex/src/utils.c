/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaparra <juaparra@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 12:07:06 by juaparra          #+#    #+#             */
/*   Updated: 2024/05/18 12:07:06 by juaparra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

//  Funcion que abre el archivo con el FD en el modo correcto para la pipe.
int open_file(char *file,int x)
{
    int ret;

    if (x == 0)
        ret = open(file,O_RDONLY, 0777);
    else if (x == 1)
        ret = open(file,O_WRONLY | O_CREAT | O_TRUNC, 0777);
	else {
        perror("Invalid mode for opening file");
        exit(EXIT_FAILURE);
    }
    if (x == -1)
	{
        perror("Failed to open file");
        exit(EXIT_FAILURE);
	}
    return(ret);
}

void    pusherror(void)
{
    ft_printf("======= Wrong input =======\n");
    ft_printf("Please add a similar input that:\n\n");
    ft_printf("./pipex\t infile cmd1 cmd2 outfile\n");
}

void    ft_free(char **t)
{
    size_t  i;

    i = 0;
    while (t[i])
    {
        free(t[i]);
        i++;
    }
    free(t);
}

char	*my_getenv(char *name, char **env)
{
	int		i;
	int		j;
	char	*sub;

	i = 0;
	while (env[i])
	{
		j = 0;
		while (env[i][j] && env[i][j] != '=')
			j++;
		sub = ft_substr(env[i], 0, j);
		if (ft_strcmp(sub, name) == 0)
		{
			free(sub);
			return (env[i] + j + 1);
		}
		free(sub);
		i++;
	}
	return (NULL);
}

char *get_path(char *cmd, char **env) {
    char **allpath = ft_split(my_getenv("PATH", env), ':');
    char **s_cmd = ft_split(cmd, ' ');
    int i = 0;
    while (allpath[i]) {
        char *path_part = ft_strjoin(allpath[i], "/");
        char *exec = ft_strjoin(path_part, s_cmd[0]);
        free(path_part);
        if (access(exec, F_OK | X_OK) == 0) {
            ft_free(s_cmd);
            ft_free(allpath);
            return exec;
        }
        free(exec);
        i++;
    }
    ft_free(s_cmd);
    ft_free(allpath);
    return cmd;
}