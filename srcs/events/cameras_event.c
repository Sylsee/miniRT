/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cameras_event.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 17:52:24 by arguilla          #+#    #+#             */
/*   Updated: 2022/03/20 07:10:38 by arguilla         ###   ########.fr       */
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

static void	init_rotation(int keycode, t_cam *cam, double *coef, t_p3 *tmp)
{
	if (keycode == D_KEY)
		*tmp = cam->horizontal;
	else if (keycode == A_KEY)
	{
		*tmp = cam->horizontal;
		*coef *= -1;
	}
	else if (keycode == S_KEY)
		*tmp = cam->vertical;
	else if (keycode == W_KEY)
	{
		*tmp = cam->vertical;
		*coef *= -1;
	}
}

static void	rotate_camera(int keycode, t_minirt *minirt)
{
	t_p3	tmp;
	t_cam	*cam;
	double	coef;

	coef = 0.03;
	cam = minirt->scene->cam;
	init_rotation(keycode, cam, &coef, &tmp);
	tmp = v_scale(tmp, coef);
	cam->look_at = v_add(cam->look_at, tmp);
	normalize(&cam->look_at);
	param_cam(cam, minirt->scene->res);
	if (minirt->scene->cam->v_up.x == 0
		&& minirt->scene->cam->v_up.y != 0 && minirt->scene->cam->v_up.z == 0)
		minirt->scene->cam->v_up.x = 0.000000001;
	update_window(minirt);
}

static void	translate_camera(int keycode, t_minirt *minirt, t_cam *cam)
{
	if (keycode == D_KEY)
		cam->origin.x += MOVE_SIZE;
	else if (keycode == A_KEY)
		cam->origin.x -= MOVE_SIZE;
	else if (keycode == SPACE_KEY)
		cam->origin.y += MOVE_SIZE;
	else if (keycode == SHIFT_KEY)
		cam->origin.y -= MOVE_SIZE;
	else if (keycode == W_KEY)
		cam->origin.z += MOVE_SIZE;
	else if (keycode == S_KEY)
		cam->origin.z -= MOVE_SIZE;
	param_cam(cam, minirt->scene->res);
	update_window(minirt);
}

void	cameras_event(int keycode, t_minirt *minirt)
{
	if ((keycode == Q_KEY || keycode == E_KEY) && minirt->scene->cam->next)
		switch_camera(keycode, minirt);
	else if (keycode == CAPS_KEY)
	{
		minirt->scene->camera_mode = !minirt->scene->camera_mode;
		print_status(minirt);
	}
	if (is_movement_keycode(keycode))
	{
		if (!minirt->scene->camera_mode && keycode != SPACE_KEY
			&& keycode != SHIFT_KEY)
			rotate_camera(keycode, minirt);
		else
			translate_camera(keycode, minirt, minirt->scene->cam);
	}
}
