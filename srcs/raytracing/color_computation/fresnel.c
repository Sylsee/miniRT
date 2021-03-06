/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fresnel.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 16:25:40 by spoliart          #+#    #+#             */
/*   Updated: 2022/02/12 22:36:54 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static double	get_kr(double eta[3], double cosi, double sint)
{
	double	rs;
	double	rp;
	double	cost;

	cost = sqrt(max(0., 1 - sint * sint));
	cosi = fabs(cosi);
	rs = ((eta[1] * cosi) - (eta[0] * cost))
		/ ((eta[1] * cosi) + (eta[0] * cost));
	rp = ((eta[0] * cosi) - (eta[1] * cost))
		/ ((eta[0] * cosi) + (eta[1] * cost));
	return ((rs * rs + rp * rp) / 2);
}

double	fresnel(t_p3 dir, t_hit hit)
{
	double	cosi;
	double	eta[2];
	double	sint;

	cosi = max(-1, min(1, v_dot(dir, hit.normal.dir)));
	eta[0] = AIR_REFRACTIVE_IMPACT;
	eta[1] = hit.ior;
	if (cosi > 0)
	{
		eta[0] = hit.ior;
		eta[1] = AIR_REFRACTIVE_IMPACT;
	}
	sint = eta[0] / eta[1] * sqrt(max(0., 1 - cosi * cosi));
	if (sint >= 1)
		return (1.f);
	return (get_kr(eta, cosi, sint));
}
