/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 15:47:39 by yje               #+#    #+#             */
/*   Updated: 2022/08/08 17:37:50 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

size_t	ft_print_s(va_list ap)
{
	char	*tmp;
	size_t	print;

	print = 0;
	tmp = (char *)va_arg(ap, char *);
	if (tmp == NULL)
		tmp = "(null)";
	print = write(1, tmp, ft_strlen(tmp));
	return (print);
}