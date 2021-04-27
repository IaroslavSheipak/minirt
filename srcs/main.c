/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtx_sp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suzumaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 19:40:06 by suzumaki          #+#    #+#             */
/*   Updated: 2021/03/29 20:20:52 by suzumaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

t_vector_3d		create_ray(t_camera camera, int w, int h)
{
	t_vector_3d	ray;

	ray.x = w + 0.5 - g_screen.width / 2.0;
	ray.y = -(h + 0.5 - g_screen.height / 2.0);
	ray.z = (-g_screen.height) / (2.0 * tan(camera.fov / 2.0 / 57.2958));
	ray = vector_normalize(ray);
	return (ray);
}

void			draw_scene(void)
{
	int				window[2];
	t_object_3d		*nearest_obj;
	t_vector_3d		nearest_intersection;

	window[0] = 0;
	while (window[0] < g_screen.height)
	{
		window[1] = 0;
		while (window[1] < g_screen.width)
		{
			find_nearest_to_camera(
		quaternion_to_vector3d(quaternion_rotate(g_camera_list->camera.rotation,
			create_ray(g_camera_list->camera, window[1], window[0]))),
				&nearest_obj, &nearest_intersection);
			pixel_put(nearest_obj, nearest_intersection, window[1], window[0]);
			window[1]++;
		}
		window[0]++;
	}
	mlx_put_image_to_window(g_screen.mlx,
	g_screen.mlx_window, g_screen.img->img, 0, 0);
}

static int		bind_camera2(int keycode)
{
	if (keycode == 14 && g_camera_list != NULL)
		roll_camera(&g_camera_list->camera, -0.2);
	else if (keycode == 12 && g_camera_list != NULL)
		roll_camera(&g_camera_list->camera, 0.2);
	else if (keycode == 1 && g_camera_list != NULL)
		pitch_camera(&g_camera_list->camera, 0.2);
	else if (keycode == 13 && g_camera_list != NULL)
		pitch_camera(&g_camera_list->camera, -0.2);
	else if (keycode == 0 && g_camera_list != NULL)
		yaw_camera(&g_camera_list->camera, -0.2);
	else if (keycode == 2 && g_camera_list != NULL)
		yaw_camera(&g_camera_list->camera, 0.2);
	else if (keycode == 257 && g_camera_list != NULL)
		g_camera_list = g_camera_list->next;
	else if (keycode == 48)
		create_bmp_image("screenshot.bmp");
	else if (keycode == 53)
		exit(1);
	if (g_camera_list != NULL)
		draw_scene();
	return (1);
}

int				bind_camera_movements(int keycode)
{
	if (keycode == 126 && g_camera_list != NULL)
		move_camera_forward(&g_camera_list->camera, 10);
	else if (keycode == 125 && g_camera_list != NULL)
		move_camera_backward(&g_camera_list->camera, 10);
	else if (keycode == 124 && g_camera_list != NULL)
		move_camera_right(&g_camera_list->camera, 10);
	else if (keycode == 123 && g_camera_list != NULL)
		move_camera_left(&g_camera_list->camera, 10);
	else if (keycode == 258 && g_camera_list != NULL)
		move_camera_up(&g_camera_list->camera, 10);
	else if (keycode == 269 && g_camera_list != NULL)
		move_camera_down(&g_camera_list->camera, 10);
	bind_camera2(keycode);
	return (1);
}

int				main(int argc, char *argv[])
{
	t_data			img;
	t_camera_list	*tmp;

	parse_file(argv[1]);
	check_parser();
	g_screen.mlx = mlx_init();
	check_screen();
	img.img = mlx_new_image(g_screen.mlx, g_screen.width, g_screen.height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
		&img.line_length, &img.endian);
	g_screen.mlx_window = mlx_new_window(g_screen.mlx,
		g_screen.width, g_screen.height, "miniRT");
	g_screen.img = &img;
	tmp = g_camera_list;
	while (tmp != NULL && tmp->next != NULL)
		tmp = tmp->next;
	if (g_camera_list != NULL)
		tmp->next = g_camera_list;
	if (g_camera_list != NULL)
		draw_scene();
	check_for_save(argc, argv);
	mlx_hook(g_screen.mlx_window, 17, 1L << 0, &cross_exit, NULL);
	mlx_key_hook(g_screen.mlx_window, bind_camera_movements, NULL);
	mlx_loop(g_screen.mlx);
}
