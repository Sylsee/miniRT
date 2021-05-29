/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 18:13:36 by spoliart          #+#    #+#             */
/*   Updated: 2021/05/29 18:46:40 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	quit_program(t_minirt *minirt)
{
	ft_lstclear(minirt->scene->light, free);
	free(minirt->scene->light);
	ft_lstclear(minirt->scene->cam, free);
	free(minirt->scene->cam);
	ft_lstclear(minirt->scene->obj, free);
	free(minirt->scene->obj);
	free(minirt->scene);
	mlx_destroy_image(minirt->mlx, minirt->img);
	mlx_destroy_window(minirt->mlx, minirt->win);
	free(minirt);
	exit(0);
}
