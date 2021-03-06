/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raudiber <raudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 18:47:54 by raudiber          #+#    #+#             */
/*   Updated: 2014/01/03 15:57:28 by raudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int ft_toupper(int c)
{
	if ((c >= 'a') && (c <= 'z'))
		c -= 32;
	return (c);
}
