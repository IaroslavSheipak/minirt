/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suzumaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 19:36:13 by suzumaki          #+#    #+#             */
/*   Updated: 2021/03/25 12:20:19 by suzumaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

t_light_list	*ft_lghtnew(t_light light)
{
	t_light_list *res;

	if (!(res = malloc(sizeof(t_light_list))))
		return (NULL);
	res->light = light;
	res->next = NULL;
	return (res);
}

t_light_list	*ft_lghtlast(t_light_list *lst)
{
	while (lst != NULL && lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void			ft_lghtadd_back(t_light_list **lst, t_light_list *new)
{
	if (!lst || !new)
		return ;
	if (!*lst)
		*lst = new;
	else
		ft_lghtlast(*lst)->next = new;
}

t_light			new_light(double ratio, t_vector_3d color, t_vector_3d coords)
{
	t_light light;

	g_is_diffuse_on = 1;
	light.coords = coords;
	light.color = color;
	light.ratio = ratio;
	return (light);
}
