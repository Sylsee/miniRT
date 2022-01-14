/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx_events.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 09:00:59 by arguilla          #+#    #+#             */
/*   Updated: 2022/01/14 13:03:41 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	key_events(int keycode, t_minirt *minirt)
{
	exit_window(keycode, minirt->data);
	cameras_event(keycode, minirt);
	return (1);
}

void	init_mlx_events(t_minirt *minirt)
{
	mlx_hook(minirt->data->win, 33, 0, &destroy_window, minirt->data);
	mlx_key_hook(minirt->data->win, &key_events, minirt);
}
