/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx_events.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 09:00:59 by arguilla          #+#    #+#             */
/*   Updated: 2022/01/15 17:10:09 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	switch_object_type(int keycode, t_scene *scene)
{
	if (keycode == TAB_KEY)
		scene->object_type = !scene->object_type;
}

static int	key_events(int keycode, t_minirt *minirt)
{
	exit_window(keycode, minirt->data);
	switch_object_type(keycode, minirt->scene);
	if (minirt->scene->object_type == CAMERA)
		cameras_event(keycode, minirt);
	else if (minirt->scene->object_type == LIGHT)
		lights_event(keycode, minirt);
	printf("%d\n", keycode);
	return (1);
}

void	init_mlx_events(t_minirt *minirt)
{
	mlx_hook(minirt->data->win, 33, 0, &destroy_window, minirt->data);
	mlx_key_hook(minirt->data->win, &key_events, minirt);
}
