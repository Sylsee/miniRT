/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx_events.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 09:00:59 by arguilla          #+#    #+#             */
/*   Updated: 2022/01/12 20:11:02 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	init_mlx_events(t_minirt *minirt)
{
	mlx_hook(minirt->data->win, 33, 0, &destroy_window, minirt->data);
	mlx_key_hook(minirt->data->win, &cameras_event, minirt);
}
