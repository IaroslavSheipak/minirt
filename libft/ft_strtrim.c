/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suzumaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 17:03:16 by suzumaki          #+#    #+#             */
/*   Updated: 2020/11/05 23:55:55 by suzumaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_isset(char s1, char const *set)
{
	char *pt_set;

	pt_set = (char *)set;
	while (*pt_set != '\0')
	{
		if (s1 == *pt_set)
			return (1);
		pt_set++;
	}
	return (0);
}

static size_t	ft_reslen(char const *s1, char const *set)
{
	char			*pt_s1;
	static	size_t	n;
	int				e;

	e = 0;
	n = ft_strlen(s1);
	pt_s1 = (char *)s1;
	while (ft_isset(*pt_s1, set) && *pt_s1 != '\0')
	{
		n--;
		pt_s1++;
	}
	while (pt_s1[e] != '\0')
		e++;
	e = e - 1;
	while (ft_isset(pt_s1[e], set) && n)
	{
		e = e - 1;
		n = n - 1;
	}
	return (n);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char	*pt_s1;
	char	*ptr_res;
	char	*res;
	int		z;

	if (!(s1 && set))
		return (NULL);
	z = ft_reslen(s1, set);
	if (!(res = malloc(sizeof(char) * (1 + z))))
		return (NULL);
	res[z] = '\0';
	pt_s1 = (char *)s1;
	ptr_res = res;
	while (ft_isset(*pt_s1, set) && pt_s1 != '\0')
		pt_s1++;
	while (*pt_s1 != '\0' && res && z > 0)
	{
		*res++ = *pt_s1++;
		z--;
	}
	return (ptr_res);
}
