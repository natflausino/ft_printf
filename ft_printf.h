/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbarreir <nbarreir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 16:06:31 by nbarreir          #+#    #+#             */
/*   Updated: 2021/04/08 01:40:17 by nbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stddef.h>

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
	int		precision_val;
	int		count;
	int		len;
}				t_flags;

/*
** Prinft functions
*/

int			ft_printf(const char *input, ...);
void		reset_type(t_flags *flags);
void		get_flags(const char *str, t_flags *flags, va_list args);
void		get_flags_a(const char *str, t_flags *flags, va_list args);
void		get_is_star(const char *str, t_flags *flags, va_list args);
int			is_number(const char *str, t_flags *flags);

void		print_percent(t_flags *flags);
void		print_c(t_flags *flags, int c);
void		print_padd(t_flags *flags);

/*
**  Utils functions
*/

void		ft_putchar(t_flags *flags, char c);
char		*ft_strdup(const char *s1);
int			ft_isdigit(int c);
int			ft_toupper(int c);
int			ft_tolower(int c);

#endif
