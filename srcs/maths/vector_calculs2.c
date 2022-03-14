/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_calculs2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 21:33:51 by spoliart          #+#    #+#             */
/*   Updated: 2022/02/03 21:33:58 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	v_dot(t_p3 v, t_p3 u)
{
	return (v.x * u.x + v.y * u.y + v.z * u.z);
}

double	get_norm2(t_p3 v)
{
	return (v.x * v.x + v.y * v.y + v.z * v.z);
}

double	get_norm(t_p3 v)
{
	return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}

void	normalize(t_p3 *v)
{
	double	norme;

	norme = get_norm(*v);
	v->x /= norme;
	v->y /= norme;
	v->z /= norme;
}

t_p3	get_normalize(t_p3 v)
{
	t_p3	res;
	double	norme;

	norme = get_norm(v);
	res.x = v.x / norme;
	res.y = v.y / norme;
	res.z = v.z / norme;
	return (res);
}
