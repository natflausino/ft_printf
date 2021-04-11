/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbarreir <nbarreir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 01:56:45 by nbarreir          #+#    #+#             */
/*   Updated: 2021/04/11 01:56:48 by nbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			reset_type(t_flags *flags)
{
	flags->type = 0;
	flags->zero = 0;
	flags->minus = 0;
	flags->padding = 0;
	flags->width = 0;
	flags->precision = -1;
	flags->number = 0;
	flags->count = 0;
	flags->len = 0;
	flags->dot = 0;
	flags->negative = 0;
}

int				ft_printf(const char *input, ...)
{
	const char	*str;
	t_flags		flags;
	va_list		args;

	va_start(args, *input);
	reset_type(&flags);
	if (!(str = ft_strdup(input)))
		return (0);
	while (str[flags.count])
	{
		if (str[flags.count] == '%')
		{
			flags.count++;
			get_flags(str, &flags, args);
		}
		else
		{
			ft_putchar(&flags, str[flags.count]);
			flags.count++;
		}
	}
	free((char *)str);
	va_end(args);
	return (flags.len);
}
