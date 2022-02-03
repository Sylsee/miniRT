/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 12:04:10 by spoliart          #+#    #+#             */
/*   Updated: 2022/02/03 21:35:10 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	get_hit_infos(t_cylinder *cy, t_hit *hit, t_vector ray)
{
	double	a;

	hit->color = cy->color;
	hit->mirror = cy->mirror;
	a = v_dot(cy->dir, v_sub(hit->normal.origin, cy->pos));
	hit->normal.dir = get_normalize(v_sub(hit->normal.origin,
				v_add(cy->pos, v_scale(cy->dir, a))));
	a = v_dot(ray.dir, hit->normal.dir);
	if (a > 0)
		hit->normal.dir = v_scale(hit->normal.dir, -1);
}

static bool	get_normal(t_cylinder *cy, t_vector ray, t_hit *hit, double *t)
{
	double	max;

	if (t[0] > 0)
		hit->dist = t[0];
	else
		hit->dist = t[1];
	max = sqrt(pow(cy->height / 2., 2) + pow(cy->diameter / 2., 2));
	hit->normal.origin = v_add(ray.origin, v_scale(ray.dir, hit->dist));
	if (get_norm(v_sub(hit->normal.origin, cy->pos)) > max)
	{
		hit->dist = t[1];
		hit->normal.origin = v_add(ray.origin, v_scale(ray.dir, hit->dist));
		if (get_norm(v_sub(hit->normal.origin, cy->pos)) > max)
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

	normalize(&cy->dir);
	a = v_dot(v_cross(ray.dir, cy->dir), v_cross(ray.dir, cy->dir));
	b = 2 * v_dot(v_cross(ray.dir, cy->dir),
			v_cross(v_sub(ray.origin, cy->pos), cy->dir));
	c = v_dot(v_cross(v_sub(ray.origin, cy->pos), cy->dir),
			v_cross(v_sub(ray.origin, cy->pos), cy->dir))
		- (cy->diameter / 2) * (cy->diameter / 2);
	delta = b * b - 4 * a * c;
	if (delta < 0)
		return (false);
	t[0] = (-b - sqrt(delta)) / (2 * a);
	t[1] = (-b + sqrt(delta)) / (2 * a);
	if (t[1] < 0)
		return (false);
	return (get_normal(cy, ray, hit, t));
}

bool	inter_cylinder(t_cylinder *cy, t_vector ray, t_hit *hit, int mode)
{
	bool	has_inter;

	has_inter = solve_determinant(cy, ray, hit);
	if (has_inter == false)
		return (false);
	if (mode == 1)
		get_hit_infos(cy, hit, ray);
	else if (mode == 2)
	{
		hit->type = CYLINDER;
		hit->object = cy;
	}
	return (true);
}
