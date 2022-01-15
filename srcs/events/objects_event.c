/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects_event.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 20:42:14 by arguilla          #+#    #+#             */
/*   Updated: 2022/01/15 23:24:10 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	get_object_dir(t_p3 **coord, t_lst *obj)
{
	if (obj->id == PLANE)
		*coord = &((t_plane *)obj->object)->dir;
	else if (obj->id == SQUARE)
		*coord = &((t_square *)obj->object)->dir;
	else if (obj->id == CYLINDER)
		*coord = &((t_cylinder *)obj->object)->dir;
	else
		*coord = NULL;
}

static void	get_object_pos(t_p3 **coord, t_lst *obj)
{
	
	if (obj->id == SPHERE)
		*coord = &((t_sphere *)obj->object)->pos;
	else if (obj->id == PLANE)
		*coord = &((t_plane *)obj->object)->pos;
	else if (obj->id == SQUARE)
		*coord = &((t_square *)obj->object)->pos;
	else if (obj->id == CYLINDER)
		*coord = &((t_cylinder *)obj->object)->pos;
	else
		*coord = NULL;
}


static void	init_coord(t_p3 **coord, t_p3 *size, t_scene *scene)
{
	t_lst	*obj;

	obj = scene->obj;
	if (scene->object_mode == ROTATION && obj->id != SPHERE)
	{
		get_object_dir(coord, obj);
		size->x = X_ROTATION_SIZE;
		size->y = Y_ROTATION_SIZE;
		size->z = Z_ROTATION_SIZE;
	}
	else
	{
		get_object_pos(coord, obj);
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

static void	update_sphere_property(int keycode, t_minirt *minirt)
{
	t_lst *obj;

	obj = minirt->scene->obj;
	if (keycode == K_KEY)
		((t_sphere *)obj->object)->diameter += SPHERE_DIAMETER_SIZE;
	else if (keycode == J_KEY)
		((t_sphere *)obj->object)->diameter -= SPHERE_DIAMETER_SIZE;
	update_window(minirt);
}

static void	update_cylinder_property(int keycode, t_minirt *minirt)
{
	t_lst *obj;

	obj = minirt->scene->obj;
	if (keycode == K_KEY)
		((t_cylinder *)obj->object)->diameter += CYLINDER_WIDTH_SIZE;
	else if (keycode == J_KEY)
		((t_cylinder *)obj->object)->diameter -= CYLINDER_WIDTH_SIZE;
	else if (keycode == L_KEY)
		((t_cylinder *)obj->object)->height += CYLINDER_HEIGHT_SIZE;
	else if (keycode == H_KEY)
		((t_cylinder *)obj->object)->height -= CYLINDER_HEIGHT_SIZE;
	update_window(minirt);
}

static void	update_object_property(int keycode, t_minirt *minirt)
{
	t_lst	*obj;

	obj = minirt->scene->obj;
	if (obj->id == SPHERE)
		update_sphere_property(keycode, minirt);
	else if (obj->id == CYLINDER)
		update_cylinder_property(keycode, minirt);
}

static bool	is_object_property_keycode(int keycode)
{
	return (keycode == H_KEY || keycode == J_KEY || keycode == K_KEY
			|| keycode == L_KEY);
}

void	objects_event(int keycode, t_minirt *minirt)
{
	printf("%d\n", keycode);
	if (keycode == SHIFT_KEY)
		minirt->scene->object_mode = !minirt->scene->object_mode;
	else if (is_object_movement_keycode(keycode))
		move_object(keycode, minirt);
	else if (is_object_property_keycode(keycode))
	{printf("increase_");
	fflush(stdout);
		update_object_property(keycode, minirt);}
}
