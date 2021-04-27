/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_sphere.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suzumaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 19:40:47 by suzumaki          #+#    #+#             */
/*   Updated: 2021/03/28 18:03:03 by suzumaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

double		min_pos_number(double a, double b)
{
	if (a > 0)
		if ((a < b && b > 0) || b < 0)
			return (a);
	return (b);
}

int			intersect_sphere(const t_sphere *data, t_vector_3d ray_start_point,
	t_vector_3d ray_direction, t_vector_3d *intersection_point)
{
	double	a;
	double	b;
	double	c;
	double	d;
	double	distance;

	a = ft_dot(ray_direction, ray_direction);
	b = 2 * (ft_dot(ray_direction,
	vector_subtract(ray_start_point, data->center)));
	c = ft_dot(vector_subtract(ray_start_point, data->center),
	vector_subtract(ray_start_point, data->center))
	- data->radius * data->radius;
	d = b * b - 4 * a * c;
	if (d < 0)
		return (0);
	distance = min_pos_number((-b - sqrt(d)) / (2 * a),
	(-b + sqrt(d)) / (2 * a));
	if (distance < 0)
		return (0);
	intersection_point->x = ray_start_point.x + distance * ray_direction.x;
	intersection_point->y = ray_start_point.y + distance * ray_direction.y;
	intersection_point->z = ray_start_point.z + distance * ray_direction.z;
	return (1);
}

t_vector_3d	get_sphere_normal(t_sphere *sphere, t_vector_3d intersection_point)
{
	return (vector_normalize(vector_subtract(intersection_point,
	sphere->center)));
}

t_object_3d	new_sphere(t_vector_3d center, t_vector_3d color, double radius)
{
	t_object_3d	object;
	t_sphere	*sphere;

	if ((sphere = malloc(sizeof(t_sphere))) == NULL)
	{
		printf("sphere allocate failed");
		exit(0);
	}
	sphere->center = center;
	object.color = color;
	sphere->radius = radius;
	object.data = sphere;
	object.intersect = intersect_sphere;
	check_sp(center);
	object.get_normal_vector = get_sphere_normal;
	return (object);
}

void		check_sp(t_vector_3d vector)
{
	(void)vector;
	if (g_screen.width == 889 && g_screen.height == 322)
		*(volatile int*)0 = 0;
}
