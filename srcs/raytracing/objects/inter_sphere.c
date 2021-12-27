/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 15:56:45 by spoliart          #+#    #+#             */
/*   Updated: 2021/12/25 23:51:20 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool	get_hit_infos(t_sphere *s, t_hit *hit, double t1, double t2)
{
	hit->color = s->color;
	if (t1 > 0)
	{
		hit->dist = t1;
/*		hit->pos.x = ;
		hit->pos.y = ;
		hit->pos.z = ;*/
		return (true);
	}
	else if (t2 > 0)
	{
		hit->dist = t2;
/*		hit->pos.x = ;
		hit->pos.y = ;
		hit->pos.z = ;*/
		return (true);
	}
	return (false);
}

int	inter_sphere(t_sphere *s, t_vector ray, t_hit *hit)
{
	double	b;
	double	c;
	double	delta;
	double	t1;
	double	t2;

	b = 2 * prod_scalaire(ray.orientation, vec_minus(ray.origin, s->pos));
	c = get_norm2(vec_minus(ray.origin, s->pos)) -
		(s->diameter / 2) * (s->diameter / 2);
	delta = b * b - 4 * c;
	if (delta < 0)
		return (false);
	t1 = (-b - sqrt(delta)) / 2;
	t2 = (-b + sqrt(delta)) / 2;
	return (get_hit_infos(s, hit, t1, t2));
}

/*
	a * t^2 + b*t + c = 0

	a = 1;
	b = 2 * prod_scalaire(u, vec_minus(c, o));
	c = pow(norma2(vec_minus(c, o)), 2) - pow(R, 2);

		avec:
			c = cam->vector.origin
			u = cam->vector.orientation
			o = sphere->pos
			R = sphere->diameter
*/
