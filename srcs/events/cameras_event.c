/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cameras_event.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 17:52:24 by arguilla          #+#    #+#             */
/*   Updated: 2022/01/12 20:51:42 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	cameras_event(int keycode, t_minirt *minirt)
{
	if (keycode == Q_KEY)
	{
	//	minirt->scene->cam = minirt->scene->cam->next;
		printf("%d\n", minirt->scene->obj->id);	
	//	printf("%d\n", minirt->scene->cam->id);
	minirt->scene->obj = minirt->scene->obj->next;
	}

	if (keycode == E_KEY)
	{
		printf("E event\n");
		printf("%d\n", minirt->scene->obj->id);	
		minirt->scene->cam = minirt->scene->cam->next;
	//	mlx_destroy_window(minirt->data->mlx, minirt->data->win);

/*	minirt->data->img = mlx_new_image(minirt->data->mlx, minirt->scene->res.x, minirt->scene->res.y);
	if (!minirt->data->img)
		internal_error("unable to create minilibx image");
	minirt->data->data = mlx_get_data_addr(minirt->data->img, &minirt->data->pixel_bits,
			&minirt->data->line_bytes, &minirt->data->endian);
*/	
	mlx_clear_window(minirt->data->mlx, minirt->data->win);	
	create_img(minirt->data, *(minirt->scene));
	mlx_put_image_to_window(minirt->data->mlx, minirt->data->win, minirt->data->img, 0, 0);
	}
	// orientation
	// x et z == 0 et y != 0
	// x = 0.0001
	return (1);
}
