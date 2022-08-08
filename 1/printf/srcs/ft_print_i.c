/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_i.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 15:49:02 by yje               #+#    #+#             */
/*   Updated: 2022/08/08 18:49:30 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_print_i(va_list ap)
{
	int				tmp;
	size_t			print;

	print = 0;
	tmp = (int)va_arg(ap, int);
	print = ft_putnbr(tmp);
	return (print);
}
