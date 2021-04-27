/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suzumaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 19:38:36 by suzumaki          #+#    #+#             */
/*   Updated: 2021/03/29 20:21:04 by suzumaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	parse_file(char *name)
{
	char	*line;
	int		fd;
	int		n;

	if ((fd = open(name, O_RDONLY)) < 1 ||
	(ft_strnstr(name, ".rt\0", ft_strlen(name)) == NULL))
		manage_error("file not readable or not .rt");
	n = 1;
	g_objs = NULL;
	g_camera_list = NULL;
	while (n > 0)
	{
		n = get_next_line(fd, &line);
		if (n > -1)
		{
			parse_line(line);
			free(line);
		}
		if (n < 0)
			manage_error("file not readable or not .rt");
	}
	close(fd);
}

char	*skip_space(char *line)
{
	if (*line == '\0')
		return (line);
	while (*line == '-' || *line == '.' || (*line >= '0' && *line <= '9'))
		line++;
	while (*line && !(*line == '-' || *line == '.' ||
	(*line >= '0' && *line <= '9')))
		line++;
	return (line);
}

char	*parse_vector(char *line, t_vector_3d *params)
{
	while (!(*line == '-' || *line == '.' || (*line >= '0' && *line <= '9')))
		line++;
	params->x = ft_atof(line);
	line = skip_space(line);
	params->y = ft_atof(line);
	line = skip_space(line);
	params->z = ft_atof(line);
	if (*line != '\0')
		line = skip_space(line);
	return (line);
}

void	parse_line(char *line)
{
	if (*line == '\0')
		return ;
	else if (ft_strnstr(line, "sp ", ft_strlen(line)))
		ft_objadd_back(&g_objs, ft_objnew(manage_sp(line)));
	else if (ft_strnstr(line, "pl ", ft_strlen(line)))
		ft_objadd_back(&g_objs, ft_objnew(manage_pl(line)));
	else if (ft_strnstr(line, "tr ", ft_strlen(line)))
		ft_objadd_back(&g_objs, ft_objnew(manage_tr(line)));
	else if (ft_strnstr(line, "sq ", ft_strlen(line)))
		ft_objadd_back(&g_objs, ft_objnew(manage_sq(line)));
	else if (ft_strnstr(line, "cy ", ft_strlen(line)))
		ft_objadd_back(&g_objs, ft_objnew(manage_cy(line)));
	else if (ft_strnstr(line, "l ", ft_strlen(line)))
		manage_l(line);
	else if (ft_strnstr(line, "c ", ft_strlen(line)))
		manage_c(line);
	else if (ft_strnstr(line, "R ", ft_strlen(line)))
		manage_r(line);
	else if (ft_strnstr(line, "A ", ft_strlen(line)))
		manage_a(line);
	else
		manage_error("wrong identifier of figures");
}
