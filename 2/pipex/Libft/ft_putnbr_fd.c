/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 20:50:59 by yje               #+#    #+#             */
/*   Updated: 2022/09/17 20:51:01 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	ln;
	char	c;

	if (fd < 0)
		return ;
	ln = (long)n;
	if (n < 0)
	{
		write(fd, "-", 1);
		ln *= -1;
	}
	if (ln < 10)
	{
		c = ln + '0';
		write(fd, &c, 1);
	}
	else
	{
		ft_putnbr_fd(ln / 10, fd);
		c = ln % 10 + '0';
		write(fd, &c, 1);
	}	
}
