/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 21:54:18 by spoliart          #+#    #+#             */
/*   Updated: 2022/01/15 23:09:04 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

# define SPHERE 1
# define PLANE 2
# define SQUARE 3
# define CYLINDER 4
# define TRIANGLE 5

# define SPHERE_DIAMETER_SIZE 1
# define CYLINDER_WIDTH_SIZE 1
# define CYLINDER_HEIGHT_SIZE 1

typedef struct	s_sphere
{
	double		diameter;
	t_p3		pos;
	t_color		color;
}				t_sphere;

typedef struct	s_plane
{
	t_p3		pos;
	t_p3		dir;
	t_color		color;
}				t_plane;

typedef struct	s_square
{
	double		size;
	t_p3		pos;
	t_p3		dir;
	t_color		color;
}				t_square;

typedef struct	s_cylinder
{
	double		diameter;
	double		height;
	t_p3		pos;
	t_p3		dir;
	t_color		color;
}				t_cylinder;

typedef struct	s_triangle
{
	t_p3		first;
	t_p3		second;
	t_p3		third;
	t_color		color;
}				t_triangle;

int	inter_sphere(t_sphere *s, t_vector ray, t_hit *hit);

#endif
