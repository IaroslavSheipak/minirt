/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suzumaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 19:00:25 by suzumaki          #+#    #+#             */
/*   Updated: 2020/11/04 19:17:31 by suzumaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	char	*res;
	size_t	n;

	if ((!(s1 && s2)))
		return (NULL);
	n = 1 + ft_strlen(s1) + ft_strlen(s2);
	if (!(ptr = malloc(sizeof(char) * (n))))
		return (NULL);
	res = ptr;
	while (n-- && *s1 != '\0')
		*ptr++ = *s1++;
	while (n-- && s2 != '\0')
		*ptr++ = *s2++;
	*ptr = '\0';
	return (res);
}
