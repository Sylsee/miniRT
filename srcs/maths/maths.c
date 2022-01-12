/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 16:24:33 by spoliart          #+#    #+#             */
/*   Updated: 2022/01/10 16:24:42 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	min(double a, double b)
{
	if (a > b)
		return (b);
	return (a);
}

double	max(double a, double b)
{
	if (a < b)
		return (b);
	return (a);
}
