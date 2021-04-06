/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbarreir <nbarreir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 18:12:03 by nbarreir          #+#    #+#             */
/*   Updated: 2021/04/05 21:59:10 by nbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
# include <stdarg.h>
# include <stdio.h>

void		reset_type(t_flags *flags)
{
	flags.type = 0;
	flags.zero = 0;
	flags.minus = 0;
	flags.padding = 0;
	flags.width = 0;
	flags.precision = -1;
	flags.number = 0;
	flags.width_val = 0;
	flags.precision_val = -1;
	flags.count = 0;
}

int				ft_printf(const char *input, ...)
{
	const char	*str;
	size_t		len_out;
	t_flags		flags;
	va_list		args;

	va_start(args, *input);
	reset_type(&flags);
	len_out = 0;
	if (!(str = ft_strdup(input)))
		return (0);
	while (str[flags->count])
	{
		if (str[flags->count] == '%')
		{
			flags->count++;
			get_flags_a(&str[flags->count], &flags, args);
		}
		else
		{
			ft_putchar_fd(str[flags->count], 1);
			flags->count++;
		}
		len_out = flags->count;
	}
	free((char *)str);
	va_end(args);
	return (len_out);
}
