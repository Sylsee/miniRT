/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_properties.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 23:27:36 by arguilla          #+#    #+#             */
/*   Updated: 2022/01/15 23:33:39 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	update_sphere_properties(int keycode, t_minirt *minirt)
{
	t_lst	*obj;

	obj = minirt->scene->obj;
	if (keycode == K_KEY)
		((t_sphere *)obj->object)->diameter += SPHERE_DIAMETER_SIZE;
	else if (keycode == J_KEY)
		((t_sphere *)obj->object)->diameter -= SPHERE_DIAMETER_SIZE;
	update_window(minirt);
}

void	update_cylinder_properties(int keycode, t_minirt *minirt)
{
	t_lst	*obj;

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

void	update_object_properties(int keycode, t_minirt *minirt)
{
	t_lst	*obj;

	obj = minirt->scene->obj;
	if (obj->id == SPHERE)
		update_sphere_properties(keycode, minirt);
	else if (obj->id == CYLINDER)
		update_cylinder_properties(keycode, minirt);
}

bool	is_object_properties_keycode(int keycode)
{
	return (keycode == H_KEY || keycode == J_KEY || keycode == K_KEY
		|| keycode == L_KEY);
}
