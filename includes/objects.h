/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 21:54:18 by spoliart          #+#    #+#             */
/*   Updated: 2021/12/23 17:57:29 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

# define SPHERE 1
# define PLANE 2
# define SQUARE 3
# define CYLINDER 4
# define TRIANGLE 5

typedef struct	s_sphere
{
	double		diameter;
	t_coord		pos;
	t_color		color;
}				t_sphere;

typedef struct	s_plane
{
	t_coord		pos;
	t_coord		orientation;
	t_color		color;
}				t_plane;

typedef struct	s_square
{
	double		size;
	t_coord		pos;
	t_coord		orientation;
	t_color		color;
}				t_square;

typedef struct	s_cylinder
{
	double		diameter;
	double		height;
	t_coord		pos;
	t_coord		orientation;
	t_color		color;
}				t_cylinder;

typedef struct	s_triangle
{
	t_coord		first;
	t_coord		second;
	t_coord		third;
	t_color		color;
}				t_triangle;

int	inter_sphere(t_sphere *s, t_vector ray, t_hit *hit);

#endif
