/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suzumaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 19:36:32 by suzumaki          #+#    #+#             */
/*   Updated: 2021/03/21 19:36:35 by suzumaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHARIKI_CAMERA_H
# define SHARIKI_CAMERA_H

# include "minirt.h"
# include "vector.h"

typedef struct				s_camera
{
	t_vector_3d				coords;
	t_quaternion			rotation;
	double					fov;
}							t_camera;

typedef struct				s_camera_list
{
	t_camera				camera;
	struct s_camera_list	*next;
	struct s_camera_list	*prev;
}							t_camera_list;
t_camera_list				*g_camera_list;

void						rotate_camera(t_camera *camera,
	double angle, t_vector_3d base_vector);
void						move_camera(t_camera *camera,
	t_vector_3d base_direction, double distance);
void						manage_l(char *line);
t_camera_list				*ft_camnew(t_camera camera);
t_camera_list				*ft_camlast(t_camera_list *lst);
void						ft_camadd_back(t_camera_list **lst,
								t_camera_list *new);
void						move_camera_forward(t_camera *camera,
								double distance);
void						move_camera_backward(t_camera *camera,
								double distance);
void						move_camera_up(t_camera *camera, double distance);
void						move_camera_down(t_camera *camera, double distance);
void						move_camera_left(t_camera *camera, double distance);
void						move_camera_right(t_camera *camera,
								double distance);
void						roll_camera(t_camera *camera, double angle);
void						yaw_camera(t_camera *camera, double angle);
void						pitch_camera(t_camera *camera, double angle);
t_camera					new_camera(double fov, t_vector_3d v,
								t_vector_3d coords);
t_vector_3d					create_ray(t_camera camera, int w, int h);

#endif
