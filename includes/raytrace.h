/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 16:24:07 by spoliart          #+#    #+#             */
/*   Updated: 2022/03/07 18:49:24 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYTRACE_H
# define RAYTRACE_H

/*	LIGHT	*/
typedef struct s_light_infos
{
	t_color		specular_color;
	t_color		ambient_color;
	t_color		diffuse_color;
	t_vector	ray;
}				t_light_infos;

t_color		light(t_scene scene, t_hit hit, t_vector ray);
bool		is_shaded(t_scene scene, t_hit hit, t_light *light);

/*	MATERIAL_COLOR_COMPUTATION	*/
t_color		compute_material(t_scene scene, t_vector ray, t_hit hit,
				int nb_rebound);
t_color		mirror(t_scene scene, t_vector ray, t_hit hit, int nb_rebound);
double		fresnel(t_p3 dir, t_hit hit);
t_vector	reflect(t_vector v1, t_vector v2);
t_color		reflection(t_scene scene, t_vector ray, t_hit hit, int nb_rebound);
t_color		refraction(t_scene scene, t_vector ray, t_hit hit, int nb_rebound);

#endif
