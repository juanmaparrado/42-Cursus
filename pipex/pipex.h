/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaparra <juaparra@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 12:06:55 by juaparra          #+#    #+#             */
/*   Updated: 2024/05/18 12:06:55 by juaparra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX
# define PIPEX

#include "lib/libft/libft.h"
#include "lib/printf/ft_printf.h"

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

void    exec(char *cmd, char **env);
void    child(char **argv, int *p_fd, char **env);
void    parent(char **argv, int *p_fd, char **env);
int     open_file(char *file, int x);
void    pusherror(void);
void    ft_free(char **t);
char    *my_getenv(char *name, char **env);
char    *get_path(char *cmd, char **env);
#endif