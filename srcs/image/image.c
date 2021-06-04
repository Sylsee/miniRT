/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 22:25:02 by spoliart          #+#    #+#             */
/*   Updated: 2021/06/04 21:33:55 by spoliart         ###   ########.fr       */
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

void	create_img(t_minirt *minirt, t_scene *scene, t_cam *cam)
{
	int			x;
	int			y;

	y = scene->res.y + 1;
	while (y--)
	{
		x = scene->res.x + 1;
		while (x--)
		{
			normalize(&(ray.orientation));
			if (intersec_obj(s, ray))
				my_mlx_pixel_put(minirt, x, y, color);
		}
	}
}
