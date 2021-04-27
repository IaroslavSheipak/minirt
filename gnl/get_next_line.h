/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suzumaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 06:54:02 by suzumaki          #+#    #+#             */
/*   Updated: 2021/01/24 19:53:51 by suzumaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 1
# include <unistd.h>
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

int		check_buffer(char *buffer);
char	*get_line(const char *s);
char	*get_res(char *res);
int		free_buf(char *buffer);
int		get_next_line(int fd, char **line);

#endif
