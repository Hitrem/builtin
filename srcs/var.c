/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raudiber <raudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/25 19:56:56 by raudiber          #+#    #+#             */
/*   Updated: 2014/03/25 20:05:16 by raudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

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
