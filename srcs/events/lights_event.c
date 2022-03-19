/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 16:56:59 by arguilla          #+#    #+#             */
/*   Updated: 2022/01/18 22:13:34 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	switch_light(t_minirt *minirt)
{
	if (minirt->scene->current_light->next == NULL
		&& minirt->scene->current_light == minirt->scene->light)
		return ;
	if (minirt->scene->current_light->next == NULL)
		minirt->scene->current_light = minirt->scene->light;
	else
		minirt->scene->current_light = minirt->scene->current_light->next;
	print_status(minirt);
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
	else if (keycode == SPACE_KEY)
		coord->y += Y_MOVE_LIGHT;
	else if (keycode == SHIFT_KEY)
		coord->y -= Y_MOVE_LIGHT;
	else if (keycode == W_KEY)
		coord->z += Z_MOVE_LIGHT;
	else if (keycode == S_KEY)
		coord->z -= Z_MOVE_LIGHT;
	update_window(minirt);
}

void	lights_event(int keycode, t_minirt *minirt)
{
	if ((keycode == Q_KEY || keycode == E_KEY)
		&& minirt->scene->current_light)
		switch_light(minirt);
	else if (is_movement_keycode(keycode))
		move_light(keycode, minirt);
}
