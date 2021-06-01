/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 16:20:44 by spoliart          #+#    #+#             */
/*   Updated: 2021/05/30 13:31:51 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "minirt.h"

typedef struct	s_color
{
	double		r;
	double		g;
	double		b;
}				t_color;

typedef struct	s_coord
{
	double		x;
	double		y;
	double		z;
}				t_coord;

typedef struct	s_couple
{
	int			x;
	int			y;
}				t_couple;

typedef struct	s_vector
{
	t_coord		origin;
	t_coord		orientation;
}				t_vector;

typedef struct	s_light
{
	t_coord		pos;
	double		ratio;
	t_color		color;
}				t_light;

typedef struct	s_cam
{
	t_vector	vector;
	double		fov;
}				t_cam;

typedef struct	s_list_rt
{
	int					id;
	void				*content;
	struct s_list_rt	*next;
}				t_list_rt;

typedef struct	s_scene
{
	t_couple	res;
	t_light		ambient;
	t_list		*light;
	t_list		*cam;
	t_list_rt	*obj;
}				t_scene;

#endif
