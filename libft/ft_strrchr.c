/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suzumaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 20:43:49 by suzumaki          #+#    #+#             */
/*   Updated: 2020/10/31 15:06:08 by suzumaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *ptr;
	char *res;

	res = NULL;
	ptr = (char *)s;
	while (*ptr != '\0')
	{
		if (*ptr == c)
			res = ptr;
		ptr++;
	}
	if (c == 0)
		res = ptr;
	return (res);
}
