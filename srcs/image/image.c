/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 22:25:02 by spoliart          #+#    #+#             */
/*   Updated: 2022/02/09 16:51:40 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

#ifndef ANTIALIASING
# define ANTIALIASING 1.0
#endif
#ifndef MAX_REFLECT
# define MAX_REFLECT 100
#endif

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
		else if (tmp->id == CYLINDER)
			has_inter = inter_cylinder(tmp->object, ray, &t, mode);
		if (has_inter == true && (t_min.dist == -1 || t.dist < t_min.dist))
			t_min = t;
		tmp = tmp->next;
	}
	return (t_min);
}

t_color	get_color(t_scene scene, t_vector ray, int nb_rebound)
{
	t_hit	hit;
	t_color	color;

	if (nb_rebound == 0)
		return (new_color(BACKGROUND_COLOR));
	hit = intersection(scene, ray, 1);
	if (hit.dist == -1)
		return (new_color(BACKGROUND_COLOR));
	if (hit.material_type == REFLECTION)
		return (reflection(scene, ray, hit, nb_rebound));
	else if (hit.material_type == REFRACTION)
		return (refraction(scene, ray, hit, nb_rebound));
	color = light(scene, hit);
	return (color);
}

int	anti_aliasing(t_scene scene, double x, double y)
{
	int			i;
	int			j;
	t_color		color;
	t_color		tmp_color;
	t_vector	ray;

	i = -1;
	color = new_color(0);
	while(++i < ANTIALIASING)
	{
		j = -1;
		while (++j < ANTIALIASING)
		{
			ray = new_ray(scene.cam, scene, x + (double)i / ANTIALIASING,
					y + (double)j / ANTIALIASING);
			tmp_color = get_color(scene, ray, MAX_REFLECT);
			color.r += tmp_color.r;
			color.g += tmp_color.g;
			color.b += tmp_color.b;
		}
	}
	color.r /= ANTIALIASING * ANTIALIASING;
	color.g /= ANTIALIASING * ANTIALIASING;
	color.b /= ANTIALIASING * ANTIALIASING;
	return (create_rgb((int)color.r, (int)color.g, (int)color.b));
}

void	create_img(t_data *data, t_scene scene)
{
	int			x;
	int			y;
	int			color;

	y = 0;
	while (y < scene.res.y)
	{
		x = 0;
		while (x < scene.res.x)
		{
			color = anti_aliasing(scene, (double)x, (double)y);
			put_color(data, x, y, color);
			x++;
		}
		y++;
	}
}
