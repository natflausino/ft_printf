/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_star.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbarreir <nbarreir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 03:37:00 by nbarreir          #+#    #+#             */
/*   Updated: 2021/04/09 20:47:19 by nbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

int		is_number(const char *str, t_flags *flags)
{
	flags->number = 0;
	if (!(ft_isdigit((int)str[flags->count])))
		return (0);
	while (ft_isdigit((int)str[flags->count]))
	{
		flags->number = ((flags->number) * 10) + (int)str[flags->count] - '0';
		flags->count++;
	}
	return (1);
}

void	paula_is_star(t_flags *flags, va_list args, int *star)
{
	*star = va_arg(args, int);
	if(*star < 0)
	{
		*star = *star * (-1);
		flags->zero = 0;
		flags->padding = ' ';
	}
	flags->count++;
}
