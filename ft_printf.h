/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbarreir <nbarreir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 16:06:31 by nbarreir          #+#    #+#             */
/*   Updated: 2021/04/06 01:04:38 by nbarreir         ###   ########.fr       */
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
	int		count;
}				t_flags;

/*
** Prinft functions
*/

int			ft_printf(const char *input, ...);
t_param		reset_type(void);
void		get_flags_a(const char *str, t_flags *flags, va_list args);
void		get_is_star(const char *str, t_flags *flags, va_list args);

void		print_percent(const char *str, t_flags *flags, va_list args);

/*
**  Utils functions
*/

void		ft_putchar_fd(char c, int fd);
char		*ft_strdup(const char *s1);
int			ft_isdigit(int c);
int			ft_toupper(int c);
int			ft_tolower(int c);

#endif
