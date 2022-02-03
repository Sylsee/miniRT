/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 23:42:46 by arguilla          #+#    #+#             */
/*   Updated: 2022/02/03 20:27:08 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	print_infos(t_scene scene)
{
	printf(BOLDCYAN"\t\t\t%s\n", "MINIRT STATUS ");
	printf(YELLOW"%s"RESET"%s\n", "Camera mode: ",
		return_string(scene.camera_mode, "translation", "rotation"));
	printf(YELLOW"%s"RESET"%s\n", "Object type: ",
		return_string(scene.object_type, "camera", "light"));
	printf(YELLOW"%s"RESET"%s\n", "Object mode: ",
		return_string(scene.object_mode, "translation", "rotation"));
}

static void	print_camera_infos(t_cam cam)
{
	printf(YELLOW"%s\n"RESET, "Camera property:");
	printf(GREEN"\t%s"RESET"%d\n", "Id: ", cam.id);
	print_p3(cam.origin, "Origin:");
	print_p3(cam.look_at, "Direction:");
}

static void	print_light_infos(t_list light)
{
	t_light	*content;

	content = ((t_light *)light.content);
	printf(YELLOW"%s\n"RESET, "Light property:");
	printf(GREEN"\t%s"RESET"%f\n", "Ratio: ", content->ratio);
	print_p3(content->pos, "Origin:");
}

static void	print_object_infos(int id, void *obj)
{
	printf(YELLOW"%s\n"RESET, "Object property:");
	if (id == SPHERE)
		print_sphere(obj);
	else if (id == PLANE)
		print_plane(obj);
	else if (id == SQUARE)
		print_square(obj);
	else if (id == CYLINDER)
		print_cylinder(obj);
	else if (id == TRIANGLE)
		print_triangle(obj);
}

void	print_status(t_minirt *minirt)
{
	print_infos(*minirt->scene);
	if (minirt->scene->cam)
		print_camera_infos(*minirt->scene->cam);
	if (minirt->scene->current_light)
		print_light_infos(*((t_list *)minirt->scene->current_light));
	if (minirt->scene->id_current_obj != -1)
		print_object_infos(minirt->scene->id_current_obj,
			minirt->scene->current_obj);
	printf("\n\n");
}
