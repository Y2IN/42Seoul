/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 16:29:41 by yje               #+#    #+#             */
/*   Updated: 2022/08/03 18:01:10 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

int ft_printf(const char *, ...);
size_t is_print(const char *format, va_list *ap);
size_t ft_print_c(va_list ap);
size_t ft_print_s(va_list ap);
size_t ft_print_d(va_lit ap);
size_t ft_print_i(va_lit ap);
size_t ft_print_u(va_list ap);


#endif