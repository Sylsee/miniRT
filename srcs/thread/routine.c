/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 05:51:12 by arguilla          #+#    #+#             */
/*   Updated: 2022/03/20 21:06:28 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	*routine(void *arg)
{
	t_routine_data	data;

	init_routine_data(&data, arg);
	while (data.start < data.end)
	{
		if (data.id == MAX_THREADS - 1)
			display_progress_bar(data.range);
		data.x = 0;
		while (data.x < data.scene->res.x)
		{
			data.color = anti_aliasing(*(data.scene), (double)data.x,
					(double)data.start);
			put_color(data.data, data.x, data.start, data.color);
			data.x++;
		}
		data.start++;
	}
	return (NULL);
}
