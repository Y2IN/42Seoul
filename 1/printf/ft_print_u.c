/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 18:06:48 by yje               #+#    #+#             */
/*   Updated: 2022/08/08 18:50:20 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t ft_print_u(va_list ap)
{
	unsigned int	tmp;
	size_t			print;

	print = 0;
	tmp = va_arg(ap, unsigned int);
	print = ft_putnbr(tmp);
	return (print);
}
