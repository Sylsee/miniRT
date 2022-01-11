/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mirror.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 16:23:23 by spoliart          #+#    #+#             */
/*   Updated: 2022/01/11 16:23:33 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	mirror(t_scene scene, t_vector ray, t_hit hit, int nb_rebound)
{
	t_vector	reflect;

	reflect.dir = v_sub(ray.dir, v_scale(hit.normal.dir,
				2 * v_dot(hit.normal.dir, ray.dir)));
	reflect.origin = v_add(hit.normal.origin, v_scale(hit.normal.dir, 0.00001));
	return (get_color(scene, reflect, nb_rebound - 1));
}
