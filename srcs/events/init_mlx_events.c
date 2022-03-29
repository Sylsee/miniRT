/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx_events.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <arguilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 09:00:59 by arguilla          #+#    #+#             */
/*   Updated: 2022/03/30 00:58:56 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	init_mlx_events(t_data *data, t_scene *scene)
{
	t_minirt	*minirt;

	minirt = alloc(sizeof(t_minirt), NULL);
	if (minirt == NULL)
		internal_error("unable to allocate memory");
	minirt->data = data;
	minirt->scene = scene;
	print_status(minirt);
	mlx_mouse_hook(data->win, &mouse_hook, minirt);
	mlx_hook(data->win, 33, 0, &exit_minirt, minirt);
	mlx_key_hook(minirt->data->win, &key_events, minirt);
}
