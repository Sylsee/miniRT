/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 14:35:05 by spoliart          #+#    #+#             */
/*   Updated: 2022/02/12 22:50:51 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

#ifndef BASE_COLOR_IMPACT
# define BASE_COLOR_IMPACT 0.7
#endif
#ifndef LIGHT_IMPACT
# define LIGHT_IMPACT 1000
#endif
#ifndef LIGHT_COLOR_IMPACT
# define LIGHT_COLOR_IMPACT 0.7
#endif
#ifndef AMBIENT_IMPACT
# define AMBIENT_IMPACT 0.1
#endif
#ifndef AMBIENT_COLOR_IMPACT
# define AMBIENT_COLOR_IMPACT 0.1
#endif
#ifndef INTENSITY_IMPACT
# define INTENSITY_IMPACT 0.9
#endif

static void	calculate_color(t_hit hit, t_light *light, double intensity,
	t_color *color)
{
	color->r += (hit.color.r * BASE_COLOR_IMPACT
			+ light->color.r * LIGHT_COLOR_IMPACT)
		* intensity * INTENSITY_IMPACT;
	color->g += (hit.color.g * BASE_COLOR_IMPACT
			+ light->color.g * LIGHT_COLOR_IMPACT)
		* intensity * INTENSITY_IMPACT;
	color->b += (hit.color.b * BASE_COLOR_IMPACT
			+ light->color.b * LIGHT_COLOR_IMPACT)
		* intensity * INTENSITY_IMPACT;
	color->r = max(min(color->r, 255), 0);
	color->g = max(min(color->g, 255), 0);
	color->b = max(min(color->b, 255), 0);
}

static t_color	init_color(t_scene scene, t_hit hit)
{
	t_color	color;

	color.r = (hit.color.r * BASE_COLOR_IMPACT + scene.ambient.color.r
			* AMBIENT_COLOR_IMPACT) * scene.ambient.ratio * AMBIENT_IMPACT;
	color.g = (hit.color.g * BASE_COLOR_IMPACT + scene.ambient.color.g
			* AMBIENT_COLOR_IMPACT) * scene.ambient.ratio * AMBIENT_IMPACT;
	color.b = (hit.color.b * BASE_COLOR_IMPACT + scene.ambient.color.b
			* AMBIENT_COLOR_IMPACT) * scene.ambient.ratio * AMBIENT_IMPACT;
	color.r = max(min(color.r, 255), 0);
	color.g = max(min(color.g, 255), 0);
	color.b = max(min(color.b, 255), 0);
	return (color);
}

t_color	light(t_scene scene, t_hit hit)
{
	double	intensity;
	double	norm;
	t_list	*tmp;
	t_color	color;
	t_light	*light;

	intensity = 0;
	tmp = scene.light;
	color = init_color(scene, hit);
	while (tmp)
	{
		light = tmp->content;
		norm = max(v_dot(get_normalize(v_sub(light->pos, hit.normal.origin)),
					hit.normal.dir), 0);
		intensity += is_shaded(scene, hit, light) * light->ratio * LIGHT_IMPACT
			* norm
			/ get_norm2(v_sub(light->pos, hit.normal.origin));
		calculate_color(hit, light, intensity, &color);
		tmp = tmp->next;
	}
	return (color);
}
