/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_properties.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 23:27:36 by arguilla          #+#    #+#             */
/*   Updated: 2022/03/19 21:46:26 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	update_sphere_properties(int keycode, t_minirt *minirt, t_sphere *s)
{
	if (keycode == K_KEY)
	{
		s->diameter += SPHERE_DIAMETER_SIZE;
		update_window(minirt);
	}
	else if (keycode == J_KEY)
	{
		if (s->diameter > SPHERE_DIAMETER_SIZE)
			s->diameter -= SPHERE_DIAMETER_SIZE;
		else
			return ;
		update_window(minirt);
	}
}

void	update_cylinder_properties(int keycode, t_minirt *minirt, t_cylinder *c)
{
	if (keycode == K_KEY)
		c->diameter += CYLINDER_WIDTH_SIZE;
	else if (keycode == J_KEY)
	{
		if (c->diameter > CYLINDER_WIDTH_SIZE)
			c->diameter -= CYLINDER_WIDTH_SIZE;
		else
			return ;
	}
	else if (keycode == L_KEY)
		c->height += CYLINDER_HEIGHT_SIZE;
	else if (keycode == H_KEY)
	{
		if (c->height > CYLINDER_HEIGHT_SIZE)
			c->height -= CYLINDER_HEIGHT_SIZE;
		else
			return ;
	}
	update_window(minirt);
}

void	update_object_properties(int keycode, t_minirt *minirt)
{
	if (minirt->scene->id_current_obj == SPHERE)
		update_sphere_properties(keycode, minirt, minirt->scene->current_obj);
	else if (minirt->scene->id_current_obj == CYLINDER)
		update_cylinder_properties(keycode, minirt, minirt->scene->current_obj);
}

bool	is_object_properties_keycode(int keycode)
{
	return (keycode == H_KEY || keycode == J_KEY || keycode == K_KEY
		|| keycode == L_KEY);
}
