/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 16:23:23 by spoliart          #+#    #+#             */
/*   Updated: 2022/02/09 16:59:52 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color	reflection(t_scene scene, t_vector ray, t_hit hit, int nb_rebound)
{
	double		kr;
	t_color		color;
	t_vector	reflect;
	t_color		reflect_color;

	reflect.dir = v_sub(ray.dir, v_scale(hit.normal.dir,
				2 * v_dot(hit.normal.dir, ray.dir)));
	reflect.origin = v_add(hit.normal.origin, v_scale(hit.normal.dir, 0.00001));
	reflect_color = get_color(scene, reflect, nb_rebound - 1);
	kr = fresnel(ray.dir, hit);
	color.r = hit.color.r * (1 - kr) * 0.1 + reflect_color.r * kr;
	color.g = hit.color.g * (1 - kr) * 0.1 + reflect_color.g * kr;
	color.b = hit.color.b * (1 - kr) * 0.1 + reflect_color.b * kr;
	return (color);
}
