/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suzumaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 18:34:28 by suzumaki          #+#    #+#             */
/*   Updated: 2020/11/03 16:56:43 by suzumaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	const char	*cps;
	char		*res;
	char		*cp_res;

	cps = s;
	if (!(res = malloc((ft_strlen(s) + 1) * sizeof(const char))))
		return (NULL);
	cp_res = res;
	while (*cps)
	{
		ft_memset(cp_res, *cps, 1);
		cp_res++;
		cps++;
	}
	ft_memset(cp_res, '\0', 1);
	return (res);
}
