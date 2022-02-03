/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 16:24:07 by spoliart          #+#    #+#             */
/*   Updated: 2022/02/03 21:43:52 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYTRACE_H
# define RAYTRACE_H

/*	LIGHT	*/
t_color	light(t_scene scene, t_hit hit);
int		is_shaded(t_scene scene, t_hit hit, t_light *light);

/*	MIRROR	*/
int		mirror(t_scene scene, t_vector ray, t_hit hit, int nb_rebound);

#endif
