/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suzumaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 11:03:54 by suzumaki          #+#    #+#             */
/*   Updated: 2021/03/26 14:13:29 by suzumaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_atof(const char *str)
{
	double	res;
	double	res_fp;
	char	*c;
	int		len;

	len = 0;
	if (str == NULL)
		return (0.0);
	c = (char *)str;
	res = (double)ft_atoi(c);
	while (*c && *c != '.' && *c != ',' && *c != ' ')
		c++;
	if (*c == ',' || *c == ' ')
		return (res);
	if (*c == '.')
		c++;
	res_fp = (double)ft_atoi(c);
	while (*c >= '0' && *c <= '9')
	{
		len++;
		c++;
	}
	while (len--)
		res_fp /= 10;
	return (res + ((res >= 0.0) ? res_fp : -res_fp));
}
