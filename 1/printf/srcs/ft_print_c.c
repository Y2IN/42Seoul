/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 15:38:10 by yje               #+#    #+#             */
/*   Updated: 2022/08/08 15:38:43 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_print_c(va_list ap)
{
	unsigned char	tmp;
	size_t			print;

	print = 0;
	tmp = (unsigned char)va_arg(ap, int);
	print = write(1, &tmp, 1);
	return (print);
}
