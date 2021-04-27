/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_to_bmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suzumaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 19:40:18 by suzumaki          #+#    #+#             */
/*   Updated: 2021/03/25 12:18:28 by suzumaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

void	bitmap_file_header(int padding_size, int fd)
{
	unsigned char	*file_header;
	int				file_size;

	if (!(file_header = ft_calloc(BMP_FILE_HEADER_SIZE, sizeof(unsigned char))))
		exit(0);
	file_size = BMP_FILE_HEADER_SIZE + BMP_INFO_HEADER_SIZE
				+ (g_screen.img->bits_per_pixel / 8 *
				g_screen.width + padding_size) * g_screen.height;
	file_header[0] = (unsigned char)('B');
	file_header[1] = (unsigned char)('M');
	file_header[2] = (unsigned char)(file_size);
	file_header[3] = (unsigned char)(file_size >> 8);
	file_header[4] = (unsigned char)(file_size >> 16);
	file_header[5] = (unsigned char)(file_size >> 24);
	file_header[10] = (unsigned char)(BMP_FILE_HEADER_SIZE
									+ BMP_INFO_HEADER_SIZE);
	write(fd, file_header, BMP_FILE_HEADER_SIZE);
	free(file_header);
}

void	bitmap_info_header(int fd)
{
	unsigned char	*info_header;

	if (!(info_header = ft_calloc(BMP_INFO_HEADER_SIZE, sizeof(unsigned char))))
		exit(0);
	info_header[0] = (unsigned char)(BMP_INFO_HEADER_SIZE);
	info_header[4] = (unsigned char)(g_screen.width);
	info_header[5] = (unsigned char)(g_screen.width >> 8);
	info_header[6] = (unsigned char)(g_screen.width >> 16);
	info_header[7] = (unsigned char)(g_screen.width >> 24);
	info_header[8] = (unsigned char)(g_screen.height);
	info_header[9] = (unsigned char)(g_screen.height >> 8);
	info_header[10] = (unsigned char)(g_screen.height >> 16);
	info_header[11] = (unsigned char)(g_screen.height >> 24);
	info_header[12] = (unsigned char)(1);
	info_header[14] = (unsigned char)(g_screen.img->bits_per_pixel);
	write(fd, info_header, BMP_INFO_HEADER_SIZE);
	free(info_header);
}

void	create_bmp_image(char *file_name)
{
	int	h;
	int	w;
	int	fd;
	int	padding_size;

	if (!(fd = open(file_name, O_CREAT | O_WRONLY | O_TRUNC, 0644)))
		exit(0);
	padding_size = 0;
	bitmap_file_header(padding_size, fd);
	bitmap_info_header(fd);
	h = g_screen.height;
	while (h--)
	{
		w = 0;
		while (w < g_screen.width)
		{
			write(fd, g_screen.img->addr + (h * g_screen.img->line_length
				+ w * g_screen.img->bits_per_pixel / 8), 4);
			w++;
		}
	}
	printf("\nDONESCRBMP");
	close(fd);
}
