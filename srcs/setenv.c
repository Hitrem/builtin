/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raudiber <raudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/25 20:06:39 by raudiber          #+#    #+#             */
/*   Updated: 2014/03/25 21:08:40 by raudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static	void	resize_env(char ***env, int n)
{
	char	**new;
	int		size;

	size = 0;
	while ((*env)[size])
		size++;
	size += n;
	new = (char**)malloc(sizeof(char*) * n);
	size = 0;
	while (size < n)
	{
		if ((*env)[size])
			new[size] = ft_strdup((*env)[size]);
		size++;
	}
	new[size] = '\0';
	env = &new;
}

static	char	*new_env_line(char *name, char *value)
{
	char	*line;

	if (value)
		line = ft_strjoin(name, ft_strjoin("=", value));
	else
		line = ft_strjoin(name, "=");
	return (line);
}

static	int		change_value(char ***env, char *value, int index)
{
	if ((*env)[index])
	{
		(*env)[index] = ft_strjoin((*env)[index], value);
		return (1);
	}
	return (-1);
}

int		ft_setenv(char ***env, char *name, char *value, int over)
{
	int		index;

	index = 0;
	ft_putendl(ft_itoa(over));
	if (name)
	{
		if ((index = grep_var(name, (*env))) && (over == 1))
			return (change_value(env, value, index));
		else
		{
			resize_env(env, 1);
			while ((*env)[index])
				index++;
			(*env)[index - 1] = new_env_line(name, value);
			return (1);
		}
	}
	return (-1);
}