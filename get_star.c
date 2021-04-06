/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_star.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbarreir <nbarreir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 03:37:00 by nbarreir          #+#    #+#             */
/*   Updated: 2021/04/06 01:35:12 by nbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

int		is_number(const char *str, t_flags *flags)
{
	flags->number = 0;
	while(ft_isdigit((int)str[flags->count])
	{
		flags->number = ((flags->number) * 10) + ((int)str[flags->count]);
		i++;
	}
	if(!(ft_isdigit((int)str[flags->count]))
		return(0);
	return(1);
}

void	get_is_star(const char *str, t_flags *flags, va_list args)
{
	flags->precision_val = va_arg(args, int);
	if(str[flags->count - 1] == '.')
	{
		if(flags->number >= 0)
		{
			flags->precision = flags->precision_val;
			flags->zero = 0;
			flags->padding = ' ';
		}
	}
	if(flags->number < 0)
	{
		flags->width = (flags->number * (-1));
		flags->zero = 0;
		flags->padding = ' ';
	}
	else
		flags->width = flags->number; //flags->width_val = flags->number ????
	flags->count++;
}

