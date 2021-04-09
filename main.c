/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbarreir <nbarreir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 20:10:58 by nbarreir          #+#    #+#             */
/*   Updated: 2021/04/09 20:33:52 by nbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main(void)
{
	//char a;

	//a = 'b';
	//printf("hello1\n");
	//ft_printf("hello2\n");

	//printf("|%-*c|", 3, a);
	//printf("\n");
	//ft_printf("|%-.*c|", 3, a);

	printf("%-60s: |%s|","format identifier", "quarenta-e-dois");
	printf("\n");
	ft_printf("%-60s: |%s|","FT format identifier", "quarenta-e-dois");
	printf("\n");
	printf("%-60s: |%20s|", "with minimum field (20) width", "quarenta-e-dois");
	printf("\n");
	ft_printf("%-60s: |%20s|", "FT with minimum field (20) width", "quarenta-e-dois");
	printf("\n");
	printf("%-60s: |%-20s|", "minimum field (20) left align", "quarenta-e-dois");
	printf("\n");
	ft_printf("%-60s: |%-20s|", "FT minimum field (20) left align", "quarenta-e-dois");
	printf("\n");
	printf("%-60s: |%.8s|", "precision (8) field", "quarenta-e-dois");
	printf("\n");
	ft_printf("%-60s: |%.8s|", "FT precision (8) field", "quarenta-e-dois");
	printf("\n");
	printf("%-60s: |%-.8s|", "precision (8) field left align", "quarenta-e-dois");
	printf("\n");
	ft_printf("%-60s: |%-.8s|", "FT precision (8) field left align", "quarenta-e-dois");
	printf("\n");
	printf("%-60s: |%20.8s|", "minimum (20) and precision (8) field", "quarenta-e-dois");
	printf("\n");
	ft_printf("%-60s: |%20.8s|", "FT minimum (20) and precision (8) field", "quarenta-e-dois");
	printf("\n");
	printf("%-60s: |%-20.8s|", "minimum (20) and precision (8) field left align", "quarenta-e-dois");
	printf("\n");
	ft_printf("%-60s: |%-20.8s|", "FT minimum (20) and precision (8) field left align", "quarenta-e-dois");
	printf("\n");
	printf("%-60s: |%-*.*s|", "star minimum (20) and precision (8) field left align", 20, 8, "quarenta e dois");
	printf("\n");
	ft_printf("%-60s: |%-*.*s|", "FT star minimum (20) and precision (8) field left align", 20, 8, "quarenta e dois");
	printf("\n");
}
