/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 05:45:27 by arguilla          #+#    #+#             */
/*   Updated: 2022/03/21 16:38:31 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef THREAD_H
# define THREAD_H

# ifndef MAX_THREADS
#  define MAX_THREADS	20
# endif

typedef struct s_thread_data
{
	int				id;
	pthread_mutex_t	*id_mutex;
	t_scene			*scene;
	t_data			*data;
}	t_thread_data;

typedef struct s_routine_data
{
	t_scene	*scene;
	t_data	*data;
	int		id;
	int		start;
	int		end;
	int		range;
	int		x;
	int		color;
}	t_routine_data;

void	init_routine_data(t_routine_data *data, void *arg);
void	init_thread_data(t_thread_data *thread_data, t_scene *scene,
			t_data *data);
void	*routine(void *arg);
void	display_progress_bar(int end);

#endif
