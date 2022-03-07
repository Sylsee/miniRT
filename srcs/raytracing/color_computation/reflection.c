/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 16:23:23 by spoliart          #+#    #+#             */
/*   Updated: 2022/02/13 00:40:55 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

inline t_vector	reflect(t_vector v1, t_vector v2)
{
	t_vector	reflect_ray;

	reflect_ray.dir = v_sub(v1.dir, v_scale(v2.dir,
				2 * v_dot(v2.dir, v1.dir)));
	reflect_ray.origin = v_add(v2.origin, v_scale(v2.dir, 0.00001));
	return (reflect_ray);
}

t_color	reflection(t_scene scene, t_vector ray, t_hit hit, int nb_rebound)
{
	t_vector	reflect_ray;

	reflect_ray = reflect(ray, hit.normal);
	return (get_color(scene, reflect_ray, nb_rebound - 1));
}

t_color	mirror(t_scene scene, t_vector ray, t_hit hit, int nb_rebound)
{
	double		kr;
	t_color		color;
	t_color		reflect_color;

	reflect_color = reflection(scene, ray, hit, nb_rebound);
	kr = fresnel(ray.dir, hit);
	color.r = hit.color.r * (1 - kr) * 0.05 + reflect_color.r * kr * 0.95;
	color.g = hit.color.g * (1 - kr) * 0.05 + reflect_color.g * kr * 0.95;
	color.b = hit.color.b * (1 - kr) * 0.05 + reflect_color.b * kr * 0.95;
	return (color);
}
