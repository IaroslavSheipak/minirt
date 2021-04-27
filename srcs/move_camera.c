/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suzumaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 19:37:54 by suzumaki          #+#    #+#             */
/*   Updated: 2021/03/26 13:55:50 by suzumaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

t_camera		new_camera(double fov, t_vector_3d v, t_vector_3d coords)
{
	t_camera	res;
	t_vector_3d	a_xyz;

	a_xyz = vector_cross(create_vector3d(0, 0, -1), v);
	res.coords = coords;
	res.rotation = vector3d_to_quaternion(a_xyz);
	res.rotation.a = 1 +
		ft_dot(create_vector3d(0, 0, -1), v);
	if (ft_dot(create_vector3d(0, 0, -1), v) == -1)
		res.rotation.y = 1;
	res.rotation = quaternion_normalize(res.rotation);
	res.fov = fov;
	return (res);
}

void			move_camera(t_camera *camera,
	t_vector_3d base_direction, double distance)
{
	t_vector_3d	tmp;

	tmp = vector_scalar_multiplication(
	vector_normalize(quaternion_to_vector3d(quaternion_rotate(camera->rotation,
				base_direction))), distance);
	camera->coords = vector_sum(camera->coords, tmp);
}

void			move_camera_forward(t_camera *camera, double distance)
{
	move_camera(camera, create_vector3d(0, 0, -1), distance);
}

void			move_camera_backward(t_camera *camera, double distance)
{
	move_camera(camera, create_vector3d(0, 0, 1), distance);
}

void			move_camera_left(t_camera *camera, double distance)
{
	move_camera(camera, create_vector3d(-1, 0, 0), distance);
}
