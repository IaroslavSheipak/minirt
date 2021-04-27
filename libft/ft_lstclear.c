/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suzumaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 18:10:34 by suzumaki          #+#    #+#             */
/*   Updated: 2020/11/05 21:47:32 by suzumaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	if (((*lst)->next) != NULL)
		ft_lstclear(&((*lst)->next), del);
	ft_lstdelone(*(lst), del);
	*lst = NULL;
}
