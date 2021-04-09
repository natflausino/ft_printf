/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbarreir <nbarreir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 00:51:34 by nbarreir          #+#    #+#             */
/*   Updated: 2021/04/09 20:22:31 by nbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

int			ft_toupper(int c)
{
	if (c >= 'a' || c <= 'z')
		c = c - 32;
	return (c);
}

int			ft_tolower(int c)
{
	if (c >= 'A' || c <= 'Z')
		c = c + 32;
	return (c);
}

void		ft_putstr(t_flags *flags, char *s, size_t size)
{
	size_t i;

	i = 0;
	if (!s)
		return ;
	while (i < size)
	{
		ft_putchar(flags, s[i]);
		i++;
	}
	return ;
}
