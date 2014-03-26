/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raudiber <raudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/25 20:39:56 by raudiber          #+#    #+#             */
/*   Updated: 2014/03/25 21:08:43 by raudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int		remove_env_line(char ***env, int line)
{
	char	**new;
	int		size;
	int		index;

	size = 0;
	while ((*env)[size])
		size++;
	size--;
	new = (char**)malloc(sizeof(char*) * size);
	if (!new)
		return (-1);
	index = 0;
	while (index < (size - 1))
	{
		if (index != line && (*env)[index])
			new[index] = ft_strdup((*env)[index]);
		else if (index != line && !(*env)[index])
			new[index] = 0;
		index++;
	}
	new[index] = '\0';
	env = &new;
	return (1);
}

int		ft_unsetenv(char ***env, char *name)
{
	int		index;

	index = 0;
	if (name)
	{
		ft_putendl("TESTTESTTESTTEST");
		if ((index = grep_var(name, (*env))))
		{
			ft_putendl("TEST2TEST2TEST2");
			ft_putendl(ft_itoa(index));
			return (remove_env_line(env, index));
		}
	}
	return (0);
}