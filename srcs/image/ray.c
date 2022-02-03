/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 14:14:17 by spoliart          #+#    #+#             */
/*   Updated: 2022/02/03 20:34:47 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector	new_ray(t_cam *cam, t_scene scene, double x, double y)
{
	t_vector	ray;
	t_p3		tmp;

	ray.origin = cam->origin;
	x = x / (scene.res.x - 1);
	y = y / (scene.res.y - 1);
	tmp = v_scale(cam->horizontal, x);
	ray.dir = v_add(cam->lower_corner, tmp);
	tmp = v_scale(cam->vertical, y);
	ray.dir = v_add(ray.dir, tmp);
	ray.dir = v_sub(ray.dir, cam->origin);
	normalize(&ray.dir);
	return (ray);
}
