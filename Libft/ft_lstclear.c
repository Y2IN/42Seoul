/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 18:38:10 by yje               #+#    #+#             */
/*   Updated: 2022/07/29 16:35:49 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*n_save;

	tmp = *lst;
	while (tmp != NULL)
	{
		n_save = tmp->next;
		ft_lstdelone(tmp, del);
		tmp = n_save;
	}
	*lst = NULL;
}
