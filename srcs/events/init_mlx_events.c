/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx_events.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 09:00:59 by arguilla          #+#    #+#             */
/*   Updated: 2022/01/18 22:12:40 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	switch_object_type(int keycode, t_minirt *minirt)
{
	if (keycode != TAB_KEY)
		return ;
	minirt->scene->object_type = !minirt->scene->object_type;
	print_status(minirt);
}

static int	key_events(int keycode, t_minirt *minirt)
{
	exit_window(keycode, minirt->data);
	switch_object_type(keycode, minirt);
	if (minirt->scene->obj && minirt->scene->obj->object)
		objects_event(keycode, minirt);
	if (minirt->scene->object_type == CAMERA)
		cameras_event(keycode, minirt);
	else if (minirt->scene->object_type == LIGHT)
		lights_event(keycode, minirt);
	return (1);
}

void	init_mlx_events(t_minirt *minirt)
{
	print_status(minirt);
	mlx_hook(minirt->data->win, 33, 0, &destroy_window, minirt->data);
	mlx_key_hook(minirt->data->win, &key_events, minirt);
}
