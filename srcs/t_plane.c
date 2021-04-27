/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_plane.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suzumaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 19:40:36 by suzumaki          #+#    #+#             */
/*   Updated: 2021/03/25 12:21:25 by suzumaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

t_vector_3d	get_plane_normal(t_plane *plane, t_vector_3d intersection_point)
{
	return (vector_normalize(vector_multiplication(plane->orientation,
	intersection_point)));
}

int			intersect_plane(const t_plane *data, t_vector_3d ray_start_point,
	t_vector_3d ray_direction, t_vector_3d *intersection_point)
{
	double distance;
	double dv;

	dv = ft_dot(ray_direction, data->orientation);
	distance = -1;
	if (dv != 0.0)
		distance = -ft_dot(vector_subtract(ray_start_point,
		data->coords), data->orientation) / dv;
	if (distance < 0.0)
		return (0);
	intersection_point->x = ray_start_point.x + distance * ray_direction.x;
	intersection_point->y = ray_start_point.y + distance * ray_direction.y;
	intersection_point->z = ray_start_point.z + distance * ray_direction.z;
	return (1);
}

t_object_3d	new_plane(t_vector_3d coords,
	t_vector_3d color, t_vector_3d orientation)
{
	t_object_3d	object;
	t_plane		*plane;

	if ((plane = malloc(sizeof(t_plane))) == NULL)
	{
		printf("pl allocate failed");
		exit(0);
	}
	plane->coords = coords;
	object.color = color;
	plane->orientation = orientation;
	object.data = plane;
	object.intersect = intersect_plane;
	object.get_normal_vector = get_plane_normal;
	return (object);
}
