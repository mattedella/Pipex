/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdella-r <mdella-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:25:40 by mdella-r          #+#    #+#             */
/*   Updated: 2024/06/11 13:37:53 by mdella-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	parent_doc(char **argv, int i, char **envp, t_pipex p)
{
	char	**command;
	char	**env;
	char	*tmp;

	env = NULL;
	command = NULL;
	dup2(p.pfd[i - 1][0], 0);
	close(p.pfd[i - 1][1]);
	dup2(p.fd, 1);
	tmp = my_get_env(&env, &command, envp, argv[i + 2]);
	if (tmp == NULL)
		(void)(free_pfd_2(p.pfd, mat_len(argv)) + ft_error(16));
	free_pfd_2(p.pfd, i);
	execve(tmp, command, envp);
	free_and_exit(env, command, tmp, 17);
}

void	child_doc(char **argv, int i, char **envp, int **pfd)
{
	char	*tmp;
	char	**command;
	char	**env;

	env = NULL;
	command = NULL;
	dup2(pfd[i][1], 1);
	close(pfd[i][0]);
	dup2(pfd[i - 1][0], 0);
	close(pfd[i - 1][1]);
	tmp = my_get_env(&env, &command, envp, argv[i + 2]);
	if (tmp == NULL)
		(void)(free_pfd_2(pfd, mat_len(argv)) + ft_error(18));
	free_pfd_2(pfd, i);
	execve(tmp, command, envp);
	free_and_exit(env, command, tmp, 19);
}

void	docpipex(int argc, char **argv, char **envp, t_pipex p)
{

	p.i = 1;
	while (++p.i < argc - 4)
	{
		p.pid = fork();
		if (p.pid == -1)
			ft_error(21);
		if (p.pid == 0)
			child_doc(argv, p.i, envp, p.pfd);
		else if (p.i < argc - 4)
			close(p.pfd[p.i][1]);
	}
	p.pid = fork();
	if (p.pid == -1)
		ft_error(22);
	if (p.pid == 0)
		parent_doc(argv, p.i, envp, p);
	waitpid(p.pid, NULL, 0);
	free_pfd_2(p.pfd, p.i);
}

void	get_doc(int argc, char **argv, int **pfd)
{
	char	*line;
	int		i;

	i = -1;
	close(pfd[0][0]);
	while (++i < argc - 4)
		write (1, "pipe ", 5);
	write(1, "here_doc > ", 12);
	line = get_next_line(0);
	while (line != NULL && ft_strncmp(line, argv[2], ft_strlen(argv[2])) != 0)
	{
		write(pfd[0][1], line, ft_strlen(line));
		free(line);
		i = -1;
		while (++i < argc - 5)
			write (1, "pipe ", 5);
		write(1, "here_doc > ", 12);
		line = get_next_line(0);
	}
	free_gnl(line);
	close(pfd[0][1]);
	free_pfd_2(pfd, argc - 5);
}
