/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdella-r <mdella-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:06:53 by mdella-r          #+#    #+#             */
/*   Updated: 2024/02/13 14:19:31 by mdella-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>

void	ft_exit(int id);
void	ft_error(int id);
int		free_mat(char **mat);
char	**get_env(char **envp);
size_t	ft_strlen(const char *str);
char	**ft_split(char *s, char c);
char	*valid_command(char **command, char **env);
char	*ft_strjoin(char const *s1, char const *s2);
void	child_process(char **argv, char **envp, int *pfd);
void	parent_process(char **argv, char **envp, int *pfd);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
char	*my_get_env(char ***env, char ***cmd, char **envp, char *argv);

#endif