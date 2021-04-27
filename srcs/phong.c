/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suzumaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 19:39:21 by suzumaki          #+#    #+#             */
/*   Updated: 2021/03/28 17:52:00 by suzumaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

static t_vector_3d	add_light(t_vector_3d diffuse_amplifier, t_light light,
	double scalar_diffuse_amplifier)
{
	t_vector_3d prom;
	t_vector_3d calc_light;

	light.color = vector_scalar_division(light.color, 255);
	calc_light = vector_scalar_multiplication(light.color, light.ratio);
	prom = vector_scalar_multiplication(calc_light, scalar_diffuse_amplifier);
	return (vector_sum(diffuse_amplifier, prom));
}

t_vector_3d			calculate_diffuse(const t_object_3d object,
	t_vector_3d point_position)
{
	t_light_list		*light;
	double				scalar_diffuse_amplifier;
	t_vector_3d			diffuse_amplifier;
	t_vector_3d			normal;
	t_vector_3d			out_point;

	diffuse_amplifier = create_vector3d(0, 0, 0);
	light = g_lights;
	normal = object.get_normal_vector(object.data, point_position);
	normal = set_normal_on_camera(normal, point_position);
	out_point = vector_sum(point_position,
		vector_scalar_multiplication(normal, 0.001));
	while (light != NULL)
	{
		if (check_for_obstacles(light->light.coords, out_point) == 0)
		{
			if ((scalar_diffuse_amplifier = ft_dot(normal,
vector_normalize(vector_subtract(light->light.coords, point_position)))) > 0.0)
				diffuse_amplifier = add_light(diffuse_amplifier,
					light->light, scalar_diffuse_amplifier);
		}
		light = light->next;
	}
	return (diffuse_amplifier);
}

static double		min(double a, double b)
{
	if (a < b)
		return (a);
	return (b);
}

static t_vector_3d	compress_amplifier(t_vector_3d amplifier)
{
	amplifier.x = min(1, amplifier.x);
	amplifier.y = min(1, amplifier.y);
	amplifier.z = min(1, amplifier.z);
	return (amplifier);
}

t_vector_3d			phong_light_amplifier(const
t_object_3d *object, t_vector_3d point_position)
{
	t_vector_3d	resulted_amplifier;

	resulted_amplifier = create_vector3d(0, 0, 0);
	resulted_amplifier = vector_sum(resulted_amplifier,
	create_vector3d(g_ambient.color.x * g_ambient.ratio / 255,
		g_ambient.color.y * g_ambient.ratio / 255,
			g_ambient.color.z * g_ambient.ratio / 255));
	if (g_is_diffuse_on)
	{
		resulted_amplifier = vector_sum(resulted_amplifier,
		calculate_diffuse(*object, point_position));
	}
	return (compress_amplifier(resulted_amplifier));
}
