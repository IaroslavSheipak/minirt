/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suzumaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 19:18:59 by suzumaki          #+#    #+#             */
/*   Updated: 2020/11/05 23:56:26 by suzumaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned
int, char))
{
	char	*res;
	size_t	n;

	n = 0;
	if (!(s && f))
		return (NULL);
	if (!(res = malloc(sizeof(char) * ft_strlen(s) + 1)))
		return (NULL);
	while (n < ft_strlen(s))
	{
		res[n] = f(n, s[n]);
		n++;
	}
	res[n] = '\0';
	return (res);
}
