/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_udi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbarreir <nbarreir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 21:10:04 by nbarreir          #+#    #+#             */
/*   Updated: 2021/04/09 23:55:28 by nbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print_doido_da_nat(t_flags *flags, int num)
{
	int size;
	char *number;

	flags->count++; // CHOI MANDOU A GENTE CONTAR SEMPRE ESSA MERDA
	if(num < 0)
	{
		flags->negative = 1;
		num = num * (-1);
	}
	number = ft_itoa(num);
	size = (int)ft_strlen(number);
	if(flags->negative == 1)
	{
		size = size + 1;
		flags->precision = flags->precision + 1;
	}
	if(flags->negative == 1 && flags->zero == 1)
		ft_putchar(flags, '-');
	if (flags->width <= 0)
		flags->width = size;
	else if (flags->width > size && flags->minus == 0)
	{
		if(flags->precision > size)
			flags->width = flags->width - flags->precision;
		else
			flags->width = flags->width - size;
		print_padd(flags, flags->width);
	}
	if (flags->negative == 1 && flags->zero == 0)
	{
		ft_putchar(flags, '-');
		if(flags->dot == 1 && flags->precision > size)
		{
			flags->padding = '0';
			print_padd(flags, flags->precision - size);
		}
	}
	ft_putstr(flags, number, size);
	if (flags->width > size && flags->minus == 1)
	{
		flags->padding = ' ';
		if(flags->precision > size)
			flags->width = flags->width - flags->precision;
		else
			flags->width = flags->width - size;
		print_padd(flags, flags->width);
	}
	flags->width = 0;
	flags->precision = -1;
	flags->minus = 0;
}
