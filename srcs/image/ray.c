/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 14:14:17 by spoliart          #+#    #+#             */
/*   Updated: 2022/01/13 21:21:36 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector	new_ray(t_cam *cam, t_scene scene, int x, int y)
{
	t_vector	ray;
	t_p3		tmp;
	t_p3		right;
	t_p3		up;
	const t_p3	random = {0, 1, 0};

	ray.origin = cam->origin;
	tmp.x = (2 * (((double)x + 0.5) / (double)scene.res.x) - 1)
		* tan((double)cam->fov / 2 * M_PI / 180)
		* (double)scene.res.x / (double)scene.res.y;
	tmp.y = (1 - 2 * (((double)y + 0.5) / (double)scene.res.y))
		* tan((double)cam->fov / 2 * M_PI / 180);
	tmp.z = 1;
	right = v_cross(random, cam->dir);
	normalize(&right);
	up = v_cross(cam->dir, right);
	normalize(&up);
	ray.dir.x = tmp.x * right.x + tmp.y * up.x + tmp.z * cam->dir.x;
	ray.dir.y = tmp.x * right.y + tmp.y * up.y + tmp.z * cam->dir.y;
	ray.dir.z = tmp.x * right.z + tmp.y * up.z + tmp.z * cam->dir.z;
	normalize(&ray.dir);
	return (ray);
}
