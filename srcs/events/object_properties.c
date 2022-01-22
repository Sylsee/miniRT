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
	if (keycode == K_KEY)
		((t_sphere *)minirt->scene->current_obj)->diameter += SPHERE_DIAMETER_SIZE;
	else if (keycode == J_KEY)
		((t_sphere *)minirt->scene->current_obj)->diameter -= SPHERE_DIAMETER_SIZE;
	update_window(minirt);
}

void	update_cylinder_properties(int keycode, t_minirt *minirt)
{
	if (keycode == K_KEY)
		((t_cylinder *)minirt->scene->current_obj)->diameter += CYLINDER_WIDTH_SIZE;
	else if (keycode == J_KEY)
		((t_cylinder *)minirt->scene->current_obj)->diameter -= CYLINDER_WIDTH_SIZE;
	else if (keycode == L_KEY)
		((t_cylinder *)minirt->scene->current_obj)->height += CYLINDER_HEIGHT_SIZE;
	else if (keycode == H_KEY)
		((t_cylinder *)minirt->scene->current_obj)->height -= CYLINDER_HEIGHT_SIZE;
	update_window(minirt);
}

void	update_object_properties(int keycode, t_minirt *minirt)
{
	if (minirt->scene->id_current_obj == SPHERE)
		update_sphere_properties(keycode, minirt);
	else if (minirt->scene->id_current_obj == CYLINDER)
		update_cylinder_properties(keycode, minirt);
}

bool	is_object_properties_keycode(int keycode)
{
	return (keycode == H_KEY || keycode == J_KEY || keycode == K_KEY
		|| keycode == L_KEY);
}
