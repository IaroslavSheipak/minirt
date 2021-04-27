/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quaternion_operations.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suzumaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 19:39:48 by suzumaki          #+#    #+#             */
/*   Updated: 2021/03/25 12:19:41 by suzumaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

t_quaternion	create_quaternion(double a, double x, double y, double z)
{
	t_quaternion res;

	res.a = a;
	res.x = x;
	res.y = y;
	res.z = z;
	return (res);
}

t_quaternion	vector3d_to_quaternion(t_vector_3d vec)
{
	return (create_quaternion(0, vec.x, vec.y, vec.z));
}

t_vector_3d		quaternion_to_vector3d(t_quaternion quat)
{
	return (create_vector3d(quat.x, quat.y, quat.z));
}

double			quaternion_magnitude(t_quaternion quaternion)
{
	return (sqrt(pow(quaternion.a,
		2) + pow(quaternion.x,
			2) + pow(quaternion.y, 2) + pow(quaternion.z, 2)));
}

t_quaternion	quaternion_invert(t_quaternion quaternion)
{
	return (create_quaternion(quaternion.a,
		-quaternion.x, -quaternion.y, -quaternion.z));
}
