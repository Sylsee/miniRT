/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 14:35:05 by spoliart          #+#    #+#             */
/*   Updated: 2022/03/09 12:25:48 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	diffuse(t_hit hit, t_light *light, t_light_infos *infos)
{
	double	intensity;

	intensity = infos->vis * light->ratio * LIGHT_IMPACT
		* max(v_dot(get_normalize(v_sub(light->pos, hit.normal.origin)),
				hit.normal.dir), 0)
		/ get_norm2(v_sub(light->pos, hit.normal.origin));
	infos->diffuse_color.r += (hit.color.r * BASE_COLOR_IMPACT
			+ light->color.r * LIGHT_COLOR_IMPACT)
		* intensity * INTENSITY_IMPACT;
	infos->diffuse_color.g += (hit.color.g * BASE_COLOR_IMPACT
			+ light->color.g * LIGHT_COLOR_IMPACT)
		* intensity * INTENSITY_IMPACT;
	infos->diffuse_color.b += (hit.color.b * BASE_COLOR_IMPACT
			+ light->color.b * LIGHT_COLOR_IMPACT)
		* intensity * INTENSITY_IMPACT;
	infos->diffuse_color.r = max(min(infos->diffuse_color.r, 255), 0);
	infos->diffuse_color.g = max(min(infos->diffuse_color.g, 255), 0);
	infos->diffuse_color.b = max(min(infos->diffuse_color.b, 255), 0);
}

static void	specular(t_hit hit, t_light *light, t_light_infos *infos)
{
	double		intensity;
	t_vector	reflect_ray;

	reflect_ray = reflect((t_vector){light->pos,
			get_normalize(v_sub(light->pos, hit.normal.origin))}, hit.normal);
	intensity = infos->vis * light->ratio * 0.5
		* pow(max(0, v_dot(reflect_ray.dir, infos->ray.dir)), 64);
	infos->specular_color.r += (hit.color.r * BASE_COLOR_IMPACT
			+ light->color.r * LIGHT_COLOR_IMPACT)
		* intensity * INTENSITY_IMPACT;
	infos->specular_color.g += (hit.color.g * BASE_COLOR_IMPACT
			+ light->color.g * LIGHT_COLOR_IMPACT)
		* intensity * INTENSITY_IMPACT;
	infos->specular_color.b += (hit.color.b * BASE_COLOR_IMPACT
			+ light->color.b * LIGHT_COLOR_IMPACT)
		* intensity * INTENSITY_IMPACT;
	infos->specular_color.r = max(min(infos->specular_color.r, 255), 0);
	infos->specular_color.g = max(min(infos->specular_color.g, 255), 0);
	infos->specular_color.b = max(min(infos->specular_color.b, 255), 0);
}

static void	init_light(t_scene scene, t_hit hit, t_vector ray,
		t_light_infos *infos)
{
	infos->ray = ray;
	infos->diffuse_color.r = 0;
	infos->diffuse_color.g = 0;
	infos->diffuse_color.b = 0;
	infos->specular_color.r = 0;
	infos->specular_color.g = 0;
	infos->specular_color.b = 0;
	infos->base_color.r = (hit.color.r * BASE_COLOR_IMPACT
			+ scene.ambient.color.r * AMBIENT_COLOR_IMPACT)
		* scene.ambient.ratio * AMBIENT_IMPACT;
	infos->base_color.g = (hit.color.g * BASE_COLOR_IMPACT
			+ scene.ambient.color.g * AMBIENT_COLOR_IMPACT)
		* scene.ambient.ratio * AMBIENT_IMPACT;
	infos->base_color.b = (hit.color.b * BASE_COLOR_IMPACT
			+ scene.ambient.color.b * AMBIENT_COLOR_IMPACT)
		* scene.ambient.ratio * AMBIENT_IMPACT;
	infos->base_color.r = max(min(infos->base_color.r, 255), 0);
	infos->base_color.g = max(min(infos->base_color.g, 255), 0);
	infos->base_color.b = max(min(infos->base_color.b, 255), 0);
}

t_color	light(t_scene scene, t_hit hit, t_vector ray)
{
	t_list			*tmp;
	t_light			*light;
	t_light_infos	infos;

	tmp = scene.light;
	init_light(scene, hit, ray, &infos);
	while (tmp)
	{
		light = tmp->content;
		infos.vis = is_shaded(scene, hit, light);
		diffuse(hit, light, &infos);
		specular(hit, light, &infos);
		tmp = tmp->next;
	}
	infos.base_color.r += infos.diffuse_color.r * DIFFUSE_COEF
		+ infos.specular_color.r * SPECULAR_COEF;
	infos.base_color.g += infos.diffuse_color.g * DIFFUSE_COEF
		+ infos.specular_color.g * SPECULAR_COEF;
	infos.base_color.b += infos.diffuse_color.b * DIFFUSE_COEF
		+ infos.specular_color.b * SPECULAR_COEF;
	infos.base_color.r = max(min(infos.base_color.r, 255), 0);
	infos.base_color.g = max(min(infos.base_color.g, 255), 0);
	infos.base_color.b = max(min(infos.base_color.b, 255), 0);
	return (infos.base_color);
}
