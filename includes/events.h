/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 08:33:48 by arguilla          #+#    #+#             */
/*   Updated: 2022/01/11 09:01:35 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

int		destroy_window(t_data *data);
int		exit_window(int keycode, t_data *data);
void	init_mlx_events(t_data *data);

#endif
