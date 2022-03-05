/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 14:24:11 by spoliart          #+#    #+#             */
/*   Updated: 2022/03/04 15:44:59 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	is_shaded(t_scene scene, t_hit hit, t_light *light)
{
	t_vector	ray;
	t_hit		obj_hit;
	double		light_dist;

	ray.dir = get_normalize(v_sub(light->pos, hit.normal.origin));
	ray.origin = v_add(hit.normal.origin, v_scale(ray.dir, 0.000000001));
	light_dist = sqrt(get_norm2(v_sub(light->pos, hit.normal.origin)));
	obj_hit = intersection(scene.obj, ray, 3);
	if (obj_hit.dist == -1 || obj_hit.dist > light_dist)
		return (1);
	return (0);
}
