/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fresnel.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 16:25:40 by spoliart          #+#    #+#             */
/*   Updated: 2022/02/09 16:25:48 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	fresnel(t_p3 dir, t_hit hit)
{
	double	r[2];
	double	kr;
	double	cos[2];
	double	eta[3];
	double	sint;

	cos[0] = max(-1, min(1, v_dot(dir, hit.normal.dir)));
	eta[0] = 1;
	eta[1] = hit.ior;
	if (cos[0] > 0)
	{
		eta[2] = eta[0];
		eta[0] = eta[1];
		eta[1] = eta[2];
	}
	sint = eta[0] / eta[1] * sqrtf((float)max(0., 1 - cos[0] * cos[0]));
	if (sint >= 1)
		kr = 1;
	else
	{
		cos[1] = sqrtf((float)max(0., 1 - sint * sint));
		cos[0] = fabsf((float)cos[0]);
		r[0] = ((eta[1] * cos[0]) - (eta[0] * cos[1]))
			/ ((eta[1] * cos[0]) + (eta[0] * cos[1]));
		r[1] = ((eta[0] * cos[0]) - (eta[1] * cos[1]))
			/ ((eta[0] * cos[0]) + (eta[1] * cos[1]));
		kr = (r[0] * r[0] + r[1] * r[1]) / 2;
	}
	return (kr);
}
