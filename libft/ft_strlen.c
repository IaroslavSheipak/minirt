/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suzumaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 15:31:54 by suzumaki          #+#    #+#             */
/*   Updated: 2020/10/28 15:41:48 by suzumaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	char	*ptr;
	int		res;

	res = 0;
	ptr = (char *)s;
	while (*ptr)
	{
		res++;
		ptr++;
	}
	return (res);
}
