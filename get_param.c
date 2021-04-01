/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_param.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbarreir <nbarreir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 20:21:05 by nbarreir          #+#    #+#             */
/*   Updated: 2021/04/01 00:00:10 by nbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
# include <stdarg.h>
# include <stdio.h>

static void		get_specs(t_flags *flags, va_list args, size_t len_out)
{
	if (flags->type == 'c')
		print_c(args, flags, len_out);
	else if (flags->type == 'd' || flags->type == 'i')
		print_di(args, flags, len_out);
	else if (flags->type == 's')
		print_s(args, flags, len_out);
	else if (flags->type == 'p')
		print_p(args, flags, len_out);
	else if (flags->type == 'u')
		print_u(args, flags, len_out);
	else if (flags->type == 'x')
		print_x(args, flags, len_out);
	else if (flags->type == 'X')
		print_xx(args, flags, len_out);
	else if (flags->type == 'n')
		print_n(args, flags, len_out);
}

void	get_flags_b(const char *str, t_flags *flags, va_list args, size_t i)
{
	if (str[i] == '.')
	{
		i++;
		if(str[i] == '*')
			get_is_star(str, flags, args, i);
		else if (is_number(str, flags, i) == 1)
		{
			flags.precision = flags.number;
			flags.zero = 0;
			flags.padding = ' ';
		}
		else
		{
			flags.precision = 0;
			flags.zero = 0;
			flags.padding = ' ';
		}
	}
}

void	get_flags_a(const char *str, t_flags *flags, va_list args, size_t i)
{
	while (str[i] == '0' || str[i] == '-')
	{
		if(str[i] == '0' && flags.minus == 0)
		{
			flags.zero = 1;
			flags.padding = '0';
		}
		else if (str[i] == '-' || flags.zero == 0)
		{
			flags.minus = 1;
			flags.padding = ' ';
		}
		i++;
	}
	if(str[i] == '*')
		get_is_star(str, &flags, args, i);
	else if (read_number(str, &flag, i) == 1)
		flags.width = flags.number;
	get_flags_b(str, &flags, args, i);
}

void	ft_percent(const char *str, va_list args)
{
	int i;

	i = 0;
	reset_type();
	if (str[i + 1] && str[i] == '%')
		ft_putchar_fd('%', 1);

	printf("chegou depois do percent\n");
}
