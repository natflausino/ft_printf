/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cs_per.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbarreir <nbarreir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 23:43:28 by nbarreir          #+#    #+#             */
/*   Updated: 2021/04/08 02:14:06 by nbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print_percent(t_flags *flags)
{
	flags->count++;
	ft_putchar(flags, '%');
}

void		print_c(t_flags *flags, int c)
{
	flags->count++;
	if (flags->width <= 0)
		flags->width = 1;
	else if (flags->width > 1 && flags->minus == 0)
	{
		flags->padding = ' ';
		print_padd(flags);
	}
	ft_putchar(flags, c);
	if (flags->width > 1 && flags->minus == 1)
		print_padd(flags);
}

void		print_padd(t_flags *flags)
{
	int	i;

	i = 0;
	while (i < (flags->width - 1))
	{
		ft_putchar(flags, flags->padding);
		i++;
	}
}

