/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uhex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbarreir <nbarreir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 02:04:39 by nbarreir          #+#    #+#             */
/*   Updated: 2021/04/16 01:44:31 by nbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Prints unsigned int
*/

void			print_du_luigi(t_flags *flags, unsigned num)
{
	int				size;
	char			*number;

	flags->count++;
	if (flags->dot == 1)
	{
		flags->zero = 0;
		flags->padding = ' ';
	}
	number = ft_utoa_do_matheus(num);
	size = (int)ft_strlen(number);
	if (num == 0 && flags->dot == 1)
		size = 0;
	print_nat_uhex(flags, number, size);
	free(number);
}

/*
** Deals with precision for u and hexadecimals
*/

static void		precision_nat_uhex(t_flags *flags, char *number, int size)
{
	if (flags->dot == 1 && flags->precision > size)
	{
		flags->padding = '0';
		print_padding(flags, flags->precision - size);
	}
	if (flags->dot == 1 && flags->precision <= 0 && *number == '0')
	{
		if (flags->width > size && flags->minus == 1)
		{
		flags->padding = ' ';
		if (flags->precision > size)
			flags->width = flags->width - flags->precision;
		else
			flags->width = flags->width - size;
		print_padding(flags, flags->width);
		}
		reset_da_cla(flags);
	}
}

void			print_nat_uhex(t_flags *flags, char *number, int size)
{
	if (flags->width <= 0)
		flags->width = size;
	else if (flags->width > size && flags->minus == 0)
	{
		if (flags->precision > size)
			flags->width = flags->width - flags->precision;
		else
			flags->width = flags->width - size;
		print_padding(flags, flags->width);
	}
	precision_nat_uhex(flags, number, size);
	ft_putstr(flags, number, size);
	if (flags->width > size && flags->minus == 1)
	{
		flags->padding = ' ';
		if (flags->precision > size)
			flags->width = flags->width - flags->precision;
		else
			flags->width = flags->width - size;
		print_padding(flags, flags->width);
	}
	reset_da_cla(flags);
}

/*
** Prints hexadecimals x and X
*/

void			print_hex(t_flags *flags, unsigned int num)
{
	int				size;
	char			*number;

	flags->count++;
	if (flags->dot == 1)
	{
		flags->zero = 0;
		flags->padding = ' ';
	}
	number = hextoa(flags, (unsigned long long)num);
	size = (int)ft_strlen(number);
	if (num == 0 && flags->dot == 1)
		size = 0;
	print_nat_uhex(flags, number, size);
	free(number);
}
