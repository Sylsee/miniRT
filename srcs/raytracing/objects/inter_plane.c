/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 16:26:32 by spoliart          #+#    #+#             */
/*   Updated: 2022/01/11 18:52:25 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static double	f_abs(double n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static bool	get_hit_infos(t_plane *p, t_vector ray, t_hit *hit)
{
	t_p3	s1;
	t_p3	s2;

	hit->color = p->color;
	hit->mirror = p->mirror;
	hit->normal.origin = v_add(ray.origin, v_scale(ray.dir, hit->dist));
	s1 = v_add(ray.dir, p->dir);
	s2 = v_add(ray.dir, v_scale(p->dir, -1));
	if (get_norm(s1) < get_norm(s2))
		hit->normal.dir = p->dir;
	else
		hit->normal.dir = v_scale(p->dir, -1);
	return (true);
}

bool	inter_plane(t_plane *p, t_vector ray, t_hit *hit)
{
	double	denom;

	denom = v_dot(p->dir, ray.dir);
	if (f_abs(denom) > 0.0001f)
	{
		hit->dist = v_dot(v_sub(p->pos, ray.origin), p->dir) / denom;
		if (hit->dist >= 0)
			return (get_hit_infos(p, ray, hit));
	}
	return (false);
}
