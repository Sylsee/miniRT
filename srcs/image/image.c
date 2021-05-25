/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 22:25:02 by spoliart          #+#    #+#             */
/*   Updated: 2021/05/26 01:05:44 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <math.h>

void	put_color(t_minirt *minirt, t_scene *scene, int x, int y)
{
	minirt->data[(y * scene->res.x + x) * 3] = 255;
	minirt->data[(y * scene->res.x + x) * 3 + 1] = 255;
	minirt->data[(y * scene->res.x + x) * 3 + 2] = 255;
}

void	create_img(t_minirt *minirt, t_scene *scene)
{
	int			x;
	int			y;
	t_sphere	*s;
	t_cam		*cam;
	t_vector	ray;

	cam = (t_cam *)scene->cam->content;
	s = (t_sphere *)scene->obj->content;
	y = scene->res.y + 1;
	while (y--)
	{
		x = scene->res.x + 1;
		while (x--)
		{
			ray = (t_vector){(t_coord){cam->vector.origin.x, cam->vector.origin.y, cam->vector.origin.z}, (t_coord){x -
				scene->res.x / 2, y - scene->res.y / 2, -(scene->res.x) /
				(2 * tan(cam->fov / 2))}};
			normalize(&(ray.orientation));
			if (inter_sphere(s, ray))
				put_color(minirt, scene, x, y);
		}
	}
}
