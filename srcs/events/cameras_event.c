/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cameras_event.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 17:52:24 by arguilla          #+#    #+#             */
/*   Updated: 2022/02/05 22:33:06 by spoliart         ###   ########.fr       */
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

static void	init_rotation(int keycode, t_cam *cam, int *coef, t_p3 *tmp)
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
	int		coef;
	t_p3	tmp;
	t_cam	*cam;

	coef = 0.5;
	cam = minirt->scene->cam;
	init_rotation(keycode, cam, &coef, &tmp);
	tmp = v_scale(tmp, coef * 0.1);
	cam->look_at = v_add(cam->look_at, tmp);
	normalize(&cam->look_at);
	param_cam(cam, minirt->scene->res);
	if (minirt->scene->cam->v_up.x == 0
		&& minirt->scene->cam->v_up.y != 0 && minirt->scene->cam->v_up.z == 0)
		minirt->scene->cam->v_up.x = 0.000000001;
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
	else if (is_movement_keycode(keycode))
		rotate_camera(keycode, minirt);
}
