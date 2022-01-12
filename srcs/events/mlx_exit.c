/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 08:36:39 by arguilla          #+#    #+#             */
/*   Updated: 2022/01/11 21:08:12 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	exit_window(int keycode, t_data *data)
{
	if (keycode == ESC)
		destroy_window(data);
	return (1);
}

int	destroy_window(t_data *data)
{
	printf("exit event\n");
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	exit(0);
}
