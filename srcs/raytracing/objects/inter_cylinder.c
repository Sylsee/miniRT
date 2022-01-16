/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 12:04:10 by spoliart          #+#    #+#             */
/*   Updated: 2022/01/16 01:59:29 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool	get_hit_infos(t_cylinder *cy, t_vector ray, t_hit *hit, double *t)
{
	double		t_;
	double		max;
	t_vector	p;

	if (t[0] > 0)
		t_ = t[0];
	else
		t_ = t[1];
	max = sqrt(pow(cy->height / 2, 2) + pow(cy->diameter, 2));
	p.origin = v_add(ray.origin, v_scale(ray.dir, t_));
	p.dir = v_sub(p.origin, cy->pos);
	if (get_norm(p.dir) > max)
	{
		t_ = t[1];
		p.origin = v_add(ray.origin, v_scale(ray.dir, t_));
		p.dir = v_sub(p.origin, cy->pos);
		if (get_norm(p.dir) > max)
			return (false);
	}
	hit->color = cy->color;
	hit->mirror = cy->mirror;
	hit->normal.origin = p.origin;
	normalize(&hit->normal.dir);
	return (true);
}

static double	*solve_determinant(t_cylinder *cy, t_vector ray, double *t)
{
	double	a;
	double	b;
	double	c;
	double	delta;

	a = get_norm2(v_cross(ray.dir, cy->dir));
	b = 2 * v_dot(v_cross(ray.dir, cy->dir),
		v_cross(v_sub(ray.origin, cy->pos), cy->dir));
	c = get_norm2(v_cross(v_sub(ray.origin, cy->pos), cy->dir))
		- (cy->diameter / 2) * (cy->diameter / 2);
	delta = b * b - 4 * a * c;
	if (delta < 0)
		return (NULL);
	t[0] = (-b - sqrt(delta)) / (2 * a);
	t[1] = (-b + sqrt(delta)) / (2 * a);
	return (t);
}

bool	inter_cylinder(t_cylinder *cy, t_vector ray, t_hit *hit, int mode)
{
	double	thief[2];
	double	*t;

	t = solve_determinant(cy, ray, thief);
	if (t != NULL && t[1] > 0)
	{
		if (mode == 1)
			return (get_hit_infos(cy, ray, hit, t));
		else if (mode == 2)
		{
			hit->type = CYLINDER;
			hit->object = cy;
		}
		return (true);
	}
	return (false);
}
