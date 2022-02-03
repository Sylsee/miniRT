/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 20:28:05 by spoliart          #+#    #+#             */
/*   Updated: 2022/02/03 21:06:32 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_p3	z_rotation(t_p3 p, double theta)
{
	t_p3	tmp;

	theta *= M_PI / 180;
	tmp.x = cos(theta) * p.x - sin(theta) * p.y;
	tmp.x = sin(theta) * p.x + cos(theta) * p.y;
	tmp.z = p.z;
	return (tmp);
}

static void	set_lower_point(t_cam *cam)
{
	t_p3	focale;
	t_p3	tmp;

	focale = v_scale(cam->look_at, -1);
	tmp = v_div(cam->horizontal, 2);
	cam->lower_corner = v_sub(cam->origin, tmp);
	tmp = v_div(cam->vertical, 2);
	cam->lower_corner = v_sub(cam->lower_corner, tmp);
	cam->lower_corner = v_sub(cam->lower_corner, focale);
}

void	param_cam(t_cam *cam, double w, double h)
{
	double	ratio;
	t_p3	focale;
	t_p3	cross;

	ratio = w / h;
	cam->pov_w = 2.0 * cam->fov;
	cam->pov_h = cam->pov_w * ratio;
	focale = v_scale(cam->look_at, -1);
	cross = v_cross(cam->v_up, focale);
	if (get_norm(cross) == 0)
		cross = z_rotation(focale, 90);
	normalize(&cross);
	cam->horizontal = v_scale(cross, cam->pov_w);
	cross = v_cross(focale, cross);
	normalize(&cross);
	cam->vertical = v_scale(cross, cam->pov_h);
	set_lower_point(cam);
}
