/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <arguilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 08:36:39 by arguilla          #+#    #+#             */
/*   Updated: 2022/02/27 11:08:47 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

#define ESC 65307

int	exit_window(int keycode, t_minirt *minirt)
{
	if (keycode == ESC)
		destroy_window(minirt);
	return (1);
}

int	destroy_window(t_minirt *minirt)
{
	if (minirt->scene->frame_index > 0)
		create_video(minirt);
	mlx_destroy_image(minirt->data->mlx, minirt->data->img);
	mlx_destroy_window(minirt->data->mlx, minirt->data->win);
	mlx_destroy_display(minirt->data->mlx);
	free(minirt->data->mlx);
	exit(0);
}
