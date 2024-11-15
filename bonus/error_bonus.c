/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdella-r <mdella-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:21:37 by mdella-r          #+#    #+#             */
/*   Updated: 2024/02/12 15:07:21 by mdella-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	ft_error(int id)
{
	perror("Error");
	exit(id);
}

int	ft_exit(char *str, int id)
{
	write(2, str, ft_strlen(str));
	write(2, "\n", 2);
	exit (id);
}

void	free_and_exit(char **env, char **command, char *tmp, int id)
{
	free_mat(env);
	free_mat(command);
	free(tmp);
	ft_error(id);
}

int	free_pfd_2(int **pfd, int i)
{
	int	l;

	l = 0;
	while (l < i)
	{
		free(pfd[l]);
		l++;
	}
	free(pfd);
	return (0);
}
