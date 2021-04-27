/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suzumaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 18:36:42 by suzumaki          #+#    #+#             */
/*   Updated: 2020/11/04 19:09:10 by suzumaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	n;

	n = 0;
	if (!(ptr = malloc((len + 1) * sizeof(char)))
		|| !(s))
		return (NULL);
	while (n < len && start + n < ft_strlen(s))
	{
		ptr[n] = (char)s[start + n];
		++n;
	}
	ptr[n] = '\0';
	return (ptr);
}
