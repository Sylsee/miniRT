/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 22:25:02 by spoliart          #+#    #+#             */
/*   Updated: 2022/01/07 14:24:44 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_hit	intersection(t_scene scene, t_vector ray)
{
	bool	has_inter;
	t_hit	t;
	t_hit	t_min;
	t_lst	*tmp;

	t_min.dist = -1;
	tmp = scene.obj;
	while (tmp)
	{
		has_inter = false;
		if (tmp->id == SPHERE)
			has_inter = inter_sphere(tmp->object, ray, &t);
/*		else if (tmp->id == PLANE)
			has_inter = inter_plane(tmp->object, ray, &t);
		else if (tmp->id == CYLINDER)
			has_inter = inter_cylinder(tmp->object, ray, &t);
*/		if (has_inter == true && (t_min.dist == -1 || t.dist < t_min.dist))
			t_min = t;
		tmp = tmp->next;
	}
	return (t_min);
}

static int	get_color(t_scene scene, t_vector ray)
{
	int		color;
	t_hit	t;

	t = intersection(scene, ray);
	if (t.dist == -1)
		return (BACKGROUND_COLOR);
	color = create_rgb(t.color.r, t.color.g, t.color.b);
	return (color);
}

void	create_img(t_data *data, t_scene scene)
{
	int			x;
	int			y;
	int			color;
	t_vector	ray;

	y = 0;
	while (y < scene.res.y)
	{
		x = 0;
		while (x < scene.res.x)
		{
			ray = new_ray(scene.cam->content, scene, x, y);
			color = get_color(scene, ray);
			put_color(data, x, y, color);
			x++;
		}
		y++;
	}
}
