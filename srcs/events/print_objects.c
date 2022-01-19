/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 21:35:34 by arguilla          #+#    #+#             */
/*   Updated: 2022/01/18 22:06:24 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	print_sphere(t_sphere *sphere)
{
	printf(GREEN"\t%s"RESET"%s\n", "type: ", "sphere");
	printf(GREEN"\t%s"RESET"%f\n", "Diameter: ", sphere->diameter);
	print_p3(sphere->pos, "Origin:");
}

void	print_plane(t_plane *plane)
{
	printf(GREEN"\t%s"RESET"%s\n", "type: ", "plane");
	print_p3(plane->pos, "Origin:");
	print_p3(plane->dir, "Direction:");
}

void	print_square(t_square *square)
{
	printf(GREEN"\t%s"RESET"%s\n", "type: ", "square");
	printf(GREEN"\t%s"RESET"%f\n", "Size: ", square->size);
	print_p3(square->pos, "Origin:");
	print_p3(square->dir, "Direction:");
}

void	print_cylinder(t_cylinder *cylinder)
{
	printf(GREEN"\t%s"RESET"%s\n", "type: ", "cylinder");
	printf(GREEN"\t%s"RESET"%f\n", "Diameter: ", cylinder->diameter);
	printf(GREEN"\t%s"RESET"%f\n", "Height: ", cylinder->height);
	print_p3(cylinder->pos, "Origin:");
	print_p3(cylinder->dir, "Direction:");
}

void	print_triangle(t_triangle *triangle)
{
	printf(GREEN"\t%s"RESET"%s\n", "type: ", "triangle");
	print_p3(triangle->first, "First:");
	print_p3(triangle->second, "Second:");
	print_p3(triangle->third, "Third:");
}
