/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_object.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:55:28 by spoliart          #+#    #+#             */
/*   Updated: 2022/01/12 21:51:48 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	select_object(int x, int y, t_scene *scene)
{
	t_vector	ray;
	t_hit		hit;

	ray = new_ray(scene.cam->content, scene, x, y);
	hit = intersection(scene, ray, 2);
	if (hit.dist == -1)
		return ;
	scene->id_current_obj = hit->type;
	scene->current_obj = hit->object;
}
