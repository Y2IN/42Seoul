/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 18:06:48 by yje               #+#    #+#             */
/*   Updated: 2022/08/08 16:02:54 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

size_t ft_print_u(va_list ap)
{
	unsigned int	tmp;
	char			*format;
	size_t			print;

	print = 0;
	tmp = (unsigned int)va_arg(ap, unsigned int);
	if (tmp == 0)
		print = write(1, "0", 1);
	else
	{
		format = ft_itoa(tmp);
		print = write(1, format, ft_strlen(format));
		free(format);
	}
	return (print);
}