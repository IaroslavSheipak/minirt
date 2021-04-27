/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suzumaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 19:35:34 by suzumaki          #+#    #+#             */
/*   Updated: 2021/03/25 12:17:27 by suzumaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

t_camera_list	*ft_camnew(t_camera camera)
{
	t_camera_list *res;

	if (!(res = malloc(sizeof(t_camera_list))))
		return (NULL);
	res->camera = camera;
	res->next = NULL;
	return (res);
}

t_camera_list	*ft_camlast(t_camera_list *lst)
{
	while (lst != NULL && lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void			ft_camadd_back(t_camera_list **lst, t_camera_list *new)
{
	if (!lst || !new)
		return ;
	if (!*lst)
		*lst = new;
	else
		ft_camlast(*lst)->next = new;
}
