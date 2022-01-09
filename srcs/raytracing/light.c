/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 14:35:05 by spoliart          #+#    #+#             */
/*   Updated: 2022/01/09 20:45:41 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static double	min(double a, double b)
{
	if (a > b)
		return (b);
	return (a);
}

static double	max(double a, double b)
{
	if (a < b)
		return (b);
	return (a);
}

#define BASE_COLOR_IMPACT 2
#define LIGHT_IMPACT 0.7
#define AMBIENT_COLOR_IMPACT 0.1
#define INTENSITY_IMPACT 0.9
#define AMBIENT_IMPACT 0.1

static t_color	calculate_color(t_scene scene, t_hit hit, t_light *light,
	double intensity, t_color color)
{
	color.r += (hit.color.r * BASE_COLOR_IMPACT + light->color.r * LIGHT_IMPACT
		+ scene.ambient.color.r * AMBIENT_COLOR_IMPACT)
		* (intensity * INTENSITY_IMPACT + scene.ambient.ratio * AMBIENT_IMPACT);
	color.g += (hit.color.g * BASE_COLOR_IMPACT + light->color.g * LIGHT_IMPACT
		+ scene.ambient.color.g * AMBIENT_COLOR_IMPACT)
		* (intensity * INTENSITY_IMPACT + scene.ambient.ratio * AMBIENT_IMPACT);
	color.b += (hit.color.b * BASE_COLOR_IMPACT + light->color.b * LIGHT_IMPACT
		+ scene.ambient.color.b * AMBIENT_COLOR_IMPACT)
		* (intensity * INTENSITY_IMPACT + scene.ambient.ratio * AMBIENT_IMPACT);
	color.r = max(min(color.r, 255), 0);
	color.g = max(min(color.g, 255), 0);
	color.b = max(min(color.b, 255), 0);
	return (color);
}

t_color	light(t_scene scene, t_hit hit)
{
	double	intensity;
	t_list	*tmp;
	t_color	color;
	t_light	*light;

	color.r = 0;
	color.g = 0;
	color.b = 0;
	intensity = 0;
	tmp = scene.light;
	while (tmp)
	{
		light = tmp->content;
		intensity += light->ratio * 50
			* max(v_dot(get_normalize(
			v_sub(light->pos, hit.normal.origin)), hit.normal.dir), 0)
			/ get_norm2(v_sub(light->pos, hit.normal.origin));
		color = calculate_color(scene, hit, light, intensity, color);
		tmp = tmp->next;
	}
	return (color);
}
