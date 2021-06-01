/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_elem2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 19:53:58 by spoliart          #+#    #+#             */
/*   Updated: 2021/05/30 13:29:25 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_sphere(t_scene *scene, char **data)
{
	t_sphere	*sphere;

	if (!(sphere = malloc(sizeof(sphere))))
		print_err_and_exit("Malloc error");
	sphere->pos = parse_coord(data[1], data[2], data[3]);
	sphere->diameter = ft_atof(data[4]);
	sphere->color = parse_color(data[5], data[6], data[7]);
	ft_lstadd_front_rt(&(scene->obj), ft_lstnew_rt(sphere, SPHERE));
}

void	parse_plane(t_scene *scene, char **data)
{
	t_plane	*plane;

	if (!(plane = malloc(sizeof(plane))))
		print_err_and_exit("Malloc error");
	plane->pos = parse_coord(data[1], data[2], data[3]);
	plane->orientation = parse_coord(data[4], data[5], data[6]);
	if (!(check_orientation(plane->orientation)))
		print_err_and_exit("Orientation must be a number beetween -1 and 1");
	plane->color = parse_color(data[7], data[8], data[9]);
	ft_lstadd_front_rt(&(scene->obj), ft_lstnew_rt(plane, PLANE));
}

void	parse_square(t_scene *scene, char **data)
{
	t_square	*square;

	if (!(square = malloc(sizeof(square))))
		print_err_and_exit("Malloc error");
	square->pos = parse_coord(data[1], data[2], data[3]);
	square->orientation = parse_coord(data[4], data[5], data[6]);
	if (!(check_orientation(square->orientation)))
		print_err_and_exit("Orientation must be a number beetween -1 and 1");
	square->size = ft_atof(data[7]);
	square->color = parse_color(data[8], data[9], data[10]);
	ft_lstadd_front_rt(&(scene->obj), ft_lstnew_rt(square, SQUARE));
}

void	parse_cylinder(t_scene *scene, char **data)
{
	t_cylinder	*cylinder;

	if (!(cylinder = malloc(sizeof(cylinder))))
		print_err_and_exit("Malloc error");
	cylinder->pos = parse_coord(data[1], data[2], data[3]);
	cylinder->orientation = parse_coord(data[4], data[5], data[6]);
	if (!(check_orientation(cylinder->orientation)))
		print_err_and_exit("Orientation must be a number beetween -1 and 1");
	cylinder->diameter = ft_atof(data[7]);
	cylinder->height = ft_atof(data[8]);
	cylinder->color = parse_color(data[9], data[10], data[11]);
	ft_lstadd_front_rt(&(scene->obj), ft_lstnew_rt(cylinder, CYLINDER));
}

void	parse_triangle(t_scene *scene, char **data)
{
	t_triangle	*triangle;

	if (!(triangle = malloc(sizeof(triangle))))
		print_err_and_exit("Malloc error");
	triangle->first = parse_coord(data[1], data[2], data[3]);
	triangle->second = parse_coord(data[4], data[5], data[6]);
	triangle->third = parse_coord(data[7], data[8], data[9]);
	triangle->color = parse_color(data[10], data[11], data[12]);
	ft_lstadd_front_rt(&(scene->obj), ft_lstnew_rt(triangle, TRIANGLE));
}
