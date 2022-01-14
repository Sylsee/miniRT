/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 15:56:45 by spoliart          #+#    #+#             */
/*   Updated: 2022/01/12 22:30:26 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	get_hit_infos(t_sphere *s, t_vector ray, t_hit *hit)
{
	hit->color = s->color;
	hit->mirror = s->mirror;
	hit->normal.origin = v_add(ray.origin, v_scale(ray.dir, hit->dist));
	hit->normal.dir = v_sub(hit->normal.origin, s->pos);
	normalize(&hit->normal.dir);
}

static double	*solve_determinant(t_sphere *s, t_vector ray, double *t)
{
	double	b;
	double	c;
	double	delta;

	b = 2 * v_dot(ray.dir, v_sub(ray.origin, s->pos));
	c = get_norm2(v_sub(ray.origin, s->pos))
		- (s->diameter / 2) * (s->diameter / 2);
	delta = b * b - 4 * c;
	if (delta < 0)
		return (NULL);
	t[0] = (-b - sqrt(delta)) / 2;
	t[1] = (-b + sqrt(delta)) / 2;
	return (t);
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

bool	inter_sphere(t_sphere *s, t_vector ray, t_hit *hit, int mode)
{
	double	thief[2];
	double	*t;

	t = solve_determinant(s, ray, thief);
	if (t != NULL && t[1] > 0)
	{
		if (t[0] > 0)
			hit->dist = t[0];
		else
			hit->dist = t[1];
		if (mode == 1)
			get_hit_infos(s, ray, hit);
		else if (mode == 2)
		{
			hit->type = SPHERE;
			hit->object = s;
		}
		return (true);
	}
	return (false);
}
