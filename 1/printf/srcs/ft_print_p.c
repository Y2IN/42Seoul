/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 16:32:44 by yje               #+#    #+#             */
/*   Updated: 2022/08/08 19:07:13 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_p(unsigned long long n)
{
	char	*base;
	int		print;

	base = "0123456789abcdef";
	print = 0;
	putnbr_base(n, base);
	print += ch_count(n);
	return (print);
}

ssize_t	ft_print_p(va_list ap)
{
	size_t	tmp;
	int		print;

	print = 0;
	tmp = (size_t)va_arg(ap, size_t);
	if (tmp == 0)
		return (write(1, "0x0", 3));
	print += write(1, "0x", 2);
	print += ft_put_p((size_t)tmp);
	return (print);
}
