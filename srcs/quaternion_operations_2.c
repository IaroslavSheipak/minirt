/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quaternion_operations_2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suzumaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 12:55:14 by suzumaki          #+#    #+#             */
/*   Updated: 2021/03/25 12:22:40 by suzumaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

t_quaternion	quaternion_normalize(t_quaternion quaternion)
{
	double magnitude;

	magnitude = quaternion_magnitude(quaternion);
	return (create_quaternion(quaternion.a / magnitude,
		quaternion.x / magnitude,
			quaternion.y / magnitude, quaternion.z / magnitude));
}

t_quaternion	quaternion_set_rotation(double angle, t_vector_3d axis)
{
	t_quaternion res;

	res = quaternion_normalize(create_quaternion(0,
		axis.x, axis.y, axis.z));
	res = create_quaternion(cos(angle / 2),
							sin(angle / 2) * res.x,
							sin(angle / 2) * res.y, sin(angle / 2) * res.z);
	return (res);
}

t_quaternion	quaternion_product(t_quaternion a, t_quaternion b)
{
	t_quaternion res;

	res.a = a.a * b.a - a.x * b.x - a.y * b.y - a.z * b.z;
	res.x = a.a * b.x + a.x * b.a + a.y * b.z - a.z * b.y;
	res.y = a.a * b.y + b.a * a.y + a.z * b.x - b.z * a.x;
	res.z = a.a * b.z + b.a * a.z + a.x * b.y - b.x * a.y;
	return (res);
}

t_quaternion	quaternion_compose_rotation(t_quaternion first,
											t_quaternion second)
{
	return (quaternion_product(second, first));
}

t_quaternion	quaternion_rotate(t_quaternion rotation, t_vector_3d vector)
{
	return (quaternion_product(quaternion_product(rotation,
		vector3d_to_quaternion(vector)),
			quaternion_invert(rotation)));
}
