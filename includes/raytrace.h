/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 16:24:07 by spoliart          #+#    #+#             */
/*   Updated: 2022/02/09 20:13:20 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYTRACE_H
# define RAYTRACE_H

/*	LIGHT	*/
t_color	light(t_scene scene, t_hit hit);
int		is_shaded(t_scene scene, t_hit hit, t_light *light);

/*	MATERIAL_COLOR_COMPUTATION	*/
double	fresnel(t_p3 dir, t_hit hit);
t_color	reflection(t_scene scene, t_vector ray, t_hit hit, int nb_rebound);
t_color	refraction(t_scene scene, t_vector ray, t_hit hit, int nb_rebound);

#endif
