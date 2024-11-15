/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdella-r <mdella-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:44:36 by mdella-r          #+#    #+#             */
/*   Updated: 2024/02/07 10:55:14 by mdella-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void			*a;
	size_t			i;
	unsigned char	*tmp;
	size_t			n;

	if (nitems == 0 || size == 0)
		return (malloc(0));
	if ((unsigned long long)nitems > ULONG_MAX / (unsigned long long)size)
		return (NULL);
	a = malloc(size * nitems);
	if (a == NULL)
		return (0);
	i = 0;
	n = (long long)size * (long long)nitems;
	tmp = (unsigned char *) a;
	while (i < n)
	{
		tmp[i] = '\0';
		i++;
	}
	a = tmp;
	return (a);
}

size_t	f_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *buff_stat, char *buff)
{
	char	*st;
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	t;

	i = ft_strlen(buff_stat);
	j = ft_strlen(buff);
	k = -1;
	st = malloc(sizeof(char) * (i + j + 1));
	if (st == NULL)
		return (NULL);
	while (buff_stat[++k] != '\0')
		st[k] = buff_stat[k];
	t = k;
	k = -1;
	while (buff[++k] != '\0')
		st[t + k] = buff[k];
	st[t + k] = '\0';
	return (st);
}

char	*ft_strchr(char *buff, int c)
{
	int	i;

	if (buff == NULL)
		return (NULL);
	i = 0;
	while (buff[i])
	{
		if (buff[i] == (char)c)
			return ((char *)&buff[i]);
		i++;
	}
	if (buff[i] == (char)c)
		return ((char *)&buff[i]);
	return (0);
}
