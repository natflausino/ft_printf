/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cs_per.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbarreir <nbarreir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 01:35:39 by nbarreir          #+#    #+#             */
/*   Updated: 2021/06/07 20:20:31 by nbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Prints %
*/

void	print_percent(t_flags *flags)
{
	int	size;

	size = 1;
	flags->count++;
	if (flags->width <= 0)
		flags->width = size;
	else if (flags->width > size && flags->minus == 0)
	{
		flags->width = flags->width - size;
		print_padding(flags, flags->width);
	}
	ft_putchar(flags, '%');
	if (flags->width > size && flags->minus == 1)
	{
		flags->width = flags->width - size;
		print_padding(flags, flags->width);
	}
	reset_da_cla(flags);
}

/*
** Prints chars
*/

void	print_choi(t_flags *flags, int c)
{
	flags->count++;
	if (flags->asterisk == 1)
		flags->minus = 1;
	if (flags->width <= 0)
		flags->width = 1;
	else if (flags->width > 1 && flags->minus == 0)
	{
		flags->padding = ' ';
		print_padding(flags, flags->width - 1);
	}
	ft_putchar(flags, c);
	if (flags->width > 1 && flags->minus == 1)
		print_padding(flags, flags->width - 1);
	reset_da_cla(flags);
}

/*
** Prints strings
*/

void	print_spaco(t_flags *flags, char *s)
{
	int	size;

	if (!s)
		s = "(null)";
	size = (int)ft_strlen(s);
	flags->count++;
	if (flags->dot == 1 && flags->precision < size)
		size = flags->precision;
	if (flags->width <= 0)
		flags->width = size;
	else if (flags->width > size && flags->minus == 0)
	{
		if (flags->width > flags->precision && flags->zero == 0)
			flags->padding = ' ';
		flags->width = flags->width - size;
		print_padding(flags, flags->width);
	}
	ft_putstr(flags, s, size);
	if (flags->width > size && flags->minus == 1)
	{
		flags->width = flags->width - size;
		print_padding(flags, flags->width);
	}
	reset_da_cla(flags);
}
