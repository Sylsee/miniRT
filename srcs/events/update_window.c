/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 13:00:46 by arguilla          #+#    #+#             */
/*   Updated: 2022/01/15 23:48:20 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	update_window(t_minirt *minirt)
{
	mlx_clear_window(minirt->data->mlx, minirt->data->win);
	create_img(minirt->data, *(minirt->scene));
	mlx_put_image_to_window(minirt->data->mlx,
		minirt->data->win, minirt->data->img, 0, 0);
	print_status(minirt);
}
