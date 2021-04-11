/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbarreir <nbarreir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 23:51:20 by csantos-          #+#    #+#             */
/*   Updated: 2021/04/11 02:37:58 by nbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Prints hexadecimals x and X
*/
void			print_hex(t_flags *flags, long int num)
{
	int				size;
	char			*number;

	flags->count++; // CHOI COMMANDS US TO ALWAYS COUNT THIS SHIT
	if (num < 0)
	{
		num = num * (-1);
		num = UINT_MAX - num + 1;
	}
	number = hextoa(flags, num);
	size = (int)ft_strlen(number);
	print_nat_uhex(flags, number, size);
}

static void		precision_nat_uhex(t_flags *flags, int size)
{
	if (flags->dot == 1 && flags->precision > size)
	{
		flags->padding = '0';
		print_padding(flags, flags->precision - size);
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
	precision_nat_uhex(flags, size);
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
