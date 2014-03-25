/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raudiber <raudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 22:12:27 by raudiber          #+#    #+#             */
/*   Updated: 2014/03/25 01:53:50 by raudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

extern char 	**environ;

char		**get_env(void)
{
	char		**env;
	int			index;
	int			size;

	size = 0;
	index = 0;
	while (environ[size])
		size++;
	env = (char**)malloc(sizeof(char*) * size);
	while (index < size)
	{
		env[index] = (char*)malloc(sizeof(char) * ft_strlen(environ[index] + 1));
		if (index == 0)
			env[index] = environ[index];
		else
			ft_strcpy(env[index], environ[index]);
		index++;
	}
	env[index] = '\0';
	return (env);
}

char		**grep_param(char *entry)
{
	return (ft_strsplit(entry, ' '));
}

int			check_env_param(char **param)
{
	int		index;

	index = 0;
	while (param[index])
		index++;
	if (index > 3 || index == 0)
		return (-1);
	else
		return (index);
}

char		*grep_var(char *param)
{
	char	*var;
	int		index;

	index = 7;
	var = (char*)malloc(sizeof(char*) * (ft_strlen(param) + 1));
	while (param[index] != ' ' && param[index])
	{
		var[index - 7] = param[index];
		index++;
	}
	var = ft_strjoin(var, "=");
	var[index - 6] = '\0';
	return (var);
}

void		resize_env(char	***env, int n)
{
	char	**new;
	int		size;

	size = 0;
	while ((*env)[size])
		size++;
	n += size;
	new = (char**)malloc(sizeof(char*) * n);
	size = 0;
	while (size < n)
	{
		if ((*env)[size])
			new[size] = ft_strdup((*env)[size]);
		else
			new[size] = 0;
		size++;
	}
	new[size] = '\0';
	env = &new;
}

char		*ft_else(char	*tmp, char	*str, int i)
{
	int		j;

	j = 0;
	i++;
	j = i;
	while (tmp[i])
	{
		if (tmp[i] != ' ')
		{
			tmp[i] = str[j];
			j++;
		}
		i++;
	}
	return (tmp);
}

void		ft_replace_first_char(char	*str, char c1, char c2)
{
	int		index1;
	int		sig;
	char	*tmp;

	index1 = 0;
	sig = 0;
	if (str && (tmp = (char*)malloc(sizeof(char) * (ft_strlen(str) + 1))))
	{
		tmp = ft_strdup(str);
		while (tmp[index1])
		{
			if (tmp[index1] == c1)
			{
				tmp[index1] = c2;
				sig = 1;
				break ;
			}
			index1++;
		}
		if (!sig)
			tmp[index1] = '\0';
		else
			ft_else(tmp, str, index);
	}
}

void		ft_set_env(char	***env, char *param)
{
	int		index;
	char	*var;

	index = 0;
	if (check_env_param(grep_param(param)) == -1)
		ft_putendl_fd("setenv : Too many arguments.", 2);
	else if ((ft_strncmp(param, "setenv"), ft_strlen(param)) && param)
	{
		var = grep_var(param);
		while ((*env)[index] && ft_strncmp((*env)[index], var, ft_strlen(var)))
			index++;
		resize_env(env, 1);
		if (check_env_param(param) == 2)
			(*env)[index] = ft_strdup(var);
		else if (check_env_param(param) == 3)
		{
			param = param + 7;
			param = ft_replace_first_char(param, ' ', '=');
			(*env)[index] = ft_strdup(param);
		}
	}
	else
		print_env((*env));
}

void		print_env(char **env)
{
	int		index;

	index = 0;
	while (env[index])
	{
		ft_putendl(env[index]);
		index++;
	}
}