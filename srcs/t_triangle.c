/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_triangle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suzumaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 19:41:07 by suzumaki          #+#    #+#             */
/*   Updated: 2021/03/26 15:23:32 by suzumaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

t_vector_3d	get_triangle_normal(t_triangle *triangle,
								t_vector_3d intersection_point)
{
	(void)intersection_point;
	return (vector_normalize(vector_cross(vector_subtract(triangle->third_point,
	triangle->first_point),
		vector_subtract(triangle->second_point, triangle->first_point))));
}

int			intersect_triangle(const t_triangle *data,
	t_vector_3d ray_start_point,
	t_vector_3d ray_direction, t_vector_3d *intersection_point)
{
	t_vector_3d		e[4];
	double			dist;
	double			det;
	double			u;
	double			v;

	e[0] = vector_subtract((data->second_point), (data->first_point));
	e[1] = vector_subtract((data->third_point), (data->first_point));
	e[2] = vector_cross(ray_direction, e[1]);
	det = ft_dot(e[0], e[2]);
	if (det == 0)
		return (0);
	det = 1 / det;
	e[3] = vector_subtract(ray_start_point, (data->first_point));
	u = ft_dot(e[3], e[2]) * det;
	if (u < 0 || u > 1)
		return (0);
	e[2] = vector_cross(e[3], e[0]);
	v = ft_dot(ray_direction, e[2]) * det;
	if (v < 0 || u + v > 1)
		return (0);
	dist = ft_dot(e[1], e[2]) * det;
	*intersection_point = vector_sum(ray_start_point,
		vector_scalar_multiplication(ray_direction, dist));
	return (1);
}

t_object_3d	new_triangle(t_vector_3d first_point,
	t_vector_3d second_point, t_vector_3d third_point, t_vector_3d color)
{
	t_object_3d	object;
	t_triangle	*triangle;

	if ((triangle = malloc(sizeof(t_triangle))) == NULL)
	{
		printf("tr allocate fail");
		exit(0);
	}
	triangle->first_point = first_point;
	triangle->second_point = second_point;
	triangle->third_point = third_point;
	object.color = color;
	object.data = triangle;
	object.intersect = intersect_triangle;
	object.get_normal_vector = get_triangle_normal;
	return (object);
}
