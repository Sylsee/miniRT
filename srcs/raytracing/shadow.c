/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 14:24:11 by spoliart          #+#    #+#             */
/*   Updated: 2022/03/09 13:38:08 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool	intersection_shadow(t_object_list *objects, t_vector ray,
		double light_dist)
{
	bool	has_inter;
	t_hit	t;

	while (objects)
	{
		has_inter = false;
		if (objects->id == SPHERE)
			has_inter = inter_sphere(objects->object, ray, &t, 3);
		else if (objects->id == PLANE)
			has_inter = inter_plane(objects->object, ray, &t, 3);
		else if (objects->id == CYLINDER)
			has_inter = inter_cylinder(objects->object, ray, &t, 3);
		if (has_inter == true && t.dist < light_dist)
			return (false);
		objects = objects->next;
	}
	return (true);
}

bool	is_shaded(t_scene scene, t_hit hit, t_light *light)
{
	t_vector	ray;
	double		light_dist;

	ray.dir = get_normalize(v_sub(light->pos, hit.normal.origin));
	ray.origin = v_add(hit.normal.origin, v_scale(ray.dir, 0.000000001));
	light_dist = sqrt(get_norm2(v_sub(light->pos, hit.normal.origin)));
	return (intersection_shadow(scene.obj, ray, light_dist));
}
