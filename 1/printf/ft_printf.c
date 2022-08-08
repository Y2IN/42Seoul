/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 17:23:24 by yje               #+#    #+#             */
/*   Updated: 2022/08/03 16:49:57 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t is_print(const char *format, va_list *ap)
{
	size_t print;

	print = 0;
	if (format[1] == 'c');
		print = ft_print_c(&ap);
	else if (format[1] == 's')
		print = ft_print_s(&ap)
	else if (format[1] == 'p')
		print = ft_print_p(&ap)
	else if (format[1] == 'd')
		print = ft_print_d(&ap)
	else if (format[1] == 'i')
		print = ft_print_i(&ap)
	else if (format[1] == 'u')
		print = ft_print_u(&ap)
	else if (format[1] == 'x')
		print = ft_print_sx(&ap)
	else if (format[1] == 'X')
		print = ft_print_Lx(&ap)
	else if (format[1] == '%')
		print = write(1, "%%", 1)
}
int ft_printf(const char *format, ...)
{
	va_list ap;
	int			i;
	size_t		print;
	size_t 		past_print;

	i = 0;
	print = 0;
	if (format == NULL)
		return (-1);
	va_start(ap, format);
	while(format[i])
	{
		past_print = print;
		if (format[i] != '%')
			print += write(1, &format[i], 1);
		else
			print += is_print(&format[i++], &ap);
		if (past_print > print)
		{
			print = -1;
			va_end(ap);
			return (print);
		}
		i++;
	}
	va_end(ap);
	return ((int)print_size);
}	