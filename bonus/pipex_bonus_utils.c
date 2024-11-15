/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdella-r <mdella-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:11:50 by mdella-r          #+#    #+#             */
/*   Updated: 2024/02/12 12:28:06 by mdella-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*valid_command(char **command, char **env)
{
	int		i;
	char	*tmp;
	char	*command2;

	i = 0;
	command2 = ft_strjoin("/", command[0]);
	while (env[i])
	{
		tmp = ft_strjoin(env[i], command2);
		if (access(tmp, F_OK) == 0)
		{
			free(command2);
			return (tmp);
		}
		free (tmp);
		i++;
	}
	free(command2);
	return (NULL);
}

char	**get_env(char **envp)
{
	int		i;
	char	**mat;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH", 4) == 0)
		{
			mat = ft_split(envp[i] + 5, ':');
			return (mat);
		}
		i++;
	}
	return (NULL);
}

char	*my_get_env(char ***env, char ***cmd, char **envp,
					char *argv)
{
	char	*tmp;

	*env = get_env(envp);
	if (*env == NULL)
		return (NULL);
	*cmd = ft_split(argv, ' ');
	if (*cmd == NULL)
	{
		free_mat(*env);
		return (NULL);
	}
	tmp = valid_command(*cmd, *env);
	if (tmp == NULL)
	{
		free_mat(*env);
		free_mat(*cmd);
		return (NULL);
	}
	return (tmp);
}

int	mat_len(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i] != NULL)
		i++;
	return (i - 4);
}
