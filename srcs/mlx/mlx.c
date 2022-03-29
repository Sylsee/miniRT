/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 23:59:22 by spoliart          #+#    #+#             */
/*   Updated: 2022/03/30 00:25:14 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
**	Initialize minilibx utilities
*/
void	init_mlx(t_data *data, t_scene *scene)
{
	int	x;
	int	y;

	data->mlx = mlx_init();
	if (!data->mlx)
		internal_error("unable to initialize minilibx");
	mlx_get_screen_size(data->mlx, &x, &y);
	if (scene->res.x > x)
		scene->res.x = x;
	if (scene->res.y > y)
		scene->res.y = y;
	if (data->save == false)
	{
		data->win = mlx_new_window(data->mlx, scene->res.x,
				scene->res.y, "MiniRT");
		if (!data->win)
			internal_error("unable to create minilibx window");
	}
	data->img = mlx_new_image(data->mlx, scene->res.x, scene->res.y);
	if (!data->img)
		internal_error("unable to create minilibx image");
	data->data = mlx_get_data_addr(data->img, &data->pixel_bits,
			&data->line_bytes, &data->endian);
}

void	free_mlx(t_data data)
{
	mlx_destroy_image(data.mlx, data.img);
	mlx_destroy_window(data.mlx, data.win);
	mlx_destroy_display(data.mlx);
	free(data.mlx);
}
