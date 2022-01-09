/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 15:56:45 by spoliart          #+#    #+#             */
/*   Updated: 2022/01/07 14:25:27 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool	get_hit_infos(t_sphere *s, t_vector ray, t_hit *hit, double t[2])
{
	hit->color = s->color;
	if (t[0] > 0)
		hit->dist = t[0];
	else
		hit->dist = t[1];
	hit->normal.origin = v_add(ray.origin, v_scale(ray.dir, hit->dist));
	hit->normal.dir = v_sub(hit->normal.origin, s->pos);
	normalize(&hit->normal.dir);
	return (true);
}

/*
**	Solve the sphere / line  equation (a*t^2 + b*t + c = 0)
**
**	@param	s	=>	Structure contains the sphere infos
**	@param	ray	=>	Structure contains the ray / line infos
**	@param	hit	=>	Structure to fill if there is an intersection
**
**	@return true if there is an intersection, else false
*/

int	inter_sphere(t_sphere *s, t_vector ray, t_hit *hit)
{
	double	b;
	double	c;
	double	delta;
	double	t[2];

	b = 2 * v_dot(ray.dir, v_sub(ray.origin, s->pos));
	c = get_norm2(v_sub(ray.origin, s->pos))
		- (s->diameter / 2) * (s->diameter / 2);
	delta = b * b - 4 * c;
	if (delta < 0)
		return (false);
	t[0] = (-b - sqrt(delta)) / 2;
	t[1] = (-b + sqrt(delta)) / 2;
	if (t[1] > 0)
		return (get_hit_infos(s, ray, hit, t));
	return (false);
}
