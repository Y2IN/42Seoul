/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 16:32:44 by yje               #+#    #+#             */
/*   Updated: 2022/08/11 16:40:33 by yje              ###   ########.fr       */
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
	unsigned long long	tmp;
	int					print;

	print = 0;
	tmp = va_arg(ap, unsigned long long);
	if (tmp == 0)
		return (write(1, "0x0", 3));
	print += write(1, "0x", 2);
	print += ft_put_p(tmp);
	return (print);
}
