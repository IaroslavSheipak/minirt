/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suzumaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 14:01:01 by suzumaki          #+#    #+#             */
/*   Updated: 2021/03/26 18:18:30 by suzumaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../headers/minirt.h"

static int	check_ptr(const char *ptr)
{
	if ((*ptr == ' ' || *ptr == '\t' || *ptr == '\n' ||
		*ptr == '\v' || *ptr == '\f' || *ptr == '\r'))
		return (1);
	return (0);
}

static int	check_cnt(int res,
	int sign, int cnt)
{
	if (cnt > 7)
		return (1000000);
	return (res * sign);
}

static void	check_sym(const char *ptr)
{
	if (*ptr > ' ' && *ptr != '.' && *ptr != ',')
		manage_error("wrong symbol in number");
}

int			ft_atoi(const char *ptr)
{
	int		res;
	int		cnt;
	int		sign;

	res = 0;
	cnt = 0;
	sign = 1;
	if (ptr == NULL)
		return (0);
	while (check_ptr(ptr))
		ptr++;
	if (*ptr == '-')
		sign = -1;
	if (*ptr == '-' || *ptr == '+')
		ptr++;
	while (*ptr >= '0' && *ptr <= '9')
	{
		res = res * 10 + *ptr - '0';
		if (res != 0)
			cnt++;
		ptr++;
	}
	check_sym(ptr);
	return (check_cnt(res, sign, cnt));
}
