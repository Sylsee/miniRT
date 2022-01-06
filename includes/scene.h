/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 16:20:44 by spoliart          #+#    #+#             */
/*   Updated: 2021/12/15 21:40:33 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

typedef struct s_color
{
	double		r;
	double		g;
	double		b;
}				t_color;

typedef struct s_p3
{
	double		x;
	double		y;
	double		z;
}				t_p3;

typedef struct s_couple
{
	int			x;
	int			y;
}				t_couple;

typedef struct s_vector
{
	t_p3		origin;
	t_p3		dir;
}				t_vector;

typedef struct s_light
{
	double		ratio;
	t_color		color;
	t_p3		pos;
}				t_light;

typedef struct s_cam
{
	t_p3		origin;
	t_p3		dir;
	double		fov;
}				t_cam;

typedef struct s_scene
{
	t_couple	res;
	t_light		ambient;
	t_list		*light;
	t_list		*cam;
	t_lst		*obj;
}				t_scene;

#endif
