/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suzumaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 19:37:27 by suzumaki          #+#    #+#             */
/*   Updated: 2021/03/29 21:21:12 by suzumaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# define BMP_FILE_HEADER_SIZE 14
# define BMP_INFO_HEADER_SIZE 40

# include "../gnl/get_next_line.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "../headers/camera.h"
# include "../headers/object.h"
# include "../headers/light.h"
# include "../minilibx_mms_20200219//mlx.h"
# include "vector.h"

typedef struct	s_sphere
{
	t_vector_3d	center;
	double		radius;
	t_vector_3d	color;
}				t_sphere;

typedef struct	s_plane
{
	t_vector_3d	coords;
	t_vector_3d	orientation;
	t_vector_3d	color;
}				t_plane;

typedef struct	s_triangle
{
	t_vector_3d	first_point;
	t_vector_3d	second_point;
	t_vector_3d	third_point;
}				t_triangle;

typedef struct	s_square
{
	t_vector_3d	center;
	t_vector_3d	orientation;
	double		size;
	t_vector_3d	ps[4];
}				t_square;

typedef struct	s_cylinder
{
	t_vector_3d	center;
	t_vector_3d	orientation;
	double		diameter;
	double		height;
}				t_cylinder;

typedef struct	s_data {
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

typedef struct	s_screen
{
	int			width;
	int			height;
	void		*mlx;
	void		*mlx_window;
	t_data		*img;
}				t_screen;

typedef struct	s_ambient
{
	t_vector_3d	color;
	double		ratio;
}				t_ambient;

typedef struct	s_cylinder_params
{
	double		height;
	double		diameter;
}				t_cylinder_params;

t_light_list	*g_lights;
t_object_list	*g_objs;
t_screen		g_screen;
t_ambient		g_ambient;
int				g_is_diffuse_on;
double			vector_len(t_vector_3d a);
t_vector_3d		create_vector3d(double x, double y, double z);
t_vector_3d		vector_sum(t_vector_3d a, t_vector_3d b);
t_quaternion	create_quaternion(double a, double x, double y, double z);
t_quaternion	vector3d_to_quaternion(t_vector_3d vec);
t_vector_3d		quaternion_to_vector3d(t_quaternion quat);
double			quaternion_magnitude(t_quaternion quaternion);
t_quaternion	quaternion_invert(t_quaternion quaternion);
t_quaternion	quaternion_normalize(t_quaternion quaternion);
t_quaternion	quaternion_set_rotation(double angle, t_vector_3d axis);
t_quaternion	quaternion_product(t_quaternion a, t_quaternion b);
t_quaternion	quaternion_compose_rotation(t_quaternion first,
				t_quaternion second);
t_quaternion	quaternion_rotate(t_quaternion rotation, t_vector_3d vector);
t_vector_3d		vector_scalar_multiplication(t_vector_3d vector, double scalar);
char			*parse_vector(char *line, t_vector_3d *params);
t_object_3d		manage_sp(char *line);
int				intersect_sphere(const t_sphere *data,
				t_vector_3d ray_start_point,
				t_vector_3d ray_direction,
				t_vector_3d *intersection_point);
void			draw_scene();
char			*skip_space(char *line);
void			parse_line(char *line);
t_vector_3d		vector_normalize(t_vector_3d a);
double			ft_dot(t_vector_3d a, t_vector_3d b);
t_vector_3d		vector_subtract(t_vector_3d a, t_vector_3d b);
t_object_3d		new_sphere(t_vector_3d center,
				t_vector_3d color, double radius);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
t_vector_3d		get_sphere_normal(t_sphere *sphere,
				t_vector_3d intersection_point);
t_vector_3d		vector_multiplication(t_vector_3d a, t_vector_3d b);
t_vector_3d		vector_scalar_division(t_vector_3d vector, double scalar);
t_vector_3d		get_plane_normal(t_plane *plane,
				t_vector_3d intersection_point);
int				intersect_plane(const t_plane *data,
				t_vector_3d ray_start_point,
				t_vector_3d ray_direction, t_vector_3d *intersection_point);
t_object_3d		new_plane(t_vector_3d coords,
				t_vector_3d color, t_vector_3d orientation);
t_object_3d		manage_pl(char *line);
t_object_3d		manage_tr(char *line);
t_vector_3d		vector_cross(t_vector_3d a, t_vector_3d b);
t_object_3d		new_triangle(t_vector_3d first_point,
				t_vector_3d second_point,
				t_vector_3d third_point, t_vector_3d color);
t_object_3d		manage_sq(char *line);
t_vector_3d		get_square_normal(t_square *square,
				t_vector_3d intersection_point);
int				intersect_square(const t_square *data,
				t_vector_3d ray_start_point,
				t_vector_3d ray_direction,
				t_vector_3d *intersection_point);
t_object_3d		new_square(t_vector_3d center,
				t_vector_3d orientation,
				double size, t_vector_3d color);
t_object_3d		manage_cy(char *line);
t_object_3d		new_cylinder(t_vector_3d center,
				t_vector_3d orientation,
				t_cylinder_params params, t_vector_3d color);
int				intersect_cylinder(const t_cylinder *data,
				t_vector_3d ray_start_point,
				t_vector_3d ray_direction,
				t_vector_3d *intersection_point);
t_vector_3d		get_cylinder_normal(t_cylinder *cylinder,
				t_vector_3d intersection_point);
double			min_pos_number(double a, double b);
void			manage_r(char *line);
void			manage_c(char *line);
void			manage_a(char *line);
void			bitmap_file_header(int padding_size, int fd);
void			bitmap_info_header(int fd);
void			create_bmp_image(char *file_name);
int				intersect_triangle(const t_triangle *data,
				t_vector_3d ray_start_point,
				t_vector_3d ray_direction,
				t_vector_3d *intersection_point);
void			find_nearest_to_camera(t_vector_3d ray,
				t_object_3d **nearest_obj,
				t_vector_3d *nearest_intersection_point);
t_vector_3d		phong_light_amplifier(const t_object_3d *object,
				t_vector_3d point_position);
t_vector_3d		set_normal_on_camera(t_vector_3d base_normal,
				t_vector_3d point_position);
int				check_for_obstacles(t_vector_3d start_point,
				t_vector_3d end_point);
void			parse_file(char *name);
void			manage_error(char	*line);
double			*create_array(double a, double b, double c, double d);
int				cross_exit(void);
void			check_sp(t_vector_3d vector);
void			check_screen(void);
void			check_parser(void);
void			check_for_save(int argc, char *argv[]);
void			pixel_put(t_object_3d *nearest_obj,
				t_vector_3d nearest_intersection, int w, int h);
#endif
