/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cameras_event.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 17:52:24 by arguilla          #+#    #+#             */
/*   Updated: 2022/01/18 22:16:35 by arguilla         ###   ########.fr       */
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
// TODO si coord entre -1 et 1, si coord -1 < x > 0, bug, set a 0 par defaut	
	// si x et z = 1, decremente x a -1
	// une fois x a -1, decremente z a -1
	// donc x et z sont tout deux a -1, le dernier a avoir ete decremente est z donc on switch sur x pour l'incrementer
	// donc x deviendra 1 et z toujours -1
	// ensuite z on le decremente pour go a 1, une fois les deux a 1, z etant le dernier modif, on decremente x
	// on switch entre les deux
// SI z = -1.0 OU 1, ALORS decremente x  jusqu'a -1.0
    // SI x = -1, ALORS decremente z jusqu'a -1
	// SI x = 1, ALORS

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
//	normalize(coord);
	if (minirt->scene->cam->dir.x == 0
		&& minirt->scene->cam->dir.y != 0 && minirt->scene->cam->dir.z == 0)
		minirt->scene->cam->dir.x = 0.000000001;
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
		move_camera(keycode, minirt);
}
