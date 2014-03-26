/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raudiber <raudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/25 20:39:09 by raudiber          #+#    #+#             */
/*   Updated: 2014/03/25 21:08:44 by raudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		grep_var(char *name, char **env)
{
	int		index;
	size_t	size;

	index = 0;
	size = ft_strlen(name);
	while (env[index])
	{
		if (!ft_strncmp(env[index], name, size))
			return (index);
		index++;
	}
	return (0);
}