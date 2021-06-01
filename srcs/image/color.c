/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 12:46:35 by spoliart          #+#    #+#             */
/*   Updated: 2021/06/01 20:08:29 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

int	get_opposite(int color)
{
	return (create_rgb(((color & (0xFF << 16)) ^ (0xFF << 16)) >> 16,
			((color & 0xFF << 8) ^ (0xFF << 8)) >> 8,
			(color & 0xFF) ^ 0xFF));
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
