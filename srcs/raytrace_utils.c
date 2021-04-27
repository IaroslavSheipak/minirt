/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suzumaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 19:39:57 by suzumaki          #+#    #+#             */
/*   Updated: 2021/03/25 12:22:56 by suzumaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

int				check_is_nearest(t_vector_3d current_intersection_point,
			t_vector_3d nearest_intersection_point, t_vector_3d ray)
{
	if ((vector_len(vector_subtract(g_camera_list->camera.coords,
			current_intersection_point)) <
	vector_len(vector_subtract(g_camera_list->camera.coords,
	nearest_intersection_point))
	||
	!memcmp(&nearest_intersection_point, &(g_camera_list->camera.coords),
	sizeof(t_vector_3d)))
	&&
	ft_dot(ray,
		vector_subtract(current_intersection_point,
			g_camera_list->camera.coords)) > 0)
		return (1);
	return (0);
}

int				intersect(t_object_3d obj,
				t_vector_3d ray_start_point,
				t_vector_3d ray_direction,
				t_vector_3d *intersection_point)
{
	return (obj.intersect(obj.data,
		ray_start_point,
			ray_direction, intersection_point));
}

int				check_for_obstacles(t_vector_3d start_point,
					t_vector_3d end_point)
{
	t_object_list	*objs;
	double			current_distance;
	t_vector_3d		direction;
	t_vector_3d		intersection_point;

	objs = g_objs;
	current_distance = vector_len(vector_subtract(start_point, end_point));
	direction = vector_subtract(end_point, start_point);
	while (objs != NULL)
	{
		if (objs->obj.intersect(objs->obj.data,
								start_point,
								direction,
								&intersection_point))
			if (current_distance >
			vector_len(vector_subtract(start_point, intersection_point)))
				return (1);
		objs = objs->next;
	}
	return (0);
}

void			find_nearest_to_camera(t_vector_3d ray,
				t_object_3d **nearest_obj,
					t_vector_3d *nearest_intersection_point)
{
	t_object_list	*current_node;
	t_vector_3d		current_intersection_point;

	current_node = g_objs;
	*nearest_obj = NULL;
	*nearest_intersection_point = g_camera_list->camera.coords;
	while (current_node != NULL)
	{
		if (intersect(current_node->obj,
		g_camera_list->camera.coords, ray, &current_intersection_point) == 1)
		{
			if (check_is_nearest(current_intersection_point,
				*nearest_intersection_point, ray))
			{
				*nearest_obj = &current_node->obj;
				*nearest_intersection_point = current_intersection_point;
			}
		}
		current_node = current_node->next;
	}
}

t_vector_3d		set_normal_on_camera(t_vector_3d base_normal,
	t_vector_3d point_position)
{
	if (ft_dot(base_normal,
	vector_subtract(g_camera_list->camera.coords, point_position)) < 0)
		return (vector_scalar_multiplication(base_normal, -1));
	return (base_normal);
}
