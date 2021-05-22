/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_elem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 19:49:20 by spoliart          #+#    #+#             */
/*   Updated: 2021/05/22 22:02:32 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_resolution(t_scene *scene, char **data)
{
	scene->res.x = ft_atoi(data[1]);
	if (scene->res.x > 1080)
		scene->res.x = 1080;
	scene->res.y = ft_atoi(data[2]);
	if (scene->res.y > 720)
		scene->res.y = 720;
}

void	parse_ambient(t_scene *scene, char **data)
{
	scene->ambient.ratio = ft_atof(data[1]);
	if (scene->ambient.ratio < 0 || scene->ambient.ratio > 1)
		print_err_and_exit("Ratio must be a number beetween 0 and 1");
	scene->ambient.color = parse_color(data[2], data[3], data[4]);
}

void	parse_camera(t_scene *scene, char **data)
{
	t_cam	*cam;

	if (!(cam = (t_cam *)malloc(sizeof(cam))))
		print_err_and_exit("Malloc error");
	cam->vector.origin = parse_coord(data[1], data[2], data[3]);
	cam->vector.orientation = parse_coord(data[4], data[5], data[6]);
	if (!(check_orientation(cam->vector.orientation)))
		print_err_and_exit("Orientation must be a number beetween -1 and 1");
	cam->fov = ft_atof(data[7]);
	ft_lstadd_front(&(scene->cam), ft_lstnew(cam));
}

void	parse_light(t_scene *scene, char **data)
{
	t_light	*light;

	if (!(light = (t_light *)malloc(sizeof(light))))
		print_err_and_exit("Malloc error");
	light->pos = parse_coord(data[1], data[2], data[3]);
	light->ratio = ft_atof(data[4]);
	if (scene->ambient.ratio < 0 || scene->ambient.ratio > 1)
		print_err_and_exit("Ratio must be a number beetween 0 and 1");
	light->color = parse_color(data[5], data[6], data[7]);
	ft_lstadd_front(&(scene->light), ft_lstnew(light));
}
