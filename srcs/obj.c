/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suzumaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 19:38:12 by suzumaki          #+#    #+#             */
/*   Updated: 2021/03/25 12:20:33 by suzumaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers//minirt.h"

t_object_list	*ft_objnew(t_object_3d object)
{
	t_object_list *res;

	if (!(res = malloc(sizeof(t_object_list))))
		return (NULL);
	res->obj = object;
	res->next = NULL;
	return (res);
}

t_object_list	*ft_objlast(t_object_list *lst)
{
	while (lst != NULL && lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void			ft_objadd_back(t_object_list **lst, t_object_list *new)
{
	if (!lst || !new)
		return ;
	if (!*lst)
		*lst = new;
	else
		ft_objlast(*lst)->next = new;
}
