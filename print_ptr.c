/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbarreir <nbarreir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 02:05:47 by nbarreir          #+#    #+#             */
/*   Updated: 2021/04/21 21:34:37 by nbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Deals with padding for pointers
*/

static void	print_doido_ptr_a(t_flags *flags, int size)
{
	if (flags->width > size && flags->minus == 1)
	{
		flags->padding = ' ';
		flags->width = flags->width - size;
		print_padding(flags, flags->width);
	}
	reset_da_cla(flags);
}

void	print_doido_ptr(t_flags *flags, char *ptr, int size)
{
	if (flags->width <= 0)
		flags->width = size;
	else if (flags->width > size && flags->minus == 0)
	{
		flags->width = flags->width - size;
		print_padding(flags, flags->width);
	}
	ft_putstr(flags, "0x", 2);
	if (flags->dot == 1 && flags->precision > size
		&& flags->width > flags->precision)
	{
		flags->width = flags->width - flags->precision;
		print_padding(flags, flags->width);
	}
	if (flags->dot == 1 && flags->precision > size
		&& flags->width < flags->precision)
	{
		flags->padding = '0';
		print_padding(flags, flags->precision - size + 2);
	}
	ft_putstr(flags, ptr, size - 2);
	print_doido_ptr_a(flags, size);
}

/*
** Prints pointers
*/

void	print_p(t_flags *flags, unsigned long pointer)
{
	int				size;
	char			*ptr;

	flags->count++;
	ptr = hextoa(flags, pointer);
	size = (int)ft_strlen(ptr) + 2;
	if ((pointer == 0) && flags->dot == 1)
		size = 2;
	print_doido_ptr(flags, ptr, size);
	free(ptr);
}
