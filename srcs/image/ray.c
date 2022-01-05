/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 14:14:17 by spoliart          #+#    #+#             */
/*   Updated: 2022/01/05 22:52:53 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector	new_ray(t_cam *cam, t_scene scene, int x, int y)
{
	double		fov;
	t_vector	ray;

	fov = cam->fov * (M_PI / 180);
	ray.origin = cam->origin;
	ray.orientation.x = x - (scene.res.x / 2);
	ray.orientation.y = y - (scene.res.y / 2);
	ray.orientation.z = -(scene.res.x) / (2 * tan(fov / 2));
	normalize(&ray.orientation);
	ray.orientation.x = cam->orientation.x * (sqrt(get_norm2(ray.orientation))
		/ sqrt(get_norm2(cam->orientation)));
	ray.orientation.y = cam->orientation.y * (sqrt(get_norm2(ray.orientation))
		/ sqrt(get_norm2(cam->orientation)));
	ray.orientation.z = cam->orientation.z * (sqrt(get_norm2(ray.orientation))
		/ sqrt(get_norm2(cam->orientation)));
	return (ray);
}
