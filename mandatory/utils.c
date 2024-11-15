/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdella-r <mdella-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:06:53 by mdella-r          #+#    #+#             */
/*   Updated: 2024/01/30 15:13:17 by mdella-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*st;
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	t;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	k = -1;
	st = malloc(sizeof(char) * (i + j + 1));
	if (st == NULL)
		return (NULL);
	while (s1[++k] != '\0')
		st[k] = s1[k];
	t = k;
	k = -1;
	while (s2[++k] != '\0')
		st[t + k] = s2[k];
	st[t + k] = '\0';
	return (st);
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
