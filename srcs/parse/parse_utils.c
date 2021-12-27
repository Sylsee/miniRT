/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 19:47:46 by spoliart          #+#    #+#             */
/*   Updated: 2021/12/15 23:26:16 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_coord	parse_coord(char *x, char *y, char *z)
{
	t_coord	coord;

	coord.x = ft_atof(x);
	coord.y = ft_atof(y);
	coord.z = ft_atof(z);
	return (coord);
}

t_color	parse_color(char *r, char *g, char *b)
{
	t_color	color;

	color.r = ft_atof(r);
	color.g = ft_atof(g);
	color.b = ft_atof(b);
	if (check_color(color))
		internal_error("Color must be a number beetween 0 and 255");
	return (color);
}

int		check_color(t_color color)
{
	return (color.r < 0 || color.r > 255 || color.g < 0 || color.g > 255 ||
			color.b < 0 || color.b > 255);
}

int		check_orientation(t_coord orientation)
{
	return (orientation.x < -1 || orientation.x > 1 || orientation.y < -1 ||
			orientation.y > 1 || orientation.z < -1 || orientation.z > 1);
}
