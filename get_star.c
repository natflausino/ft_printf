/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_star.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbarreir <nbarreir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 03:37:00 by nbarreir          #+#    #+#             */
/*   Updated: 2021/04/01 00:52:39 by nbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

int		is_number(const char *str, t_flags *flags, size_t i)
{
	flags.number = 0;
	while(ft_isdigit((int)str[i])
	{
		flags.number = ((flags.number) * 10) + ((int)str[i]);
		i++;
	}
	if(!(ft_isdigit((int)str[i]))
		return(0);
	return(1);
}

void	get_is_star(const char *str, t_flags *flags, va_list args, size_t i)
{

}
