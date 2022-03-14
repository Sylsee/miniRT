/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 14:35:05 by spoliart          #+#    #+#             */
/*   Updated: 2022/03/14 20:00:57 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	diffuse(t_hit hit, t_light *light, t_light_infos *infos)
{
	double	angle;
	double	distance;
	double	intensity;

	angle = max(v_dot(get_normalize(v_sub(light->pos, hit.normal.origin)),
		hit.normal.dir), 0);
	distance = get_norm2(v_sub(light->pos, hit.normal.origin));
	intensity = light->ratio * 3500000 * angle / distance;
	infos->diffuse_color.r += (hit.color.r + light->color.r) * intensity;
	infos->diffuse_color.g += (hit.color.g + light->color.g) * intensity;
	infos->diffuse_color.b += (hit.color.b + light->color.b) * intensity;
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
	intensity = light->ratio * 0.2
		* pow(max(0, v_dot(reflect_ray.dir, infos->ray.dir)), 60);
	infos->specular_color.r += (hit.color.r + light->color.r) * intensity;
	infos->specular_color.g += (hit.color.g + light->color.g) * intensity;
	infos->specular_color.b += (hit.color.b + light->color.b) * intensity;
	infos->specular_color.r = max(min(infos->specular_color.r, 255), 0);
	infos->specular_color.g = max(min(infos->specular_color.g, 255), 0);
	infos->specular_color.b = max(min(infos->specular_color.b, 255), 0);
}

static void	init_light(t_scene scene, t_vector ray, t_hit hit,
		t_light_infos *infos)
{
	infos->ray = ray;
	infos->diffuse_color.r = 0;
	infos->diffuse_color.g = 0;
	infos->diffuse_color.b = 0;
	infos->specular_color.r = 0;
	infos->specular_color.g = 0;
	infos->specular_color.b = 0;
	infos->ambient_color.r = scene.ambient.color.r * scene.ambient.ratio / 5
		/ 255 * hit.color.r;
	infos->ambient_color.g = scene.ambient.color.g * scene.ambient.ratio / 5
		/ 255 * hit.color.g;
	infos->ambient_color.b = scene.ambient.color.b * scene.ambient.ratio / 5
		/ 255 * hit.color.b;
}

static t_color	assemble_light(t_light_infos infos)
{
	t_color	color;

	color.r = infos.ambient_color.r + infos.diffuse_color.r
		+ infos.specular_color.r;
	color.g = infos.ambient_color.g + infos.diffuse_color.g
		+ infos.specular_color.g;
	color.b = infos.ambient_color.b + infos.diffuse_color.b
		+ infos.specular_color.b;
	color.r = max(min(color.r, 255), 0);
	color.g = max(min(color.g, 255), 0);
	color.b = max(min(color.b, 255), 0);
	return (color);
}

t_color	light(t_scene scene, t_hit hit, t_vector ray)
{
	bool			vis;
	t_list			*tmp;
	t_light			*light;
	t_light_infos	infos;

	tmp = scene.light;
	init_light(scene, ray, hit, &infos);
	while (tmp)
	{
		light = tmp->content;
		vis = is_shaded(scene, hit, light);
		if (vis == false)
		{
			diffuse(hit, light, &infos);
			specular(hit, light, &infos);
		}
		tmp = tmp->next;
	}
	return (assemble_light(infos));
}
