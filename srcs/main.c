/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raudiber <raudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 22:10:58 by raudiber          #+#    #+#             */
/*   Updated: 2014/03/25 21:08:47 by raudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		main(void)
{
	char **env;
	char *entry;
	char **param;

	entry = NULL;
	env = get_env();
	ft_putstr("$>");
	while (get_next_line(0, &entry) > 0)
	{
		if (!ft_strcmp(entry, "env"))
			print_env(env);
		else if (!ft_strncmp(entry, "setenv", 5))
		{
			param = ft_strsplit(entry, ' ');
			ft_setenv(&env, param[1], param[2], ft_atoi(param[3]));
		}
		else if (!ft_strncmp(entry, "unsetenv", 7))
		{
			param = ft_strsplit(entry, ' ');
			ft_unsetenv(&env, param[1]);
		}
		ft_putstr("$>");
	}
	return (0);
}