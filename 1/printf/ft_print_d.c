/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 15:48:18 by yje               #+#    #+#             */
/*   Updated: 2022/08/08 16:47:22 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

size_t	ft_print_d(va_list ap)
{
	int				tmp;
	char			*format;
	size_t			print;

	print = 0;
	tmp = (int)va_arg(ap, int);
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