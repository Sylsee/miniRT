/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 22:25:02 by spoliart          #+#    #+#             */
/*   Updated: 2022/03/06 11:41:54 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
**	Calculate the closest intersection point between a vector and all objects
**
**	@param	objects	=>	Chained list contains all the objects 
**	@param	ray		=>	Structure contains the ray vector
**	@param	mode	=>	Mode to check what the user needs
**
**	return the hit structure contains all informations needed to compute the color
*/

t_hit	intersection(t_object_list *objects, t_vector ray, int mode)
{
	bool	has_inter;
	t_hit	t;
	t_hit	t_min;

	t_min.dist = -1;
	while (objects)
	{
		has_inter = false;
		if (objects->id == SPHERE)
			has_inter = inter_sphere(objects->object, ray, &t, mode);
		else if (objects->id == PLANE)
			has_inter = inter_plane(objects->object, ray, &t, mode);
		else if (objects->id == CYLINDER)
			has_inter = inter_cylinder(objects->object, ray, &t, mode);
		if (has_inter == true && (t_min.dist == -1 || t.dist < t_min.dist))
			t_min = t;
		objects = objects->next;
	}
	return (t_min);
}

/*
**	Recovers the color depending on where you look
**
**	@param	scene		=>	Structure contains all informations about the actual scene
**	@param	ray			=>	The vector where you look
**	@param	nb_rebound	=>	The max bounces autorized for reflection
**
**	return the computed color
*/

t_color	get_color(t_scene scene, t_vector ray, int nb_rebound)
{
	t_hit	hit;
	t_color	color;
	t_color	reflect;

	if (nb_rebound <= 0)
		return (new_color(scene.bg_color));
	hit = intersection(scene.obj, ray, 1);
	if (hit.dist == -1)
		return (new_color(scene.bg_color));
	color = light(scene, hit);
	if (hit.material_type == REFLECTION || hit.material_type == REFRACTION)
		return (compute_material(scene, ray, hit, nb_rebound));
	if (hit.material_type == NONE && scene.do_reflection)
	{
		reflect = reflection(scene, ray, hit, nb_rebound);
		color.r = color.r * 0.93 + reflect.r * 0.07;
		color.g = color.g * 0.93 + reflect.g * 0.07;
		color.b = color.b * 0.93 + reflect.b * 0.07;
	}
	return (color);
}

/*
**	Anti-aliasing compute the color of a pixel by tracing multiple ray and take
**	the average of it.
**	It makes the image smoother and more beautiful but it takes times
**
**	@param	scene	=>	The structure contains all the actual scene informations
**	@param	x		=>	The x position of the pixel to compute
**	@param	y		=>	The y position of the pixel to compute
**
**	return the color
*/

int	anti_aliasing(t_scene scene, double x, double y)
{
	int			i;
	int			j;
	t_color		color;
	t_color		tmp_color;
	t_vector	ray;

	i = -1;
	color = new_color(0);
	while (++i < scene.antialiasing)
	{
		j = -1;
		while (++j < scene.antialiasing)
		{
			ray = new_ray(scene.cam, scene, x + (double)i / scene.antialiasing,
					y + (double)j / scene.antialiasing);
			tmp_color = get_color(scene, ray, scene.ray_max_bounces);
			color.r += tmp_color.r;
			color.g += tmp_color.g;
			color.b += tmp_color.b;
		}
	}
	color.r /= scene.antialiasing * scene.antialiasing;
	color.g /= scene.antialiasing * scene.antialiasing;
	color.b /= scene.antialiasing * scene.antialiasing;
	return (create_rgb((int)color.r, (int)color.g, (int)color.b));
}

/*
**	Fills the image on raytracing system:
**	the main principe is to trace a ray for each pixels starting on where
**	the camera is and determine if there is an object intersection.
**
**	@param	data	=>	Structure contains the image to fill
**	@param	scene	=>	Structure contains all informations bout the actual scene
*/

void	create_img(t_data *data, t_scene scene)
{
	int			x;
	int			y;
	int			color;

	y = 0;
	printf("\n");
	while (y < scene.res.y)
	{
		printf("\r  |%.*s%.*s| %.2f%%", y * 53 / scene.res.y, PROGRESS_FULL,
			53 - y * 53 / scene.res.y, PROGRESS_EMPTY,
			(double)y * 100 / scene.res.y);
		fflush(stdout);
		x = 0;
		while (x < scene.res.x)
		{
			color = anti_aliasing(scene, (double)x, (double)y);
			put_color(data, x, y, color);
			x++;
		}
		y++;
	}
	printf("\r  |%s| 100.00%%\n\n", PROGRESS_FULL);
}
