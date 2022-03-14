/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <arguilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 08:36:39 by arguilla          #+#    #+#             */
/*   Updated: 2022/03/10 23:35:45 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
