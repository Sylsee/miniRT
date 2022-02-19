/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refraction.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 15:04:08 by spoliart          #+#    #+#             */
/*   Updated: 2022/02/12 22:36:08 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_p3	refract(t_vector ray, t_hit hit)
{
	double			n;
	double			cost;
	double			sint2;
	const double	cosi = -v_dot(hit.normal.dir, ray.dir);

	if (cosi < 0)
		n = hit.ior / AIR_REFRACTIVE_IMPACT;
	else
		n = AIR_REFRACTIVE_IMPACT / hit.ior;
	sint2 = n * n * (1.0 - cosi * cosi);
	cost = sqrt(1.0 - sint2);
	if (sint2 > 1.0)
		return ((t_p3){0, 0, 0});
	return (v_add(v_scale(ray.dir, n),
			v_scale(hit.normal.dir, n * cosi - cost)));
}

t_color	refraction(t_scene scene, t_vector ray, t_hit hit, int nb_rebound)
{
	double		kr;
	t_color		color;
	t_color		refract_color;
	t_color		reflect_color;
	t_vector	refrac;

	reflect_color = reflection(scene, ray, hit, nb_rebound);
	refrac.dir = get_normalize(refract(ray, hit));
	if (v_dot(refrac.dir, hit.normal.dir) < 0)
		refrac.origin = v_sub(hit.normal.origin, v_scale(hit.normal.dir,
					0.00001));
	else
		refrac.origin = v_add(hit.normal.origin, v_scale(hit.normal.dir,
					0.00001));
	refract_color = get_color(scene, refrac, nb_rebound - 1);
	kr = fresnel(ray.dir, hit);
	color.r = reflect_color.r * kr + refract_color.r * (1.0 - kr);
	color.g = reflect_color.g * kr + refract_color.g * (1.0 - kr);
	color.b = reflect_color.b * kr + refract_color.b * (1.0 - kr);
	return (color);
}
