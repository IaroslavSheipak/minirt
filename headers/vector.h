/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suzumaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 11:27:29 by suzumaki          #+#    #+#             */
/*   Updated: 2021/03/25 11:28:02 by suzumaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHARIKI_VECTOR_H
# define SHARIKI_VECTOR_H

typedef struct	s_vector_3d
{
	double	x;
	double	y;
	double	z;

}				t_vector_3d;

typedef struct	s_quaternion
{
	double		a;
	double		x;
	double		y;
	double		z;
}				t_quaternion;

#endif
