/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_camera2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suzumaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 10:17:04 by suzumaki          #+#    #+#             */
/*   Updated: 2021/03/25 12:23:10 by suzumaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

void			move_camera_right(t_camera *camera, double distance)
{
	move_camera(camera, create_vector3d(1, 0, 0), distance);
}

void			move_camera_up(t_camera *camera, double distance)
{
	move_camera(camera, create_vector3d(0, 1, 0), distance);
}

void			move_camera_down(t_camera *camera, double distance)
{
	move_camera(camera, create_vector3d(0, -1, 0), distance);
}

void			rotate_camera(t_camera *camera,
	double angle, t_vector_3d base_vector)
{
	t_quaternion	upd_quat;

	base_vector =
			quaternion_to_vector3d(quaternion_rotate(camera->rotation,
				base_vector));
	upd_quat = quaternion_set_rotation(angle, base_vector);
	camera->rotation = quaternion_compose_rotation(camera->rotation, upd_quat);
}

void			roll_camera(t_camera *camera, double angle)
{
	t_vector_3d	base_vector;

	base_vector.x = 0;
	base_vector.y = 0;
	base_vector.z = 1;
	rotate_camera(camera, angle, base_vector);
}
