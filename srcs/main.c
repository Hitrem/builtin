/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raudiber <raudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 22:10:58 by raudiber          #+#    #+#             */
/*   Updated: 2014/03/24 22:19:01 by raudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		main(void)
{
	char **env;
	char *entry;

	entry = NULL;
	env = get_env();
	ft_putstr("$>");
	while (get_next_line(0, &entry) > 0)
	{
		if (!ft_strcmp(entry, "env"))
			print_env(env);
		ft_putstr("$>");
	}
	return (0);
}