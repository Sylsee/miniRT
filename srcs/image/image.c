/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 22:25:02 by spoliart          #+#    #+#             */
/*   Updated: 2022/01/12 22:57:10 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_hit	intersection(t_scene scene, t_vector ray, int mode)
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
			has_inter = inter_sphere(tmp->object, ray, &t, mode);
		else if (tmp->id == PLANE)
			has_inter = inter_plane(tmp->object, ray, &t, mode);
/*		else if (tmp->id == CYLINDER)
			has_inter = inter_cylinder(tmp->object, ray, &t, mode);
*/		if (has_inter == true && (t_min.dist == -1 || t.dist < t_min.dist))
			t_min = t;
		tmp = tmp->next;
	}
	return (t_min);
}

#ifndef REBOUND_MAX
# define REBOUND_MAX 100
#endif

int	get_color(t_scene scene, t_vector ray, int nb_rebound)
{
	t_hit	hit;
	t_color	color;

	if (nb_rebound == 0)
		return (BACKGROUND_COLOR);
	hit = intersection(scene, ray, 1);
	if (hit.dist == -1)
		return (BACKGROUND_COLOR);
	else if (hit.mirror == true)
		return (mirror(scene, ray, hit, nb_rebound));
	color = light(scene, hit);
	return (create_rgb(color.r, color.g, color.b));
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
			ray = new_ray(scene.cam, scene, x, y);
			color = get_color(scene, ray, REBOUND_MAX);
			put_color(data, x, y, color);
			x++;
		}
		y++;
	}
}
