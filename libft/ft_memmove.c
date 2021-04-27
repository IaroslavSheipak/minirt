/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suzumaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 20:03:15 by suzumaki          #+#    #+#             */
/*   Updated: 2020/11/02 19:34:11 by suzumaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*cpy_dest;
	unsigned char	*cpy_src;
	size_t			len;

	if (dest == NULL && src == NULL)
		return (dest);
	len = n;
	cpy_dest = (unsigned char *)dest;
	cpy_src = (unsigned char *)src;
	if (cpy_dest < cpy_src)
		while (len--)
			*cpy_dest++ = *cpy_src++;
	else
		while (len-- > 0)
			cpy_dest[len] = cpy_src[len];
	return (dest);
}
