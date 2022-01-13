/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 08:33:48 by arguilla          #+#    #+#             */
/*   Updated: 2022/01/13 23:33:48 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENT_H
# define EVENT_H

typedef struct s_minirt
{
	t_data	*data;
	t_scene	*scene;
}				t_minirt;

int		destroy_window(t_data *data);
int		exit_window(int keycode, t_data *data);
void	init_mlx_events(t_minirt *minirt);
int		mouse_hook(int mouse_code, int x, int y, t_minirt *minirt);

#endif
