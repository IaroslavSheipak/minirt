/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suzumaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 08:13:23 by suzumaki          #+#    #+#             */
/*   Updated: 2021/01/24 19:53:57 by suzumaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	ft_strlen(const char *s)
{
	char	*ptr;
	int		res;

	res = 0;
	if (!s)
		return (res);
	ptr = (char *)s;
	while (*ptr++)
		res++;
	return (res);
}

static char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	char	*res;
	size_t	n;

	ptr = NULL;
	if (!s1 && !s2)
		return (NULL);
	n = 1 + ft_strlen(s1) + ft_strlen(s2);
	if (!(ptr = (char *)malloc(sizeof(char) * n)))
		return (NULL);
	res = ptr;
	while (s1 && n-- && *s1 != '\0')
		*ptr++ = *s1++;
	while (n-- && *s2 != '\0')
		*ptr++ = *s2++;
	*ptr = '\0';
	return (res);
}

char			*get_res(char *res)
{
	char	*rtn;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!res)
		return (0);
	while (res[i] && res[i] != '\n')
		i++;
	if (!res[i])
	{
		free(res);
		return (0);
	}
	if (!(rtn = malloc(sizeof(char) * ((ft_strlen(res) - i) + 1))))
		return (0);
	i++;
	while (res[i])
		rtn[j++] = res[i++];
	rtn[j] = '\0';
	free(res);
	return (rtn);
}

int				free_buf(char *buffer)
{
	free(buffer);
	return (-1);
}

int				get_next_line(int fd, char **line)
{
	static char	*res;
	char		*buffer;
	int			hv_read;
	char		*tmp;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!(buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	hv_read = 1;
	while (!check_buffer(res) && hv_read != 0)
	{
		if ((hv_read = read(fd, buffer, BUFFER_SIZE)) == -1)
			return (free_buf(buffer));
		buffer[hv_read] = '\0';
		tmp = res;
		res = ft_strjoin(res, buffer);
		free(tmp);
	}
	free(buffer);
	*line = get_line(res);
	res = get_res(res);
	return (!!hv_read);
}
