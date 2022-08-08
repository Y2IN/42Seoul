/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 16:29:41 by yje               #+#    #+#             */
/*   Updated: 2022/08/08 19:09:50 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

size_t	ft_print_c(va_list ap);
size_t	ft_print_d(va_list ap);
size_t	ft_print_i(va_list ap);
int		ft_put_p(unsigned long long n);
ssize_t	ft_print_p(va_list ap);
size_t	ft_print_s(va_list ap);
size_t	ft_print_u(va_list ap);
int		ft_putchar(char c);
int		ch_count(unsigned long long n);
void	putnbr_base(unsigned long long n, char *base);
int		ft_puthex(int i, char x);
size_t	ft_print_x(va_list ap, char a);
size_t	is_print(const char *format, va_list ap);
int		ft_printf(const char *format, ...);
size_t	ft_strlen(const char *s);
char	*ft_itoa(long long n);
int		ft_putnbr(long long n);

#endif
