/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <arguilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 13:00:46 by arguilla          #+#    #+#             */
/*   Updated: 2022/02/26 16:27:17 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	update_window(t_minirt *minirt)
{
	mlx_clear_window(minirt->data->mlx, minirt->data->win);
	create_img(minirt->data, *(minirt->scene));
	mlx_put_image_to_window(minirt->data->mlx,
		minirt->data->win, minirt->data->img, 0, 0);
	if (minirt->scene->video_mode)
		create_bmp(*(minirt->data), *(minirt->scene));
	print_status(minirt);
}
