/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_elem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 19:49:20 by spoliart          #+#    #+#             */
/*   Updated: 2022/03/04 15:41:04 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_resolution(t_scene *scene, char **line)
{
	if (ft_tablen(line) != 3)
		internal_error("File format error");
	scene->res.x = ft_atoi(line[1]);
	if (scene->res.x < 10)
		scene->res.x = 10;
	scene->res.y = ft_atoi(line[2]);
	if (scene->res.y < 10)
		scene->res.y = 10;
}

void	parse_ambient(t_scene *scene, char **line)
{
	if (ft_tablen(line) != 5)
		internal_error("File format error");
	scene->ambient.ratio = ft_atof(line[1]);
	if (scene->ambient.ratio < 0 || scene->ambient.ratio > 1)
		internal_error("Ratio must be a number between 0 and 1");
	scene->ambient.color = parse_color(line[2], line[3], line[4]);
}

void	parse_camera(t_scene *scene, char **line)
{
	t_cam	*cam;

	if (ft_tablen(line) != 8)
		internal_error("File format error");
	cam = alloc(sizeof(t_cam), NULL);
	if (!cam)
		internal_error("unable to allocate memory");
	cam->origin = parse_point(line[1], line[2], line[3]);
	cam->look_at = parse_point(line[4], line[5], line[6]);
	if (check_orientation(cam->look_at))
		internal_error("Camera orientation must be a number between -1 and 1");
	if (cam->look_at.x == 0 && cam->look_at.y != 0 && cam->look_at.z == 0)
		cam->look_at.x = 0.000000001;
	if (get_norm(cam->look_at) == 0)
		internal_error("Camera orientation canno't be null");
	cam->fov = ft_atof(line[7]);
	cam->fov = tan(cam->fov * M_PI / 180);
	cam->v_up.x = 0;
	cam->v_up.y = -1;
	cam->v_up.z = 0;
	param_cam(cam, scene->res);
	cam_lstadd_back(&(scene->cam), cam);
}

void	parse_light(t_scene *scene, char **line)
{
	t_light	*light;

	if (ft_tablen(line) != 8)
		internal_error("File format error");
	light = alloc(sizeof(t_light), NULL);
	if (!light)
		internal_error("unable to allocate memory");
	light->pos = parse_point(line[1], line[2], line[3]);
	light->ratio = ft_atof(line[4]);
	if (scene->ambient.ratio < 0 || scene->ambient.ratio > 1)
		internal_error("Ratio must be a number between 0 and 1");
	light->color = parse_color(line[5], line[6], line[7]);
	ft_lstadd_front(&(scene->light), ft_lstnew(light));
}
