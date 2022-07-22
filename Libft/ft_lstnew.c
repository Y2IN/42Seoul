/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 16:44:16 by yje               #+#    #+#             */
/*   Updated: 2022/07/22 18:04:05 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*nlist;

	nlist = (t_list *)malloc(sizeof(t_list));
	if (nlist == 0)
		return (0);
	nlist->next = 0;
	nlist->content = content;
	return (nlist);
}
