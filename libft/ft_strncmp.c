/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suzumaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 18:30:43 by suzumaki          #+#    #+#             */
/*   Updated: 2020/11/07 10:52:05 by suzumaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char *str1;
	unsigned char		*str2;

	if ((s1 && (s1 == s2)) || !n)
		return (0);
	str1 = (const unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (n-- && (*str1 || *str2))
	{
		if (*str1++ != *str2++)
			return (*(--str1) - *(--str2));
	}
	return (0);
}
