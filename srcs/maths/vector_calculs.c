/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_calculs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 15:36:04 by spoliart          #+#    #+#             */
/*   Updated: 2022/02/03 21:33:45 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_p3	v_sub(t_p3 v, t_p3 u)
{
	t_p3	ret;

	ret.x = v.x - u.x;
	ret.y = v.y - u.y;
	ret.z = v.z - u.z;
	return (ret);
}

t_p3	v_add(t_p3 v, t_p3 u)
{
	t_p3	ret;

	ret.x = v.x + u.x;
	ret.y = v.y + u.y;
	ret.z = v.z + u.z;
	return (ret);
}

t_p3	v_scale(t_p3 v, double f)
{
	t_p3	ret;

	ret.x = v.x * f;
	ret.y = v.y * f;
	ret.z = v.z * f;
	return (ret);
}

t_p3	v_div(t_p3 v, double f)
{
	t_p3	ret;

	ret.x = v.x / f;
	ret.y = v.y / f;
	ret.z = v.z / f;
	return (ret);
}

t_p3	v_cross(t_p3 u, t_p3 v)
{
	t_p3	res;

	res.x = u.y * v.z - u.z * v.y;
	res.y = u.z * v.x - u.x * v.z;
	res.z = u.x * v.y - u.y * v.x;
	return (res);
}
