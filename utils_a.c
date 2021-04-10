/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbarreir <nbarreir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 00:51:34 by nbarreir          #+#    #+#             */
/*   Updated: 2021/04/09 23:57:57 by nbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

int			ft_toupper(int c)
{
	if (c >= 'a' || c <= 'z')
		c = c - 32;
	return (c);
}

int			ft_tolower(int c)
{
	if (c >= 'A' || c <= 'Z')
		c = c + 32;
	return (c);
}

void		ft_putstr(t_flags *flags, char *s, size_t size)
{
	size_t i;

	i = 0;
	if (!s)
		return ;
	while (i < size)
	{
		ft_putchar(flags, s[i]);
		i++;
	}
	return ;
}

static void	conver_putnbr(int c, char *str, long int i)
{
	unsigned int m;

	m = c;
	if (c < 0)
	{
		str[0] = '-';
		m = (m * (-1));
	}
	if (m >= 10)
		conver_putnbr((m / 10), str, (i - 1));
	str[i] = (m % 10) + '0';
}

char		*ft_itoa(int n)
{
	char		*str;
	long int	j;
	long int	count;

	j = n;

	count = 0;
	if (j <= 0)
		count++;
	while (j)
	{
		j = (j / 10);
		count++;
	}
	str = malloc(sizeof(char) * (count + 1));
	if (!str)
		return (NULL);
	str[count] = 0;
	conver_putnbr(n, str, (count - 1));
	return (str);
}
