/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx_events.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <arguilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 09:00:59 by arguilla          #+#    #+#             */
/*   Updated: 2022/02/26 16:20:28 by arguilla         ###   ########.fr       */
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
	if (keycode == V_KEY)
	{
		minirt->scene->video_mode = !minirt->scene->video_mode;
		print_status(minirt);
	}
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

void	init_mlx_events(t_data *data, t_scene *scene)
{
	t_minirt	*minirt;

	minirt = alloc(sizeof(t_minirt), NULL);
	if (minirt == NULL)
		internal_error("unable to allocate memory");
	minirt->data = data;
	minirt->scene = scene;
	print_status(minirt);
	mlx_mouse_hook(data->win, &mouse_hook, minirt);
	mlx_hook(data->win, 33, 0, &destroy_window, data);
	mlx_key_hook(minirt->data->win, &key_events, minirt);
}
