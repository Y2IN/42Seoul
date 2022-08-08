/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 13:37:36 by yje               #+#    #+#             */
/*   Updated: 2022/08/03 18:06:41 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

size_t	ft_print_c(va_list ap)
{
	unsigned char	tmp;
	size_t			print;

	print = 0;
	tmp = (unsigned char)va_arg(ap, int);
	print = write(1, &tmp, 1);
	return (print);
}

size_t	ft_print_s(va_list ap)
{
	unsigned char	*tmp;
	size_t			print;

	print = 0;
	tmp = (char *)va_arg(ap, char *);
	if (tmp == NULL)
		tmp = "(null)";
	print = write(1, tmp, ft_strlen(tmp));
	return (print);
}

size_t	ft_print_d(va_lit ap)
{
	unsigned char	tmp;
	char			*format;
	size_t			print;

	print = 0;
	tmp = (int)va_arg(ap, int);
	if (tmp == 0)
		print = write(1, "0", 1);
	else
	{
		str = ft_itoa(tmp);
		print = write(1, format, ft_strlen(format));
		free(format);
	}
	return (print);
}

size_t	ft_print_i(va_lit ap)
{
	unsigned char	tmp;
	char			*format;
	size_t			print;

	print = 0;
	tmp = (int)va_arg(ap, int);
	if (tmp == 0)
		print = write(1, "0", 1);
	else
	{
		str = ft_itoa(tmp);
		print = write(1, format, ft_strlen(format));
		free(format);
	}
	return (print);
}
