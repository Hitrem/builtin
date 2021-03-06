/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raudiber <raudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 22:10:20 by raudiber          #+#    #+#             */
/*   Updated: 2014/03/25 21:01:42 by raudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# include <libft.h>
# include <stdio.h>

char		**get_env(void);
void		print_env(char **env);

int		ft_unsetenv(char ***env, char *name);
int		grep_var(char *name, char **env);
int		ft_setenv(char ***env, char *name, char *value, int over);

#endif /* !SHELL_H */