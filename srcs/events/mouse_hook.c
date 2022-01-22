/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 16:14:53 by spoliart          #+#    #+#             */
/*   Updated: 2022/01/14 00:44:08 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

#define RIGHT_CLICK 1
#define LEFT_CLICK 3
#define ROLL_UP 4
#define ROLL_DOWN 5

static void	manage_cylinder(t_cylinder *cy, int mouse_code)
{
	if (mouse_code == RIGHT_CLICK)
		cy->diameter += cy->diameter * 0.1;
	else if (mouse_code == LEFT_CLICK)
		cy->diameter -= cy->diameter * 0.1;
	else if (mouse_code == ROLL_UP)
		cy->height += cy->height * 0.1;
	else if (mouse_code == ROLL_DOWN)
		cy->height -= cy->height * 0.1;
}

static void	manage_sphere(t_sphere *s, int mouse_code)
{
	if (mouse_code == RIGHT_CLICK)
		s->diameter += s->diameter * 0.1;
	else
		s->diameter -= s->diameter * 0.1;
}

static int	select_object(int x, int y, t_scene *scene)
{
	t_vector	ray;
	t_hit		hit;

	ray = new_ray(scene->cam, *scene, x, y);
	hit = intersection(*scene, ray, 2);
	if (hit.dist == -1)
		return (0);
	scene->id_current_obj = hit.type;
	scene->current_obj = hit.object;
	return (1);
}

int	mouse_hook(int mouse_code, int x, int y, t_minirt *minirt)
{
	if (mouse_code == RIGHT_CLICK || mouse_code == LEFT_CLICK)
	{
		if (select_object(x, y, minirt->scene) != 0
			&& minirt->scene->id_current_obj != PLANE)
		{
			if (minirt->scene->id_current_obj == SPHERE)
				manage_sphere(minirt->scene->current_obj, mouse_code);
			else if (minirt->scene->id_current_obj == CYLINDER)
				manage_cylinder(minirt->scene->current_obj, mouse_code);
			update_window(minirt);
		}
	}
	return (0);
}
