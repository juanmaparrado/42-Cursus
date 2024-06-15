/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaparra <juaparra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 10:33:26 by juaparra          #+#    #+#             */
/*   Updated: 2024/06/15 12:53:15 by juaparra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "lib/libft/libft.h"
# include "lib/printf/ft_printf.h"

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>

void	exec(char *cmd, char **env);
void	child(char **argv, int *p_fd, char **env);
void	parent(char **argv, int *p_fd, char **env);
int		open_file(char *file, int x);
void	pusherror(void);
void	ft_free(char **t);
void	ft_doublefree(char **t, char **s);
char	*my_getenv(char *name, char **env);
char	*get_path(char *cmd, char **env);
#endif
