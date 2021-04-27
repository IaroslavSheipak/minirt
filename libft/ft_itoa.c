/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suzumaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 23:28:30 by suzumaki          #+#    #+#             */
/*   Updated: 2020/11/06 18:38:36 by suzumaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nlen(int n)
{
	int i;

	i = n <= 0 ? 1 : 0;
	while (n)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	int		len;
	int		sign;
	char	*str;

	len = ft_nlen(n);
	sign = n < 0 ? -1 : 1;
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	str += len;
	*str-- = '\0';
	if (!n)
		*str = '0';
	while (n)
	{
		*str = sign * (n % 10) + 48;
		if (n > 9 || n < -9)
			str--;
		n /= 10;
	}
	if (sign < 0)
		*--str = '-';
	return (str);
}
