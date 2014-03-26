/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raudiber <raudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 22:12:27 by raudiber          #+#    #+#             */
/*   Updated: 2014/03/25 20:06:25 by raudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

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