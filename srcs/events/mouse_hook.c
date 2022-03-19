/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 16:14:53 by spoliart          #+#    #+#             */
/*   Updated: 2022/03/19 21:35:01 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool	select_object(int x, int y, t_scene *scene)
{
	t_vector	ray;
	t_hit		hit;

	ray = new_ray(scene->cam, *scene, x, y);
	hit = intersection(scene->obj, ray, 2);
	if (hit.dist == -1)
		return (false);
	scene->id_current_obj = hit.type;
	scene->current_obj = hit.object;
	return (true);
}

int	mouse_hook(int mouse_code, int x, int y, t_minirt *minirt)
{
	if (mouse_code == RIGHT_CLICK)
	{
		if (select_object(x, y, minirt->scene) == true)
			print_status(minirt);
	}
	return (0);
}
