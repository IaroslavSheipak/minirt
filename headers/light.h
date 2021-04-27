/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suzumaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 19:36:49 by suzumaki          #+#    #+#             */
/*   Updated: 2021/03/21 19:36:51 by suzumaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHARIKI_LIGHT_H
# define SHARIKI_LIGHT_H

# include "minirt.h"

typedef struct			s_light
{
	t_vector_3d			coords;
	double				ratio;
	t_vector_3d			color;
}						t_light;

typedef struct			s_light_list
{
	t_light				light;
	struct s_light_list	*next;
	struct s_light_list	*prev;
}						t_light_list;

t_light					new_light(double ratio, t_vector_3d color,
							t_vector_3d coords);
t_light_list			*ft_lghtnew(t_light light);
t_light_list			*ft_lghtlast(t_light_list *lst);
void					ft_lghtadd_back(t_light_list **lst, t_light_list *new);

#endif
