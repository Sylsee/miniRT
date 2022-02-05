/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 16:20:44 by spoliart          #+#    #+#             */
/*   Updated: 2022/02/05 22:40:12 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

typedef struct s_lst t_lst;

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
	double		x;
	double		y;
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
	int				id;
	double			fov;
	double			pov_w;
	double			pov_h;
	t_p3			origin;
	t_p3			v_up;
	t_p3			look_at;
	t_p3			lower_corner;
	t_p3			horizontal;
	t_p3			vertical;
	struct s_cam	*next;
	struct s_cam	*prev;
}				t_cam;

typedef struct s_scene
{
	bool		camera_mode;
	bool		object_type;
	bool		object_mode;
	t_couple	res;
	t_light		ambient;
	t_list		*light;
	t_list		*current_light;
	t_cam		*cam;
	t_lst		*obj;
	int			id_current_obj;
	void		*current_obj;
}				t_scene;

#endif
