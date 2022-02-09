/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refraction.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 15:04:08 by spoliart          #+#    #+#             */
/*   Updated: 2022/02/09 20:34:43 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_p3	refract(t_vector ray, t_hit hit)
{
	double		cosi;
	double		eta[4];
	t_p3		n;

	eta[0] = 1;
	eta[1] = hit.ior;
	cosi = max(-1, min(1, v_dot(ray.dir, hit.normal.dir)));
	n = hit.normal.dir;
	if (cosi < 0)
		cosi = -cosi;
	else
	{
		eta[3] = eta[0];
		eta[0] = eta[1];
		eta[1] = eta[3];
		n = v_scale(hit.normal.dir, -1);
	}
	eta[3] = eta[0] / eta[1];
	eta[3] = 1 - eta[3] * eta[3] * (1 - cosi * cosi);
	if (eta[3] < 0)
		return ((t_p3){0, 0, 0});
	else
		return (v_add(v_scale(ray.dir, eta[3]),
				v_scale(n, eta[3] * cosi - sqrtf((float)eta[3]))));
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
	color.r = reflect_color.r * kr * 0.1 + refract_color.r * (1 - kr) * 0.9;
	color.g = reflect_color.g * kr * 0.1 + refract_color.g * (1 - kr) * 0.9;
	color.b = reflect_color.b * kr * 0.1 + refract_color.b * (1 - kr) * 0.9;
	return (color);
}
