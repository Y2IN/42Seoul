/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 15:02:06 by yje               #+#    #+#             */
/*   Updated: 2022/07/16 19:22:00 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	if ((65 <= c && 90 >= c) || (97 <= c && 122 >= c) || (c <= 0 && c >= 9))
		return (1);
	return (0);
}
