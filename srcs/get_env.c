/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raudiber <raudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/25 20:04:04 by raudiber          #+#    #+#             */
/*   Updated: 2014/03/25 21:08:41 by raudiber         ###   ########.fr       */
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