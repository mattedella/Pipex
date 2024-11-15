/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdella-r <mdella-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:06:53 by mdella-r          #+#    #+#             */
/*   Updated: 2024/02/12 15:07:40 by mdella-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	wait_and_free(pid_t pid, int **pfd, int i)
{
	waitpid(pid, NULL, 0);
	free_pfd(pfd, i);
}

void	free_gnl(char *line)
{
	if (line != NULL)
		free(line);
	get_next_line(-1);
}

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	*s2;

	i = 0;
	s1 = (unsigned char *)str1;
	s2 = (unsigned char *)str2;
	if (n == 0)
		return (0);
	while (i < n && s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
	{
		i++;
	}
	if (i == n)
		i--;
	return (s1[i] - s2[i]);
}

int	free_mat(char **mat)
{
	int	l;

	l = 0;
	while (mat[l])
	{
		free (mat[l]);
		l++;
	}
	free (mat);
	return (0);
}

int	free_pfd(int **pfd, int l)
{
	int	i;

	i = 0;
	while (i < l)
	{
		free (pfd[i]);
		i++;
	}
	free (pfd);
	return (0);
}
