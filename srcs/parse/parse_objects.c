/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 19:53:58 by spoliart          #+#    #+#             */
/*   Updated: 2022/01/12 22:29:04 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_sphere(t_scene *scene, char **line)
{
	t_sphere	*sphere;

	if (ft_tablen(line) != 8 && ft_tablen(line) != 9)
		internal_error("File format error");
	sphere = alloc(sizeof(t_sphere), NULL);
	if (!sphere)
		internal_error("unable to allocate memory");
	sphere->pos = parse_point(line[1], line[2], line[3]);
	sphere->diameter = ft_atof(line[4]);
	sphere->color = parse_color(line[5], line[6], line[7]);
	if (line[8])
		sphere->mirror = ft_atoi(line[8]);
	else
		sphere->mirror = false;
	lst_addfront(&(scene->obj), lstnew(sphere, SPHERE));
}

void	parse_plane(t_scene *scene, char **line)
{
	t_plane	*plane;

	if (ft_tablen(line) != 10 && ft_tablen(line) != 11)
		internal_error("File format error");
	plane = alloc(sizeof(t_plane), NULL);
	if (!plane)
		internal_error("unable to allocate memory");
	plane->pos = parse_point(line[1], line[2], line[3]);
	plane->dir = parse_point(line[4], line[5], line[6]);
	if (check_orientation(plane->dir))
		internal_error("Orientation must be a number beetween -1 and 1");
	plane->color = parse_color(line[7], line[8], line[9]);
	if (line[10])
		plane->mirror = ft_atoi(line[10]);
	else
		plane->mirror = false;
	lst_addfront(&(scene->obj), lstnew(plane, PLANE));
}

void	parse_square(t_scene *scene, char **line)
{
	t_square	*square;

	if (ft_tablen(line) != 10 && ft_tablen(line) != 11)
		internal_error("File format error");
	square = alloc(sizeof(t_square), NULL);
	if (!square)
		internal_error("unable to allocate memory");
	square->pos = parse_point(line[1], line[2], line[3]);
	square->dir = parse_point(line[4], line[5], line[6]);
	if (check_orientation(square->dir))
		internal_error("Orientation must be a number beetween -1 and 1");
	square->size = ft_atof(line[7]);
	square->color = parse_color(line[8], line[9], line[10]);
	if (line[11])
		square->mirror = ft_atoi(line[11]);
	else
		square->mirror = false;
	lst_addfront(&(scene->obj), lstnew(square, SQUARE));
}

void	parse_cylinder(t_scene *scene, char **line)
{
	t_cylinder	*cylinder;

	if (ft_tablen(line) != 11 && ft_tablen(line) != 12)
		internal_error("File format error");
	cylinder = alloc(sizeof(t_cylinder), NULL);
	if (!cylinder)
		internal_error("unable to allocate memory");
	cylinder->pos = parse_point(line[1], line[2], line[3]);
	cylinder->dir = parse_point(line[4], line[5], line[6]);
	if (check_orientation(cylinder->dir))
		internal_error("Orientation must be a number beetween -1 and 1");
	cylinder->diameter = ft_atof(line[7]);
	cylinder->height = ft_atof(line[8]);
	cylinder->color = parse_color(line[9], line[10], line[11]);
	if (line[12])
		cylinder->mirror = ft_atoi(line[12]);
	else
		cylinder->mirror = false;
	lst_addfront(&(scene->obj), lstnew(cylinder, CYLINDER));
}

void	parse_triangle(t_scene *scene, char **line)
{
	t_triangle	*triangle;

	if (ft_tablen(line) != 12 && ft_tablen(line) != 13)
		internal_error("File format error");
	triangle = alloc(sizeof(t_triangle), NULL);
	if (!triangle)
		internal_error("unable to allocate memory");
	triangle->first = parse_point(line[1], line[2], line[3]);
	triangle->second = parse_point(line[4], line[5], line[6]);
	triangle->third = parse_point(line[7], line[8], line[9]);
	triangle->color = parse_color(line[10], line[11], line[12]);
	if (line[13])
		triangle->mirror = ft_atoi(line[13]);
	else
		triangle->mirror = false;
	lst_addfront(&(scene->obj), lstnew(triangle, TRIANGLE));
}
