/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 20:49:39 by yje               #+#    #+#             */
/*   Updated: 2022/09/17 20:49:41 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_next;
	t_list	*tmp;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	new_lst = ft_lstnew((f(lst->content)));
	if (new_lst == NULL)
		return (NULL);
	tmp = new_lst;
	lst = lst->next;
	while (lst != NULL)
	{
		new_next = ft_lstnew(f(lst->content));
		if (new_next == NULL)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		tmp->next = new_next;
		tmp = new_next;
		lst = lst->next;
	}
	return (new_lst);
}
