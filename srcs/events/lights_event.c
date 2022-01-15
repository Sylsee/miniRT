/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 16:56:59 by arguilla          #+#    #+#             */
/*   Updated: 2022/01/15 22:37:38 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	switch_light(t_scene *scene)
{
	if (scene->current_light->next == NULL
		&& scene->current_light == scene->light)
		return ;
	if (scene->current_light->next == NULL)
		scene->current_light = scene->light;
	else
		scene->current_light = scene->current_light->next;
}

static void	move_light(int keycode, t_minirt *minirt)
{
	t_p3	*coord;
	t_light	*light;

	light = minirt->scene->current_light->content;
	coord = &light->pos;
	if (keycode == D_KEY)
		coord->x += X_MOVE_LIGHT;
	else if (keycode == A_KEY)
		coord->x -= X_MOVE_LIGHT;
	else if (keycode == W_KEY)
		coord->y += Y_MOVE_LIGHT;
	else if (keycode == S_KEY)
		coord->y -= Y_MOVE_LIGHT;
	else if (keycode == R_KEY)
		coord->z += Z_MOVE_LIGHT;
	else if (keycode == T_KEY)
		coord->z -= Z_MOVE_LIGHT;
	update_window(minirt);
}

void	lights_event(int keycode, t_minirt *minirt)
{
	if ((keycode == Q_KEY || keycode == E_KEY)
		&& minirt->scene->current_light)
		switch_light(minirt->scene);
	else if (is_movement_keycode(keycode))
		move_light(keycode, minirt);
}
