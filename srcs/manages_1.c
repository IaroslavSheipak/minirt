/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manages_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suzumaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 19:37:03 by suzumaki          #+#    #+#             */
/*   Updated: 2021/03/26 13:56:02 by suzumaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

t_object_3d	manage_sp(char *line)
{
	t_vector_3d	center;
	double		radius;
	t_vector_3d	color;

	line = skip_space(line);
	line = parse_vector(line, &center);
	radius = ft_atof(line) / 2;
	line = skip_space(line);
	parse_vector(line, &color);
	return (new_sphere(center,
		color, radius));
}

t_object_3d	manage_pl(char *line)
{
	t_vector_3d	coords;
	t_vector_3d	orientation;
	t_vector_3d	color;

	line = skip_space(line);
	line = parse_vector(line, &coords);
	line = parse_vector(line, &orientation);
	parse_vector(line, &color);
	if (vector_len(orientation) != 1)
		manage_error("orientation of plane not normalized");
	return (new_plane(coords,
		color, orientation));
}

t_object_3d	manage_tr(char *line)
{
	t_vector_3d first_point;
	t_vector_3d second_point;
	t_vector_3d third_point;
	t_vector_3d color;

	line = skip_space(line);
	line = parse_vector(line, &first_point);
	line = parse_vector(line, &second_point);
	line = parse_vector(line, &third_point);
	parse_vector(line, &color);
	return (new_triangle(first_point,
		second_point, third_point, color));
}

t_object_3d	manage_sq(char *line)
{
	t_vector_3d	center;
	t_vector_3d	orientation;
	t_vector_3d	color;
	double		size;

	line = skip_space(line);
	line = parse_vector(line, &center);
	line = parse_vector(line, &orientation);
	size = ft_atof(line);
	line = skip_space(line);
	parse_vector(line, &color);
	if (vector_len(orientation) - 1 > 0.03 ||
		vector_len(orientation) - 1 < -0.03)
		manage_error("orientation of square not normalized");
	return (new_square(center,
		orientation, size, color));
}

t_object_3d	manage_cy(char *line)
{
	t_vector_3d			center;
	t_vector_3d			orientation;
	t_vector_3d			color;
	t_cylinder_params	params;

	line = skip_space(line);
	line = parse_vector(line, &center);
	line = parse_vector(line, &orientation);
	params.diameter = ft_atof(line);
	line = skip_space(line);
	params.height = ft_atof(line);
	line = skip_space(line);
	parse_vector(line, &color);
	if (vector_len(orientation) != 1)
		manage_error("orientation of cy not normalized");
	return (new_cylinder(center,
		orientation, params, color));
}
