/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 19:47:46 by spoliart          #+#    #+#             */
/*   Updated: 2022/01/07 00:59:45 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_p3	parse_point(char *x, char *y, char *z)
{
	t_p3	point;

	point.x = ft_atof(x);
	point.y = ft_atof(y);
	point.z = ft_atof(z);
	return (point);
}

t_color	parse_color(char *r, char *g, char *b)
{
	t_color	color;

	color.r = ft_atof(r);
	color.g = ft_atof(g);
	color.b = ft_atof(b);
	if (check_color(color))
		internal_error("Color must be a number between 0 and 255");
	return (color);
}

int	check_color(t_color color)
{
	return (color.r < 0 || color.r > 255 || color.g < 0 || color.g > 255
		|| color.b < 0 || color.b > 255);
}

int	check_orientation(t_p3 dir)
{
	return (dir.x < (double)-1 || dir.x > (double)1
		|| dir.y < (double)-1 || dir.y > (double)1
		|| dir.z < (double)-1 || dir.z > (double)1);
}
