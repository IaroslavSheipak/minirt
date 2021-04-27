/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manages_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suzumaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 19:37:12 by suzumaki          #+#    #+#             */
/*   Updated: 2021/03/28 18:04:09 by suzumaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/camera.h"

void	manage_c(char *line)
{
	t_vector_3d	coords;
	t_vector_3d	rotation;
	double		fov;

	line = skip_space(line);
	line = parse_vector(line, &coords);
	line = parse_vector(line, &rotation);
	if (vector_len(rotation) - 1 > 0.05 || vector_len(rotation) - 1 < -0.05)
		manage_error("orientation of camera not normalized");
	fov = ft_atof(line);
	ft_camadd_back(&g_camera_list,
		ft_camnew(new_camera(fov, rotation, coords)));
}

void	manage_l(char *line)
{
	t_vector_3d	coords;
	t_vector_3d	color;
	double		fov;

	line = skip_space(line);
	line = parse_vector(line, &coords);
	fov = ft_atof(line);
	line = skip_space(line);
	parse_vector(line, &color);
	ft_lghtadd_back(&g_lights,
		ft_lghtnew(new_light(fov, color, coords)));
}

void	manage_r(char *line)
{
	line = skip_space(line);
	g_screen.width = ft_atoi(line);
	line = skip_space(line);
	g_screen.height = ft_atoi(line);
	if (g_screen.width < 1 || g_screen.height < 1)
		manage_error("wrong resolution");
}

void	manage_a(char *line)
{
	line = skip_space(line);
	g_ambient.ratio = ft_atof(line);
	line = skip_space(line);
	parse_vector(line, &g_ambient.color);
}
