/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects_event.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 20:42:14 by arguilla          #+#    #+#             */
/*   Updated: 2022/03/04 19:53:13 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	get_object_dir(t_p3 **coord, int id, void *obj)
{
	if (id == PLANE)
		*coord = &((t_plane *)obj)->dir;
	else if (id == CYLINDER)
		*coord = &((t_cylinder *)obj)->dir;
	else
		*coord = NULL;
}

static void	get_object_pos(t_p3 **coord, int id, void *obj)
{
	if (id == SPHERE)
		*coord = &((t_sphere *)obj)->pos;
	else if (id == PLANE)
		*coord = &((t_plane *)obj)->pos;
	else if (id == CYLINDER)
		*coord = &((t_cylinder *)obj)->pos;
	else
		*coord = NULL;
}

static void	init_coord(t_p3 **coord, t_p3 *size, t_scene *scene)
{
	if (scene->object_mode == ROTATION && scene->id_current_obj != SPHERE)
	{
		get_object_dir(coord, scene->id_current_obj, scene->current_obj);
		size->x = X_ROTATION_SIZE;
		size->y = Y_ROTATION_SIZE;
		size->z = Z_ROTATION_SIZE;
	}
	else
	{
		get_object_pos(coord, scene->id_current_obj, scene->current_obj);
		size->x = X_TRANSLATION_SIZE;
		size->y = Y_TRANSLATION_SIZE;
		size->z = Z_TRANSLATION_SIZE;
	}
}

static void	move_object(int keycode, t_minirt *minirt)
{
	t_p3	*coord;
	t_p3	size;

	init_coord(&coord, &size, minirt->scene);
	if (!coord)
		return ;
	if (keycode == RIGHT_KEY)
		coord->x += size.x;
	else if (keycode == LEFT_KEY)
		coord->x -= size.x;
	else if (keycode == UP_KEY)
		coord->y += size.y;
	else if (keycode == DOWN_KEY)
		coord->y -= size.y;
	else if (keycode == O_KEY)
		coord->z += size.z;
	else if (keycode == P_KEY)
		coord->z -= size.z;
	update_window(minirt);
}

void	objects_event(int keycode, t_minirt *minirt)
{
	if (keycode == SHIFT_KEY)
		minirt->scene->object_mode = !minirt->scene->object_mode;
	else if (is_object_movement_keycode(keycode))
		move_object(keycode, minirt);
	else if (is_object_properties_keycode(keycode))
		update_object_properties(keycode, minirt);
}
