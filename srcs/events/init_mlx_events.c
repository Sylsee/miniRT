/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx_events.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 09:00:59 by arguilla          #+#    #+#             */
/*   Updated: 2022/01/14 00:41:35 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	init_mlx_events(t_minirt *minirt)
{
	mlx_mouse_hook(minirt->data->win, &mouse_hook, minirt);
	mlx_hook(minirt->data->win, 33, 0, &destroy_window, minirt->data);
	mlx_key_hook(minirt->data->win, &exit_window, minirt->data);
}
