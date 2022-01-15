/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 08:33:48 by arguilla          #+#    #+#             */
/*   Updated: 2022/01/15 21:50:33 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

int		destroy_window(t_data *data);
int		exit_window(int keycode, t_data *data);
void	cameras_event(int keycode, t_minirt *minirt);
void	init_mlx_events(t_minirt *minirt);
void	update_window(t_minirt *minirt);
bool	is_movement_keycode(int keycode);
bool	is_object_movement_keycode(int keycode);
void	lights_event(int keycode, t_minirt *minirt);
void	objects_event(int keycode, t_minirt *minirt);

#endif
