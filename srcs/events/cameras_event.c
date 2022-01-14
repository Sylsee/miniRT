/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cameras_event.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 17:52:24 by arguilla          #+#    #+#             */
/*   Updated: 2022/01/14 16:11:14 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void switch_camera(int keycode, t_minirt *minirt)
{
	if (keycode == Q_KEY)
		minirt->scene->cam = minirt->scene->cam->next;
	if (keycode == E_KEY)
		minirt->scene->cam = minirt->scene->cam->prev;
	update_window(minirt);
}

static bool	is_movement_keycode(int keycode)
{
	return (keycode == W_KEY || keycode == A_KEY || keycode == S_KEY
			|| keycode == D_KEY || keycode == R_KEY || keycode == T_KEY);
}

# define MOVE_SIZE 1

# define X_MOVE_SIZE MOVE_SIZE
# define Y_MOVE_SIZE MOVE_SIZE
# define Z_MOVE_SIZE MOVE_SIZE
static void	move_camera(int keycode, t_minirt *minirt)
{
	t_p3	*coord;

	if (minirt->scene->camera_mode == TRANSLATION )
		coord = &minirt->scene->cam->origin;
	else
		coord = &minirt->scene->cam->dir;
	if (keycode == D_KEY)
		coord->x += X_MOVE_SIZE;
	else if (keycode == A_KEY)
		coord->x -= X_MOVE_SIZE;
	else if (keycode == W_KEY)
		coord->y += Y_MOVE_SIZE;
	else if (keycode == S_KEY)
		coord->y -= Y_MOVE_SIZE;
	else if (keycode == R_KEY)
		coord->z += Z_MOVE_SIZE;
	else if (keycode == T_KEY)
		coord->z -= Z_MOVE_SIZE;
	update_window(minirt);
}

int	cameras_event(int keycode, t_minirt *minirt)
{
	if ((keycode == Q_KEY || keycode == E_KEY) && minirt->scene->cam->next)
		switch_camera(keycode, minirt);
	if (keycode == CAPS_KEY)
		minirt->scene->camera_mode = !minirt->scene->camera_mode;
	if (is_movement_keycode(keycode))
		move_camera(keycode, minirt);
	return (1);
}
