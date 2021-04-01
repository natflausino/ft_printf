/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbarreir <nbarreir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 18:12:03 by nbarreir          #+#    #+#             */
/*   Updated: 2021/03/31 23:42:11 by nbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
# include <stdarg.h>
# include <stdio.h>

t_flags		reset_type(void)
{
	t_flags flags;

	flags.type = 0;
	flags.zero = 0;
	flags.minus = 0;
	flags.padding = 0;
	flags.width = 0;
	flags.precision = -1;
	flags.number = 0;
	flags.width_val = 0;
	flags.precision_val = -1;
}

int		ft_printf(const char *format, ...)
{
	const char *str;
	size_t		len_out;
	size_t		i;
	va_list		args;

	va_start(args, *format);
	i = 0;
	len_out = 0;
	if (!(str = ft_strdup(format)))
		return (0);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			get_flags_a(&str[i], &flags, args, i);
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			i++;
		}
		len_out = i;
	}
	free((char *)str);
	va_end(args);
	return (len_out);
}
