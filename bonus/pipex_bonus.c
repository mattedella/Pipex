/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdella-r <mdella-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:02:34 by mdella-r          #+#    #+#             */
/*   Updated: 2024/06/11 13:34:08 by mdella-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	here_doc(int argc, char **argv, char **envp)
{
	t_pipex	p;

	p.j = -1;
	p.pfd = malloc(sizeof(int *) * (argc - 4));
	while (++p.j < argc - 4)
		p.pfd[p.j] = malloc(sizeof(int) * 2);
	p.fd = open(argv[argc - 1], O_RDWR | O_CREAT | O_APPEND | O_TRUNC, 0644);
	if (p.fd == -1)
		ft_error(15);
	if (argc < 6)
		ft_exit("Error: invalid number of arguments", 10);
	if (pipe(p.pfd[0]) == -1)
		ft_exit("Error: pipe failed", 11);
	p.pid = fork();
	if (p.pid == -1)
		ft_exit("Error: fork failed", 12);
	if (p.pid == 0)
	{
		get_doc(argc, argv, p.pfd);
		child_doc(argv, 1, envp, p.pfd);
	}
	else
	{
		waitpid(p.pid, NULL, 0);
		if (close(p.pfd[0][1]) == -1)
			ft_exit("Error: close failed", 13);
		if (dup2(p.pfd[0][0], 0) == -1)
			ft_exit("Error: dup2 failed", 14);
		docpipex(argc, argv, envp, p);
	}
}

void	child_process(char **argv, int i, char **envp, int **pfd)
{
	int		fd;
	char	*tmp;
	char	**command;
	char	**env;

	command = NULL;
	env = NULL;
	if (i == 0)
	{
		(void)(dup2(pfd[i][1], 1) + close(pfd[i][0]));
		fd = open(argv[1], O_RDONLY, 0644);
		if (fd == -1)
			ft_error(4);
		dup2(fd, 0);
	}
	else
		(void)(dup2(pfd[i][1], 1) + close(pfd[i][0]) +
			dup2(pfd[i - 1][0], 0) + close(pfd[i - 1][1]));
	tmp = my_get_env(&env, &command, envp, argv[i + 2]);
	if (tmp == NULL)
		(void)(free_pfd(pfd, mat_len(argv)) + ft_error(5));
	free_pfd(pfd, i);
	execve(tmp, command, envp);
	free_and_exit(env, command, tmp, 6);
}

void	parent_process(char **argv, int i, char **envp, int **pfd)
{
	int		fd;
	char	**command;
	char	**env;
	char	*tmp;

	command = NULL;
	env = NULL;
	dup2(pfd[i - 1][0], 0);
	close(pfd[i - 1][1]);
	fd = open(argv[i + 3], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		ft_error(7);
	dup2(fd, 1);
	tmp = my_get_env(&env, &command, envp, argv[i + 2]);
	if (tmp == NULL)
		(void)(free_pfd(pfd, mat_len(argv)) + ft_error(8));
	free_pfd(pfd, i);
	execve(tmp, command, envp);
	free_and_exit(env, command, tmp, 9);
}

void	ft_pipex(int argc, char **argv, char **envp)
{
	t_pipex	p;

	p.i = -1;
	p.j = -1;
	p.pfd = malloc(sizeof(int *) * (argc - 4));
	while (++p.j < argc - 4)
		p.pfd[p.j] = malloc(sizeof(int) * 2);
	while (++p.i < argc - 4)
	{
		if (pipe(p.pfd[p.i]) == -1)
			ft_error(1);
		p.pid = fork();
		if (p.pid == -1)
			ft_error(2);
		if (p.pid == 0)
			child_process(argv, p.i, envp, p.pfd);
		else if (p.i < argc - 4)
			close(p.pfd[p.i][1]);
	}
	p.pid = fork();
	if (p.pid == -1)
		ft_error(3);
	if (p.pid == 0)
		parent_process(argv, p.i, envp, p.pfd);
	wait_and_free(p.pid, p.pfd, p.i);
}

int	main(int argc, char **argv, char **envp)
{
	if (argc < 5)
		ft_exit("bad arguments", 0);
	if (envp == NULL || *envp == NULL)
		ft_exit("Error: envp not found", 99);
	if (ft_strncmp(argv[1], argv[argc - 1], ft_strlen(argv[1])) == 0)
		ft_exit("Error: input and output files must differ", 100);
	if (ft_strncmp(argv[1], "here_doc", ft_strlen(argv[1])) == 0)
		here_doc(argc, argv, envp);
	else
		ft_pipex(argc, argv, envp);
}
