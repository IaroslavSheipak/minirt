/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rest_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suzumaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 10:55:23 by suzumaki          #+#    #+#             */
/*   Updated: 2021/03/25 12:23:27 by suzumaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

void			pitch_camera(t_camera *camera, double angle)
{
	t_vector_3d	base_vector;

	base_vector.x = -1;
	base_vector.y = 0;
	base_vector.z = 0;
	rotate_camera(camera, angle, base_vector);
}

void			yaw_camera(t_camera *camera, double angle)
{
	t_vector_3d	base_vector;

	base_vector.x = 0;
	base_vector.y = -1;
	base_vector.z = 0;
	rotate_camera(camera, angle, base_vector);
}

void			pixel_put(t_object_3d *nearest_obj,
	t_vector_3d nearest_intersection, int w, int h)
{
	t_vector_3d color;

	if (nearest_obj != NULL)
	{
		color = vector_multiplication(nearest_obj->color,
			phong_light_amplifier(nearest_obj,
				nearest_intersection));
		my_mlx_pixel_put(g_screen.img,
w, h, (int)((int)min_pos_number(255, color.x) * 65536 + (int)min_pos_number(255,
	color.y) * 256 + (int)min_pos_number(255, color.z)));
	}
	else
		my_mlx_pixel_put(g_screen.img, w, h, 0);
}
