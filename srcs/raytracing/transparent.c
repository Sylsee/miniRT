/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transparent.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 23:47:33 by spoliart          #+#    #+#             */
/*   Updated: 2022/02/05 23:57:54 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	fresnel(t_scene scene, t_vector ray, t_hit hit)
{
	t_vector	new_ray;

	new_ray.origin = v_add(hit.normal.origin, v_scale(hit.normal.dir, -0.001 ));
	new_ray.dir = ;
	return (get_color(scene, new_ray, nb_rebound - 1));
}
