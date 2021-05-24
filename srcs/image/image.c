/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 22:25:02 by spoliart          #+#    #+#             */
/*   Updated: 2021/05/24 23:03:48 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	create_img(t_minirt *minirt, t_scene *scene)
{
	int	x;
	int	y;
	int	color;

	y = scene->res.y + 1;
	while (y--)
	{
		x = scene->res.x + 1;
		while (x--)
		{
			color = get_color();
			minirt->data = ((unsigned char)color);
		}
	}
}
