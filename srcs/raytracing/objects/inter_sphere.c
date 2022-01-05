/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 15:56:45 by spoliart          #+#    #+#             */
/*   Updated: 2022/01/05 22:36:01 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	get_hit_infos(t_sphere *s, t_hit *hit, double t1, double t2)
{
	hit->color = s->color;
	if (t1 > 0)
		hit->dist = t1;
	else
		hit->dist = t2;
}

int	inter_sphere(t_sphere *s, t_vector ray, t_hit *hit)
{
	double	b;
	double	c;
	double	delta;
	double	t1;
	double	t2;

	b = 2 * prod_scalaire(ray.orientation, v_sub(ray.origin, s->pos));
	c = get_norm2(v_sub(ray.origin, s->pos)) -
		(s->diameter / 2) * (s->diameter / 2);
	delta = b * b - 4 * c;
	if (delta < 0)
		return (false);
	t1 = (-b - sqrt(delta)) / 2;
	t2 = (-b + sqrt(delta)) / 2;
	if (t2 > 0)
	{
		get_hit_infos(s, hit, t1, t2);
		return (true);
	}
	return (false);
}
