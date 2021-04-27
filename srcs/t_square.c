/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_square.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suzumaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 19:40:56 by suzumaki          #+#    #+#             */
/*   Updated: 2021/03/29 20:15:32 by suzumaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

t_vector_3d			get_square_normal(t_square *square,
	t_vector_3d intersection_point)
{
	(void)intersection_point;
	return (square->orientation);
}

int					intersect_square(const t_square *data,
	t_vector_3d ray_start_point,
	t_vector_3d ray_direction,
	t_vector_3d *intersection_point)
{
	t_vector_3d		target_c[3];
	t_triangle		test;

	target_c[0] = (data->ps)[0];
	target_c[1] = (data->ps)[1];
	target_c[2] = (data->ps)[2];
	test.first_point = target_c[0];
	test.second_point = target_c[1];
	test.third_point = target_c[2];
	if (intersect_triangle(&test, ray_start_point, ray_direction,
		intersection_point))
		return (1);
	test.second_point = (data->ps)[3];
	return (intersect_triangle(&test, ray_start_point, ray_direction,
		intersection_point));
}

static t_vector_3d	calc_y(double size,
	t_vector_3d orientation, t_vector_3d base_dir_x)
{
	t_vector_3d new_ort;

	new_ort = vector_cross(vector_normalize(base_dir_x), orientation);
	return (vector_scalar_multiplication(vector_normalize(new_ort), size / 2));
}

static t_vector_3d	calc_x(double size, t_vector_3d base_dir_x)
{
	return (vector_scalar_multiplication(vector_normalize(base_dir_x),
		size / 2));
}

t_object_3d			new_square(t_vector_3d center,
	t_vector_3d orientation, double size, t_vector_3d color)
{
	t_object_3d	object;
	t_square	*sqr;
	t_vector_3d	base_dir_x;
	t_vector_3d	base_dir_y;

	if ((sqr = malloc(sizeof(t_square))) == NULL)
		manage_error("sq allocate failed");
	sqr->center = center;
	sqr->orientation = orientation;
	sqr->size = size;
	object.color = color;
	object.data = sqr;
	object.intersect = intersect_square;
	object.get_normal_vector = get_square_normal;
	base_dir_x = vector_cross(create_vector3d(0, 0, 1), orientation);
	if (vector_len(base_dir_x) == 0)
		base_dir_x = vector_cross(create_vector3d(0, 1, 0), orientation);
	base_dir_y = calc_y(size, orientation, base_dir_x);
	base_dir_x = calc_x(size, base_dir_x);
	(sqr->ps)[0] = vector_sum(vector_sum(center, base_dir_x), base_dir_y);
	(sqr->ps)[1] = vector_sum(vector_subtract(center, base_dir_x), base_dir_y);
	(sqr->ps)[2] = vector_subtract(vector_subtract(center, base_dir_x),
		base_dir_y);
	(sqr->ps)[3] = vector_subtract(vector_sum(center, base_dir_x), base_dir_y);
	return (object);
}
