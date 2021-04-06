/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbarreir <nbarreir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 00:51:34 by nbarreir          #+#    #+#             */
/*   Updated: 2021/04/06 01:03:54 by nbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

int			ft_toupper(int c)
{
	if(c >= 'a' || c <= 'z')
		c = c - 32;
	return (c);
}

int			ft_tolower(int c)
{
	if(c >= 'A' || c <= 'Z')
		c = c + 32;
	return (c);
}
