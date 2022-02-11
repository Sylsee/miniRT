/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 22:25:02 by spoliart          #+#    #+#             */
/*   Updated: 2022/02/11 00:44:11 by spoliart         ###   ########.fr       */
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
	t_color	reflect;

	if (nb_rebound <= 0)
		return (new_color(scene.bg_color));
	hit = intersection(scene, ray, 1);
	if (hit.dist == -1)
		return (new_color(scene.bg_color));
	if (hit.material_type == REFLECTION)
		return (mirror(scene, ray, hit, nb_rebound));
	else if (hit.material_type == REFRACTION)
		return (refraction(scene, ray, hit, nb_rebound));
	color = light(scene, hit);
	if (hit.material_type == NONE && scene.do_reflection)
	{
		reflect = reflection(scene, ray, hit, nb_rebound);
		color.r = color.r * 0.93 + reflect.r * 0.07;
		color.g = color.g * 0.93 + reflect.g * 0.07;
		color.b = color.b * 0.93 + reflect.b * 0.07;
	}
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
	while (++i < scene.antialiasing)
	{
		j = -1;
		while (++j < scene.antialiasing)
		{
			ray = new_ray(scene.cam, scene, x + (double)i / scene.antialiasing,
					y + (double)j / scene.antialiasing);
			tmp_color = get_color(scene, ray, scene.ray_max_bounces);
			color.r += tmp_color.r;
			color.g += tmp_color.g;
			color.b += tmp_color.b;
		}
	}
	color.r /= scene.antialiasing * scene.antialiasing;
	color.g /= scene.antialiasing * scene.antialiasing;
	color.b /= scene.antialiasing * scene.antialiasing;
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
		printf("\033[2K\r %.2f%%", (double)(y * 100 / scene.res.y));
	}
	printf("\n");
}
