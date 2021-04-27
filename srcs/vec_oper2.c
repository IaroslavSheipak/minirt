/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_oper2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suzumaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 19:41:43 by suzumaki          #+#    #+#             */
/*   Updated: 2021/03/25 12:22:09 by suzumaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers//minirt.h"

t_vector_3d	vector_subtract(t_vector_3d a, t_vector_3d b)
{
	a.x -= b.x;
	a.y -= b.y;
	a.z -= b.z;
	return (a);
}

t_vector_3d	vector_scalar_multiplication(t_vector_3d vector, double scalar)
{
	vector.x *= scalar;
	vector.y *= scalar;
	vector.z *= scalar;
	return (vector);
}

t_vector_3d	vector_scalar_division(t_vector_3d vector, double scalar)
{
	vector.x /= scalar;
	vector.y /= scalar;
	vector.z /= scalar;
	return (vector);
}

t_vector_3d	vector_sum(t_vector_3d a, t_vector_3d b)
{
	a.x += b.x;
	a.y += b.y;
	a.z += b.z;
	return (a);
}

t_vector_3d	vector_multiplication(t_vector_3d a, t_vector_3d b)
{
	a.x *= b.x;
	a.y *= b.y;
	a.z *= b.z;
	return (a);
}
