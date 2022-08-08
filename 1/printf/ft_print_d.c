/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 15:48:18 by yje               #+#    #+#             */
/*   Updated: 2022/08/08 18:49:28 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_print_d(va_list ap)
{
	int				tmp;
	size_t			print;

	print = 0;
	tmp = (int)va_arg(ap, int);
	print = ft_putnbr(tmp);
	return (print);
}
