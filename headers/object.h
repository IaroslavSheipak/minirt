/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suzumaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 19:38:21 by suzumaki          #+#    #+#             */
/*   Updated: 2021/03/21 19:38:22 by suzumaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHARIKI_OBJECT_H
# define SHARIKI_OBJECT_H

# include "minirt.h"
# include "vector.h"

typedef	struct				s_object_3d
{
	void					*data;
	int						id;
	char					*type;
	int						(* intersect)();
	t_vector_3d				(* get_normal_vector)();
	t_vector_3d				color;
}							t_object_3d;

typedef struct				s_object_list
{
	t_object_3d				obj;
	struct s_object_list	*next;
	struct s_object_list	*prev;
}							t_object_list;

t_object_list				*ft_objnew(t_object_3d object);
t_object_list				*ft_objlast(t_object_list *lst);
void						ft_objadd_back(t_object_list **lst,
								t_object_list *new);

#endif
