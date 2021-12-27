/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 14:14:17 by spoliart          #+#    #+#             */
/*   Updated: 2021/12/26 14:20:59 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector	new_ray(t_cam *cam, t_scene scene, int x, int y)
{
	t_vector	ray;

	ray.origin.x = cam->origin.x;
	ray.origin.y = cam->origin.y;
	ray.origin.z = cam->origin.z;
	ray.orientation.x = x - (scene.res.x / 2);
	ray.orientation.y = y - (scene.res.y / 2);
	ray.orientation.z = -scene.res.x / (2 * tan(cam->fov / 2));
	normalize(&ray.orientation);
	return (ray);
}
