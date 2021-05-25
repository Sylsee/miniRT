/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 21:54:18 by spoliart          #+#    #+#             */
/*   Updated: 2021/05/26 00:25:25 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

# include "minirt.h"

typedef struct	s_sphere
{
	int			id;
	t_coord		pos;
	double		diameter;
	t_color		color;
}				t_sphere;

typedef struct	s_plane
{
	int			id;
	t_coord		pos;
	t_coord		orientation;
	t_color		color;
}				t_plane;

typedef struct	s_square
{
	int			id;
	t_coord		pos;
	t_coord		orientation;
	double		size;
	t_color		color;
}				t_square;

typedef struct	s_cylinder
{
	int			id;
	t_coord		pos;
	t_coord		orientation;
	double		diameter;
	double		height;
	t_color		color;
}				t_cylinder;

typedef struct	s_triangle
{
	int			id;
	t_coord		first;
	t_coord		second;
	t_coord		third;
	t_color		color;
}				t_triangle;

int	inter_sphere(t_sphere *s, t_vector ray);

#endif
