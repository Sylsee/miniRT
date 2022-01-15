/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cameras_event.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 17:52:24 by arguilla          #+#    #+#             */
/*   Updated: 2022/01/15 20:26:48 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	switch_camera(int keycode, t_minirt *minirt)
{
	if (keycode == Q_KEY)
		minirt->scene->cam = minirt->scene->cam->next;
	if (keycode == E_KEY)
		minirt->scene->cam = minirt->scene->cam->prev;
	update_window(minirt);
}

static void	init_coord(t_p3 **coord, t_p3 *size, t_scene *scene)
{
	if (scene->camera_mode == TRANSLATION)
	{
		*coord = &scene->cam->origin;
		size->x = X_TRANSLATION_SIZE;
		size->y = Y_TRANSLATION_SIZE;
		size->z = Z_TRANSLATION_SIZE;
	}
	else
	{
		*coord = &scene->cam->dir;
		size->x = X_ROTATION_SIZE;
		size->y = Y_ROTATION_SIZE;
		size->z = Z_ROTATION_SIZE;
	}
}

static void	move_camera(int keycode, t_minirt *minirt)
{
	t_p3	*coord;
	t_p3	size;

	init_coord(&coord, &size, minirt->scene);
	if (keycode == D_KEY)
		coord->x += size.x;
	else if (keycode == A_KEY)
		coord->x -= size.x;
	else if (keycode == W_KEY)
		coord->y += size.y;
	else if (keycode == S_KEY)
		coord->y -= size.y;
	else if (keycode == R_KEY)
		coord->z += size.z;
	else if (keycode == T_KEY)
		coord->z -= size.z;
	if (minirt->scene->cam->dir.x == 0
		&& minirt->scene->cam->dir.y != 0 && minirt->scene->cam->dir.z == 0)
		minirt->scene->cam->dir.x = 0.000000001;
	update_window(minirt);
}

void	cameras_event(int keycode, t_minirt *minirt)
{
	if ((keycode == Q_KEY || keycode == E_KEY) && minirt->scene->cam->next)
		switch_camera(keycode, minirt);
	if (keycode == CAPS_KEY)
		minirt->scene->camera_mode = !minirt->scene->camera_mode;
	if (is_movement_keycode(keycode))
		move_camera(keycode, minirt);
}
