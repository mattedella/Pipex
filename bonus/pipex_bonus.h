/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdella-r <mdella-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:10:19 by mdella-r          #+#    #+#             */
/*   Updated: 2024/03/04 18:26:47 by mdella-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_pipex
{
	int		**pfd;
	int		fd;
	pid_t	pid;
	int		i;
	int		j;
}			t_pipex;

typedef struct s_della
{
	int		argc;
	char	**argv;
	char	**envp;
}		t_della;

int		ft_error(int id);
size_t	f_strlen(char *str);
int		free_mat(char **mat);
size_t	ft_strlen(char *str);
void	free_gnl(char *line);
int		mat_len(char **matrix);
char	*get_next_line(int fd);
char	**get_env(char **envp);
char	*ft_cut(char *buff_stat);
char	*ft_copy(char *buff_stat);
int		free_pfd(int **pfd, int i);
int		ft_exit(char *str, int id);
char	**ft_split(char *s, char c);
int		free_pfd_2(int **pfd, int i);
char	*ft_strchr(char *buff, int c);
char	*ft_join(char *buff_stat, char *buff);
void	*ft_calloc(size_t nitems, size_t size);
char	*ft_strjoin(char *buff_stat, char *buff);
void	get_doc(int argc, char **argv, int **pfd);
char	*valid_command(char **command, char **env);
void	wait_and_free(pid_t pid, int **pfd, int i);
void	ft_pipex(int argc, char **argv, char **envp);
void	here_doc(int argc, char **argv, char **envp);
char	*ft_fill(char *buff, char *buff_stat, int fd);
void	child_doc(char **argv, int j, char **envp, int **pfd);
void	parent_doc(char **argv, int i, char **envp, t_pipex p);
void	docpipex(int argc, char **argv, char **envp, t_pipex p);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
void	child_process(char **argv, int i, char **envp, int **pfd);
void	parent_process(char **argv, int i, char **envp, int **pfd);
void	free_and_exit(char **env, char **command, char *tmp, int id);
char	*my_get_env(char ***env, char ***cmd, char **envp, char *argv);

#endif