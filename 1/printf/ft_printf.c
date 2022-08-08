/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 17:23:24 by yje               #+#    #+#             */
/*   Updated: 2022/08/08 19:09:30 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s)
	{
		s++;
		len++;
	}
	return (len);
}

size_t	is_print(const char *format, va_list ap)
{
	size_t	print;

	print = 0;
	if (*format == 'c')
		print = ft_print_c(ap);
	else if (*format == 's')
		print = ft_print_s(ap);
	else if (*format == 'p')
		print = ft_print_p(ap);
	else if (*format == 'd')
		print = ft_print_d(ap);
	else if (*format == 'i')
		print = ft_print_i(ap);
	else if (*format == 'u')
		print = ft_print_u(ap);
	else if (*format == 'x')
		print = ft_print_x(ap, 'x');
	else if (*format == 'X')
		print = ft_print_x(ap, 'X');
	else if (*format == '%')
		print = write(1, "%%", 1);
	return (print);
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	int			i;
	size_t		print;

	if (format == NULL)
		return (0);
	va_start(ap, format);
	i = 0;
	print = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (!format[i])
				break ;
			print += is_print(&format[i], ap);
		}
		else
			print += write(1, &format[i], 1);
		i++;
	}
	va_end(ap);
	return (print);
}
