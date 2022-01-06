/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 23:40:13 by spoliart          #+#    #+#             */
/*   Updated: 2021/12/21 23:42:02 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	printplane(t_plane *plane)
{
	printf("pos.x: [%f]\n", plane->pos.x);
	printf("pos.y: [%f]\n", plane->pos.y);
	printf("pos.z: [%f]\n", plane->pos.z);
	printf("dir.x: [%f]\n", plane->dir.x);
	printf("dir.y: [%f]\n", plane->dir.y);
	printf("dir.z: [%f]\n", plane->dir.z);
	printf("color.r: [%f]\n", plane->color.r);
	printf("color.g: [%f]\n", plane->color.g);
	printf("color.b: [%f]\n", plane->color.b);
}

void	printcam(t_cam *cam)
{
	printf("origin.x: [%f]\n", cam->origin.x);
	printf("origin.y: [%f]\n", cam->origin.y);
	printf("origin.z: [%f]\n", cam->origin.z);
	printf("dir.x: [%f]\n", cam->dir.x);
	printf("dir.y: [%f]\n", cam->dir.y);
	printf("dir.z: [%f]\n", cam->dir.z);
	printf("fov: [%f]\n", cam->fov);
}

void	printsphere(t_sphere *sphere)
{
	printf("diameter: [%f]\n", sphere->diameter);
	printf("pos.x: [%f]\n", sphere->pos.x);
	printf("pos.y: [%f]\n", sphere->pos.y);
	printf("pos.z: [%f]\n", sphere->pos.z);
	printf("color.r: [%f]\n", sphere->color.r);
	printf("color.g: [%f]\n", sphere->color.g);
	printf("color.b: [%f]\n", sphere->color.b);
}

void	print_objects(t_data *data, t_scene *scene)
{
	t_lst	*tmp;

	tmp = scene->obj;
	while (tmp)
	{
		printf("\nobj.id: [%d]\n", tmp->id); fflush(stdout);
		if (tmp->id == PLANE)
			printplane(tmp->content);
		else if (tmp->id == SPHERE)
			printsphere(tmp->content);
		tmp = tmp->next;
	}
}
