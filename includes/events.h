/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 08:33:48 by arguilla          #+#    #+#             */
/*   Updated: 2022/01/11 20:33:51 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

int		destroy_window(t_data *data);
int		exit_window(int keycode, t_data *data);
int		cameras_event(int keycode, t_minirt *minirt);
void	init_mlx_events(t_minirt *minirt);

#endif
