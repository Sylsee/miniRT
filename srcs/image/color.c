/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 12:46:35 by spoliart          #+#    #+#             */
/*   Updated: 2022/02/07 16:12:31 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	put_color(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->data + (y * data->line_bytes + x * (data->pixel_bits / 8));
	*(unsigned int *)dst = (unsigned int)color;
}

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
