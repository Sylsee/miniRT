/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 21:54:18 by spoliart          #+#    #+#             */
/*   Updated: 2022/01/12 22:29:34 by spoliart         ###   ########.fr       */
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
	t_p3		pos;
	t_color		color;
	bool		mirror;
}				t_sphere;

typedef struct	s_plane
{
	t_p3		pos;
	t_p3		dir;
	t_color		color;
	bool		mirror;
}				t_plane;

typedef struct	s_square
{
	double		size;
	t_p3		pos;
	t_p3		dir;
	t_color		color;
	bool		mirror;
}				t_square;

typedef struct	s_cylinder
{
	double		diameter;
	double		height;
	t_p3		pos;
	t_p3		dir;
	t_color		color;
	bool		mirror;
}				t_cylinder;

typedef struct	s_triangle
{
	t_p3		first;
	t_p3		second;
	t_p3		third;
	t_color		color;
	bool		mirror;
}				t_triangle;

bool	inter_sphere(t_sphere *s, t_vector ray, t_hit *hit, int mode);
bool	inter_plane(t_plane *p, t_vector ray, t_hit *hit, int mode);

#endif
