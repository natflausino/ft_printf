/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbarreir <nbarreir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 16:06:31 by nbarreir          #+#    #+#             */
/*   Updated: 2021/03/31 23:41:58 by nbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>
# include <stdio.h>

/*
**  Struct Part
*/
typedef struct s_flags
{
	char	type;
	char	zero;
	char	minus;
	char	padding;
	int		width;
	int		precision;
	int		number;
	int		width_val;
	int		precision_val;
}				t_flags;

/*
** Prinft functions
*/

int			ft_printf(const char *format, ...);
void		ft_percent(const char *format, va_list args);
t_param		reset_type(void);

/*
**  Utils functions
*/

void		ft_putchar_fd(char c, int fd);
char		*ft_strdup(const char *s1);

#endif
