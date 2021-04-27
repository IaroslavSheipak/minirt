/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_oper.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suzumaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 19:41:24 by suzumaki          #+#    #+#             */
/*   Updated: 2021/03/25 12:18:58 by suzumaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

double		vector_len(t_vector_3d a)
{
	return (sqrt(a.x * a.x + a.y * a.y + a.z * a.z));
}

t_vector_3d	vector_cross(t_vector_3d a, t_vector_3d b)
{
	t_vector_3d res;

	res.x = a.y * b.z - a.z * b.y;
	res.y = a.z * b.x - a.x * b.z;
	res.z = a.x * b.y - a.y * b.x;
	return (res);
}

t_vector_3d	create_vector3d(double x, double y, double z)
{
	t_vector_3d res;

	res.x = x;
	res.y = y;
	res.z = z;
	return (res);
}

t_vector_3d	vector_normalize(t_vector_3d a)
{
	double denom;

	denom = vector_len(a);
	if (denom == 0)
		return (a);
	a.x /= denom;
	a.y /= denom;
	a.z /= denom;
	return (a);
}

double		ft_dot(t_vector_3d a, t_vector_3d b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}
