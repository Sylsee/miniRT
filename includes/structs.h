/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 16:20:44 by spoliart          #+#    #+#             */
/*   Updated: 2021/05/18 21:10:54 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

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

typedef struct	s_vector
{
	t_coord		origin;
	t_coord		direction;
}				t_ray;

typedef struct	s_light
{
	t_coord			pos;
	double			ratio;
	t_color			color;
}				t_light;

typedef struct	s_cam
{
	t_vector		vector;
	double			fov;
}				t_cam;

typedef struct	s_sphere
{
	short		id;
	t_coord		pos;
	double		diameter;
	t_color		color;
}				t_sphere;

typedef struct	s_plane
{
	short		id;
	t_coord		pos;
	t_coord		orientation;
	t_color		color;
}				t_plane;

typedef struct	s_square
{
	short		id;
	t_coord		pos;
	t_coord		orientation;
	double		size;
	t_color		color;
}				t_square;

typedef struct	s_cylinder
{
	short		id;
	t_coord		pos;
	t_coord		orientation;
	double		diameter;
	double		height;
	t_color		color;
}				t_cylinder;

typedef struct	s_triangle
{
	short		id;
	t_coord		first;
	t_coord		second;
	t_coord		third;
	t_color		color;
}				t_triangle;

typedef struct	s_scene
{
	t_coord			res;
	t_light			ambient;
	t_list			*light;
	t_list			*cam;
	t_list			*obj;
}				t_scene;

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;
