/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx_events.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 09:00:59 by arguilla          #+#    #+#             */
/*   Updated: 2022/01/13 21:38:39 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	init_mlx_events(t_data data, t_scene scene)
{
	t_minirt	minirt;

	minirt.data = &data;
	minirt.scene = &scene;
	printf("scene: [%p]\n", &scene);
	printf("minirt.scene: [%p]\n", minirt.scene);
	mlx_mouse_hook(data.win, &mouse_hook, &minirt);
	mlx_hook(data.win, 33, 0, &destroy_window, &data);
	mlx_key_hook(data.win, &exit_window, &data);
}
