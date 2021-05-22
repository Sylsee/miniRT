/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_elem2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 19:53:58 by spoliart          #+#    #+#             */
/*   Updated: 2021/05/22 20:12:14 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_plane(t_scene *scene, char **data)
{
	t_plane	*plane;

	if (!(plane = (t_plane *)malloc(sizeof(plane))))
		print_err_and_exit("Malloc error");
	plane->id = PLANE;
	plane->pos = parse_coord(data[1], data[2], data[3]);
	plane->orientation = parse_coord(data[4], data[5], data[6]);
	if (!(check_orientation(plane->orientation)))
		print_err_and_exit("Orientation must be a number beetween -1 and 1");
	plane->color = parse_color(data[7], data[8], data[9]);
	ft_lstadd_front(&(scene->obj), ft_lstnew(plane));
}

void	parse_square(t_scene *scene, char **data)
{
	t_square	*square;

	if (!(square = (t_square *)malloc(sizeof(square))))
		print_err_and_exit("Malloc error");
	square->id = SQUARE;
	square->pos = parse_coord(data[1], data[2], data[3]);
	square->orientation = parse_coord(data[4], data[5], data[6]);
	if (!(check_orientation(square->orientation)))
		print_err_and_exit("Orientation must be a number beetween -1 and 1");
	square->size = ft_atof(data[7]);
	square->color = parse_color(data[8], data[9], data[10]);
	ft_lstadd_front(&(scene->obj), ft_lstnew(square));
}

void	parse_cylinder(t_scene *scene, char **data)
{
	t_cylinder	*cylinder;

	if (!(cylinder = (t_cylinder *)malloc(sizeof(cylinder))))
		print_err_and_exit("Malloc error");
	cylinder->id = CYLINDER;
	cylinder->pos = parse_coord(data[1], data[2], data[3]);
	cylinder->orientation = parse_coord(data[4], data[5], data[6]);
	if (!(check_orientation(cylinder->orientation)))
		print_err_and_exit("Orientation must be a number beetween -1 and 1");
	cylinder->diameter = ft_atof(data[7]);
	cylinder->height = ft_atof(data[8]);
	cylinder->color = parse_color(data[9], data[10], data[11]);
	ft_lstadd_front(&(scene->obj), ft_lstnew(cylinder));
}

void	parse_triangle(t_scene *scene, char **data)
{
	t_triangle	*triangle;

	if (!(triangle = (t_triangle *)malloc(sizeof(triangle))))
		print_err_and_exit("Malloc error");
	triangle->id = TRIANGLE;
	triangle->first = parse_coord(data[1], data[2], data[3]);
	triangle->second = parse_coord(data[4], data[5], data[6]);
	triangle->third = parse_coord(data[7], data[8], data[9]);
	triangle->color = parse_color(data[10], data[11], data[12]);
	ft_lstadd_front(&(scene->obj), ft_lstnew(triangle));
}
