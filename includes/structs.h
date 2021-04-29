/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 16:20:44 by spoliart          #+#    #+#             */
/*   Updated: 2021/04/29 19:25:55 by spoliart         ###   ########.fr       */
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

typedef struct	s_ray
{
	t_coord		origin;
	t_coord		direction;
}				t_ray;

typedef struct	s_list
{
	int				id;
	void			*content;
	struct s_list	*next;
}				t_list;

typedef struct	s_light
{
	t_coord			pos;
	double			ratio;
	t_color			color;
	struct s_light	*next;
}				t_light;

typedef struct	s_cam
{
	t_ray			ray;
	double			fov;
	struct s_cam	*next;
}				t_cam;

typedef struct	s_scene
{
	t_coord			res;
	t_light			ambient;
	t_light			**light;
	t_cam			**cam;
	t_cam			*actual_cam
	t_list			*elem;
}				t_scene;
