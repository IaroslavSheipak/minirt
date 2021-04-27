/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_cylinder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suzumaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 19:40:27 by suzumaki          #+#    #+#             */
/*   Updated: 2021/03/25 12:20:48 by suzumaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

t_vector_3d		get_cylinder_normal(t_cylinder *cylinder,
	t_vector_3d intersection_point)
{
	double		t;
	t_vector_3d	pt;
	t_vector_3d	surface_normal;

	t = ft_dot(vector_subtract(intersection_point, cylinder->center),
	vector_normalize(cylinder->orientation));
	pt = vector_sum(cylinder->center,
	vector_scalar_multiplication(cylinder->orientation, t));
	surface_normal = vector_normalize(vector_subtract(intersection_point, pt));
	return (surface_normal);
}

static int		check_cylinder_root(double root, const t_cylinder *data,
	t_vector_3d ray_start_point, t_vector_3d ray_direction)
{
	double	m;

	if (root < 0)
		return (0);
	m = ft_dot(ray_direction,
	vector_scalar_multiplication(data->orientation,
	root)) + ft_dot(vector_subtract(ray_start_point,
	data->center), data->orientation);
	if (m >= -data->height / 2 && m <= data->height / 2)
		return (1);
	return (0);
}

static double	calculate_distance(double *mas,
	const t_cylinder *cylinder,
		t_vector_3d ray_start_point, t_vector_3d ray_direction)
{
	double distance;

	distance = -1;
	if (check_cylinder_root(
			(-mas[1] - sqrt(mas[3])) / (2 * mas[0]),
			cylinder,
			ray_start_point,
			ray_direction))
		distance = ((-mas[1] - sqrt(mas[3])) / (2 * mas[0]));
	else if (check_cylinder_root(
			(-mas[1] + sqrt(mas[3])) / (2 * mas[0]),
			cylinder,
			ray_start_point,
			ray_direction))
		distance = ((-mas[1] + sqrt(mas[3])) / (2 * mas[0]));
	free(mas);
	return (distance);
}

int				intersect_cylinder(const t_cylinder *data,
	t_vector_3d ray_start_point,
	t_vector_3d ray_direction, t_vector_3d *intersection_point)
{
	double	a;
	double	b;
	double	c;
	double	d;
	double	distance;

	a = ft_dot(ray_direction, ray_direction) -
	pow(ft_dot(ray_direction, data->orientation), 2);
	b = 2 * (ft_dot(ray_direction,
	vector_subtract(ray_start_point, data->center)) - ft_dot(ray_direction,
	data->orientation) * ft_dot(vector_subtract(ray_start_point,
	data->center), data->orientation));
	c = ft_dot(vector_subtract(ray_start_point, data->center),
	vector_subtract(ray_start_point, data->center))
	- pow(data->diameter / 2, 2) - pow(ft_dot(vector_subtract(ray_start_point,
	data->center), data->orientation), 2);
	if ((d = b * b - 4 * a * c) < 0)
		return (0);
	distance = calculate_distance(create_array(a, b, c, d), data,
	ray_start_point, ray_direction);
	if (distance < 0)
		return (0);
	*intersection_point = vector_sum(ray_start_point,
		vector_scalar_multiplication(ray_direction, distance));
	return (1);
}

t_object_3d		new_cylinder(t_vector_3d center, t_vector_3d orientation,
	t_cylinder_params params, t_vector_3d color)
{
	t_object_3d	object;
	t_cylinder	*cylinder;

	if ((cylinder = malloc(sizeof(t_cylinder))) == NULL)
	{
		printf("cy allocate failed\n");
		exit(0);
	}
	cylinder->orientation = orientation;
	cylinder->center = center;
	cylinder->height = params.height;
	cylinder->diameter = params.diameter;
	object.color = color;
	object.data = cylinder;
	object.intersect = intersect_cylinder;
	object.get_normal_vector = get_cylinder_normal;
	return (object);
}
