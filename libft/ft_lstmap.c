/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suzumaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 18:22:49 by suzumaki          #+#    #+#             */
/*   Updated: 2020/11/05 21:49:06 by suzumaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *res;
	t_list *node;

	if (!lst || !f)
		return (NULL);
	if (!(res = ft_lstnew(f(lst->content))))
		return (NULL);
	node = res;
	lst = lst->next;
	while (lst)
	{
		if (!(node->next = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&res, del);
			return (NULL);
		}
		node = node->next;
		lst = lst->next;
	}
	return (res);
}
