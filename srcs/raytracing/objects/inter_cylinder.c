/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 12:04:10 by spoliart          #+#    #+#             */
/*   Updated: 2022/01/16 15:47:18 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool	get_hit_infos(t_cylinder *cy, t_hit *hit)
{
	hit->color = cy->color;
	hit->mirror = cy->mirror;
	normalize(&hit->normal.dir);
	return (true);
}

static bool	get_dist(t_cylinder *cy, t_vector ray, t_hit *hit, double *t)
{
	double		max;

	if (t[0] > 0)
		hit->dist = t[0];
	else
		hit->dist = t[1];
	max = sqrt(pow(cy->height / 2, 2) + pow(cy->diameter, 2));
	hit->normal.origin = v_add(ray.origin, v_scale(ray.dir, hit->dist));
	hit->normal.dir = v_sub(hit->normal.origin, cy->pos);
	if (get_norm(hit->normal.dir) > max)
	{
		hit->dist = t[1];
		hit->normal.origin = v_add(ray.origin, v_scale(ray.dir, hit->dist));
		hit->normal.dir = v_sub(hit->normal.origin, cy->pos);
		if (get_norm(hit->normal.dir) > max)
			return (false);
	}
	return (true);
}

static bool	solve_determinant(t_cylinder *cy, t_vector ray, t_hit *hit)
{
	double	a;
	double	b;
	double	c;
	double	delta;
	double	t[2];

	a = get_norm2(v_cross(ray.dir, cy->dir));
	b = 2 * v_dot(v_cross(ray.dir, cy->dir),
		v_cross(v_sub(ray.origin, cy->pos), cy->dir));
	c = get_norm2(v_cross(v_sub(ray.origin, cy->pos), cy->dir))
		- (cy->diameter / 2) * (cy->diameter / 2);
	delta = b * b - 4 * a * c;
	if (delta < 0)
		return (false);
	t[0] = (-b - sqrt(delta)) / (2 * a);
	t[1] = (-b + sqrt(delta)) / (2 * a);
	return (get_dist(cy, ray, hit, t));
}

bool	inter_cylinder(t_cylinder *cy, t_vector ray, t_hit *hit, int mode)
{
	bool	has_inter;

	has_inter = solve_determinant(cy, ray, hit);
	if (has_inter == true)
	{
		if (mode == 1)
			return (get_hit_infos(cy, hit));
		else if (mode == 2)
		{
			hit->type = CYLINDER;
			hit->object = cy;
		}
		return (true);
	}
	return (false);
}
