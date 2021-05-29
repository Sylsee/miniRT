/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersec_sphere.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 15:56:45 by spoliart          #+#    #+#             */
/*   Updated: 2021/05/26 01:11:22 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	inter_sphere(t_sphere *s, t_vector ray)
{
	double b;
	double c;
	double t;
	double t1;
	double t2;

	b = 2 * prod_scalaire(ray.orientation,
			vec_minus(ray.origin, s->pos));
	c = norma2(vec_minus(ray.origin, s->pos)) -
		s->diameter * s->diameter;
	if ((t = b * b - 4 * c) < 0)
		return (0);
	t1 = (-b - sqrt(t)) / (2);
	t2 = (-b + sqrt(t)) / (2);
	(void)t1;
	if (t2 > 0)
		return (1);
	return (0);
}

/*
	a * t^2 + b*t + c = 0

	a = 1;
	b = 2 * prod_scalaire(u, vec_minus(c, o));
	c = pow(norma2(vec_minus(c, o)), 2) - pow(R, 2);

		avec:
			c = cam->vector.origin
			u = cam->vector.direction
			o = sphere->pos
			R = sphere->diameter
*/
