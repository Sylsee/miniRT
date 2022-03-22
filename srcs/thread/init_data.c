/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 05:44:33 by arguilla          #+#    #+#             */
/*   Updated: 2022/03/22 14:57:13 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	init_routine_data(t_routine_data *data, void *arg)
{
	t_thread_data	*thread_data;

	thread_data = (t_thread_data *)arg;
	pthread_mutex_lock(&thread_data->id_mutex);
	data->id = thread_data->id;
	thread_data->id++;
	pthread_mutex_unlock(&thread_data->id_mutex);
	data->scene = thread_data->scene;
	data->data = thread_data->data;
	data->start = (data->scene->res.y / MAX_THREADS) * data->id;
	data->end = data->start + (data->scene->res.y / MAX_THREADS);
	if (data->id == MAX_THREADS - 1)
		data->end += data->scene->res.y % MAX_THREADS;
	data->range = data->end - data->start;
	data->x = 0;
}

void	init_thread_data(t_thread_data *thread_data, t_scene *scene,
		t_data *data)
{
	thread_data->id = 0;
	thread_data->scene = scene;
	thread_data->data = data;
	if (pthread_mutex_init(&thread_data->id_mutex, NULL) != 0)
		internal_error("Mutex initialisation failed");
}
