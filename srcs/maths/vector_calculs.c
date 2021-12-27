/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_calculs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 15:36:04 by spoliart          #+#    #+#             */
/*   Updated: 2021/12/26 14:37:02 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_coord	vec_minus(t_coord v, t_coord u)
{
	t_coord	ret;

	ret.x = v.x - u.x;
	ret.y = v.y - u.y;
	ret.z = v.z - u.z;
	return (ret);
}

t_coord	vec_add(t_coord v, t_coord u)
{
	t_coord	ret;

	ret.x = v.x + u.x;
	ret.y = v.y + u.y;
	ret.z = v.z + u.z;
	return (ret);
}

double	prod_scalaire(t_coord v, t_coord u)
{
	return (v.x * u.x + v.y * u.y + v.z * u.z);
}

double	get_norm2(t_coord v)
{
	return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}

void	normalize(t_coord *v)
{
	double	norme;

	norme = get_norm2(*v);
	v->x /= norme;
	v->y /= norme;
	v->z /= norme;
}
