/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 00:54:11 by spoliart          #+#    #+#             */
/*   Updated: 2022/03/30 00:58:25 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	switch_object_type(t_minirt *minirt)
{
	minirt->scene->object_type = !minirt->scene->object_type;
	print_status(minirt);
}

static bool	is_object_keycode(int keycode)
{
	return (keycode == CTRL_KEY || is_object_movement_keycode(keycode)
		|| is_object_properties_keycode(keycode));
}

int	key_events(int keycode, t_minirt *minirt)
{
	if (keycode == ESC_KEY)
		exit_minirt(minirt);
	else if (keycode == V_KEY)
		video_mode(minirt);
	else if (keycode == TAB_KEY)
		switch_object_type(minirt);
	else if (is_object_keycode(keycode)
		&& minirt->scene->obj && minirt->scene->obj->object)
		objects_event(keycode, minirt);
	else if (minirt->scene->object_type == CAMERA)
		cameras_event(keycode, minirt);
	else if (minirt->scene->object_type == LIGHT)
		lights_event(keycode, minirt);
	return (1);
}
