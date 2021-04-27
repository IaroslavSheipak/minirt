/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suzumaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 10:00:59 by suzumaki          #+#    #+#             */
/*   Updated: 2021/03/25 12:21:03 by suzumaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

double	*create_array(double a, double b, double c, double d)
{
	double *arr;

	arr = malloc(4 * sizeof(double));
	arr[0] = a;
	arr[1] = b;
	arr[2] = c;
	arr[3] = d;
	return (arr);
}

int		cross_exit(void)
{
	exit(1);
}

void	check_screen(void)
{
	int x;
	int y;

	mlx_get_screen_size(g_screen.mlx, &x, &y);
	if (g_screen.width > x)
		g_screen.width = x;
	if (g_screen.height > y)
		g_screen.height = y;
}

void	check_parser(void)
{
	if (g_screen.width < 0 || g_screen.height < 0)
		manage_error("screen resolution wrong");
}

void	check_for_save(int argc, char *argv[])
{
	if (argc == 3 && ft_strncmp("--save", argv[2], 7) == 0)
	{
		create_bmp_image("screenshot.bmp");
		exit(0);
	}
}
