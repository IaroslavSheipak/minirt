/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suzumaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 19:20:25 by suzumaki          #+#    #+#             */
/*   Updated: 2020/10/31 14:01:19 by suzumaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char *cpy_dest;
	unsigned char *cpy_src;

	cpy_dest = (unsigned char *)dest;
	cpy_src = (unsigned char *)src;
	while (n--)
	{
		*cpy_dest = *cpy_src;
		if (*cpy_src == (unsigned char)c)
			return (cpy_dest + 1);
		cpy_dest++;
		cpy_src++;
	}
	return (NULL);
}
