/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_elem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 19:49:20 by spoliart          #+#    #+#             */
/*   Updated: 2022/01/05 22:20:28 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_resolution(t_scene *scene, char **line)
{
	scene->res.x = ft_atoi(line[1]);
	if (scene->res.x > 1080)
		scene->res.x = 1080;
	else if (scene->res.x < 10)
		scene->res.x = 10;
	scene->res.y = ft_atoi(line[2]);
	if (scene->res.y > 720)
		scene->res.y = 720;
	else if (scene->res.y < 10)
		scene->res.y = 10;
}

void	parse_ambient(t_scene *scene, char **line)
{
	scene->ambient.ratio = ft_atof(line[1]);
	if (scene->ambient.ratio < 0 || scene->ambient.ratio > 1)
		internal_error("Ratio must be a number beetween 0 and 1");
	scene->ambient.color = parse_color(line[2], line[3], line[4]);
}

void	parse_camera(t_scene *scene, char **line)
{
	t_cam	*cam;

	cam = alloc(sizeof(t_cam), NULL);
	if (!cam)
		internal_error("unable to allocate memory");
	cam->origin = parse_coord(line[1], line[2], line[3]);
	cam->orientation = parse_coord(line[4], line[5], line[6]);
	if (check_orientation(cam->orientation))
		internal_error("Camera orientation must be a number beetween -1 and 1");
	cam->fov = ft_atof(line[7]);
	ft_lstadd_front(&(scene->cam), ft_lstnew(cam));
}

void	parse_light(t_scene *scene, char **line)
{
	t_light	*light;

	light = alloc(sizeof(t_light), NULL);
	if (!light)
		internal_error("unable to allocate memory");
	light->pos = parse_coord(line[1], line[2], line[3]);
	light->ratio = ft_atof(line[4]);
	if (scene->ambient.ratio < 0 || scene->ambient.ratio > 1)
		internal_error("Ratio must be a number beetween 0 and 1");
	light->color = parse_color(line[5], line[6], line[7]);
	ft_lstadd_front(&(scene->light), ft_lstnew(light));
}
